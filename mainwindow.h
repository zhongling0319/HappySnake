#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <deque>
using namespace std;

#define STEP 20     //蛇身和食物的大小
#define BASE 1000
#define TO_UP 1
#define TO_DOWN 2
#define TO_LEFT 3
#define TO_RIGHT 4

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    void gameInit();
    ~MainWindow();
protected:
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *event);
private:
    Ui::MainWindow *ui;
    //食物位置
    int food;
    //速度
    int speed = 0;
    //蛇位置
    deque<int> snake;
    //行进方向
    int direction;
    //记录得分
    int score;
};

#endif // MAINWINDOW_H
