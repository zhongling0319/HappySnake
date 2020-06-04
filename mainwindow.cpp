#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gameover.h"
#include "ui_gameover.h"
#include <QtGlobal>
#include <QTime>
#include <QTimer>
#include <QString>
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QPainterPath>
#include <QColor>
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //游戏初始化
    gameInit();
    //设置定时器
    QTimer* timer = new QTimer(this);
    timer->stop();
    //关联速度控制
    connect(ui->horizontalSlider, &QSlider::valueChanged, ui->spinBox, &QSpinBox::setValue);
    void (QSpinBox:: *spsignal)(int) = &QSpinBox::valueChanged;
    connect(ui->spinBox, spsignal, ui->horizontalSlider, &QSlider::setValue);
    connect(ui->spinBox, spsignal, [=](){
        speed = ui->spinBox->value();
    });
    //关联开始和暂停按钮功能
    ui->pushButtonStart->setCheckable(true);
    connect(ui->pushButtonStart, &QPushButton::clicked, [=](bool flag){
        if (flag) {
            //timer->start((1000-9*speed)/3);
            timer->start(3000/(speed+1));
            ui->frame->setFocus();
            ui->pushButtonStart->setText("暂停");
        }
        else {
            timer->stop();
            ui->pushButtonStart->setText("开始");
        }
    });
    //关联重置按钮功能
    connect(ui->pushButtonReset, &QPushButton::clicked, [=](){
        timer->stop();
        gameInit();
        ui->pushButtonStart->setText("开始");
        ui->pushButtonStart->setChecked(false);
        update();
    });
    //得分框显示得分
    ui->labelScore->setText(QString::number(score));
    //关联游戏结束窗口
    GameOver* gameOverDialog = new GameOver;
    gameOverDialog->setWindowTitle("Game Over");
    connect(gameOverDialog->ui->pushButtonAgain, &QPushButton::clicked, [=](){
        gameInit();
        ui->pushButtonStart->setText("开始");
        ui->pushButtonStart->setChecked(false);
        gameOverDialog->close();
    });
    connect(gameOverDialog->ui->pushButtonExit, &QPushButton::clicked, [=](){
        gameOverDialog->close();
        this->close();
    });
    //关联定时器事件，游戏主体
    connect(timer, &QTimer::timeout, [=](){
        //蛇向前移动一格
        int snakeHeadX = snake.front()/BASE;
        int snakeHeadY = snake.front()%BASE;
        int snakeTail = snake.back();
        switch(direction) {
        case TO_UP: {
            snake.pop_back();
            snake.push_front(snakeHeadX*BASE + (snakeHeadY - STEP));
            break;
        }
        case TO_DOWN: {
            snake.pop_back();
            snake.push_front(snakeHeadX*BASE + (snakeHeadY + STEP));
            break;
        }
        case TO_LEFT: {
            snake.pop_back();
            snake.push_front((snakeHeadX - STEP)*BASE + snakeHeadY);
            break;
        }
        case TO_RIGHT: {
            snake.pop_back();
            snake.push_front((snakeHeadX + STEP)*BASE + snakeHeadY);
            break;
        }
        }
        //如果吃到了食物，更新食物位置，蛇尾加长一格
        if (snake.front() == food) {
            int foodX = ui->frame->x() + (qrand()%ui->frame->width())/STEP*STEP;
            int foodY = ui->frame->y() + (qrand()%ui->frame->height())/STEP*STEP;
            food = foodX*BASE + foodY;
            snake.push_back(snakeTail);
            score++;
        }
        //撞墙
        snakeHeadX = snake.front()/BASE;
        snakeHeadY = snake.front()%BASE;
        if (snakeHeadX < (ui->frame->x()) || snakeHeadX >= (ui->frame->x()+ui->frame->width())
                || snakeHeadY < (ui->frame->y()) || snakeHeadY >= (ui->frame->y()+ui->frame->height())) {
            timer->stop();
            gameOverDialog->show();
        }
        //蛇撞到自己
        for (int i = 2; i < snake.size(); i++) {
            if (snake.front() == snake[i]) {
                timer->stop();
                gameOverDialog->show();
            }
        }
        //显示当前分数
        ui->labelScore->setText(QString::number(score));
        //更新
        update();
    });
}

void MainWindow::gameInit()
{
    //初始化蛇位置
    snake.clear();
    snake.push_back((ui->frame->x() + 4*STEP)*BASE + ui->frame->y());
    snake.push_back((ui->frame->x() + 3*STEP)*BASE + ui->frame->y());
    snake.push_back((ui->frame->x() + 2*STEP)*BASE + ui->frame->y());
    snake.push_back((ui->frame->x() + 1*STEP)*BASE + ui->frame->y());
    //初始化食物位置
    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
    int foodX = ui->frame->x() + (qrand()%ui->frame->width())/STEP*STEP;
    int foodY = ui->frame->y() + (qrand()%ui->frame->height())/STEP*STEP;
    while (foodY == ui->frame->y()) {
        foodY = ui->frame->y() + (qrand()%ui->frame->height())/STEP*STEP;
    }   //防止第一次的随机食物在蛇身上
    food = foodX*BASE + foodY;
    //初始化得分
    score = 0;
    //初始化方向
    direction = TO_RIGHT;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QColor col = QColor(107,194,53);
    //设置画笔画刷
    QPen pen(col);
    pen.setWidth(STEP/2);
    pen.setStyle(Qt::DotLine);
    painter.setPen(pen);
    QBrush brush(col, Qt::SolidPattern);
    painter.setBrush(brush);
    //画食物
    QPainterPath foodPath;
    foodPath.addEllipse(food/BASE, food%BASE, STEP, STEP);
    painter.fillPath(foodPath, col);
    //画蛇
    QPainterPath snakePath;
    for (int s : snake) {
        snakePath.addEllipse(s/BASE, s%BASE, STEP, STEP);
    }
    painter.fillPath(snakePath, col);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if ((event->key() == Qt::Key_Up) && direction != TO_DOWN)   direction = TO_UP;
    if ((event->key() == Qt::Key_Down) && direction != TO_UP)   direction = TO_DOWN;
    if ((event->key() == Qt::Key_Left) && direction != TO_RIGHT)   direction = TO_LEFT;
    if ((event->key() == Qt::Key_Right) && direction != TO_LEFT)   direction = TO_RIGHT;
}

MainWindow::~MainWindow()
{
    delete ui;
}
