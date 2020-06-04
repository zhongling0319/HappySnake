/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButtonStart;
    QPushButton *pushButtonReset;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QSpinBox *spinBox;
    QSlider *horizontalSlider;
    QLabel *label_4;
    QLabel *labelScore;
    QFrame *frame;
    QWidget *widget_2;
    QLabel *label;
    QLabel *label_3;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setMinimumSize(QSize(800, 600));
        MainWindow->setMaximumSize(QSize(800, 600));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(580, 210, 211, 351));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        verticalLayout = new QVBoxLayout(widget_3);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButtonStart = new QPushButton(widget_3);
        pushButtonStart->setObjectName(QString::fromUtf8("pushButtonStart"));
        QFont font;
        font.setPointSize(16);
        pushButtonStart->setFont(font);

        verticalLayout->addWidget(pushButtonStart);

        pushButtonReset = new QPushButton(widget_3);
        pushButtonReset->setObjectName(QString::fromUtf8("pushButtonReset"));
        pushButtonReset->setFont(font);

        verticalLayout->addWidget(pushButtonReset);


        verticalLayout_2->addWidget(widget_3);

        widget_4 = new QWidget(widget);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout = new QHBoxLayout(widget_4);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(widget_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        horizontalLayout->addWidget(label_2);

        spinBox = new QSpinBox(widget_4);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setFont(font);

        horizontalLayout->addWidget(spinBox);


        verticalLayout_2->addWidget(widget_4);

        horizontalSlider = new QSlider(widget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setFont(font);
        horizontalSlider->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(horizontalSlider);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        verticalLayout_2->addWidget(label_4);

        labelScore = new QLabel(widget);
        labelScore->setObjectName(QString::fromUtf8("labelScore"));
        labelScore->setFont(font);
        labelScore->setFrameShape(QFrame::Panel);
        labelScore->setFrameShadow(QFrame::Sunken);
        labelScore->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(labelScore);

        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 10, 560, 560));
        frame->setAutoFillBackground(false);
        frame->setStyleSheet(QString::fromUtf8(""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Sunken);
        widget_2 = new QWidget(centralWidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(580, 20, 211, 171));
        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 50, 131, 111));
        label->setPixmap(QPixmap(QString::fromUtf8(":/new/label/image/snake.jpg")));
        label->setScaledContents(true);
        label_3 = new QLabel(widget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 0, 191, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\215\216\346\226\207\345\275\251\344\272\221"));
        font1.setPointSize(24);
        label_3->setFont(font1);
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
#if QT_CONFIG(statustip)
        pushButtonStart->setStatusTip(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213\346\270\270\346\210\217", nullptr));
#endif // QT_CONFIG(statustip)
        pushButtonStart->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213", nullptr));
#if QT_CONFIG(statustip)
        pushButtonReset->setStatusTip(QCoreApplication::translate("MainWindow", "\346\232\202\345\201\234\346\270\270\346\210\217", nullptr));
#endif // QT_CONFIG(statustip)
        pushButtonReset->setText(QCoreApplication::translate("MainWindow", "\351\207\215\347\275\256", nullptr));
#if QT_CONFIG(statustip)
        label_2->setStatusTip(QCoreApplication::translate("MainWindow", "\350\260\203\346\225\264\351\200\237\345\272\246", nullptr));
#endif // QT_CONFIG(statustip)
        label_2->setText(QCoreApplication::translate("MainWindow", "\351\200\237\345\272\246\357\274\232", nullptr));
#if QT_CONFIG(statustip)
        spinBox->setStatusTip(QCoreApplication::translate("MainWindow", "\350\260\203\346\225\264\351\200\237\345\272\246", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(statustip)
        horizontalSlider->setStatusTip(QCoreApplication::translate("MainWindow", "\350\260\203\346\225\264\351\200\237\345\272\246", nullptr));
#endif // QT_CONFIG(statustip)
        label_4->setText(QCoreApplication::translate("MainWindow", "\345\276\227\345\210\206\357\274\232", nullptr));
#if QT_CONFIG(statustip)
        labelScore->setStatusTip(QCoreApplication::translate("MainWindow", "\346\270\270\346\210\217\345\276\227\345\210\206", nullptr));
#endif // QT_CONFIG(statustip)
        labelScore->setText(QString());
        label->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "Happy Snake", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
