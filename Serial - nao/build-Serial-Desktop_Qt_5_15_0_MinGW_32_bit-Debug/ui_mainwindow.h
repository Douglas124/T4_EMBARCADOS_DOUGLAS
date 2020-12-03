/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QLabel *label_2;
    QLCDNumber *LCD_TEMP;
    QLCDNumber *LCD_UMI;
    QLCDNumber *LCD_PRESS;
    QLCDNumber *LCD_DISTANCIA;
    QSlider *SLIDER_SERVO1;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QSpinBox *SPIN_HORA_LIGA_M;
    QSpinBox *SPIN_MIN_LIGA_M;
    QSpinBox *SPIN_SEG_LIGA_M;
    QSpinBox *SPIN_HORA_DESLIGA_M;
    QSpinBox *SPIN_MIN_DESLIGA_M;
    QSpinBox *SPIN_SEG_DESLIGA_M;
    QSpinBox *SPIN_HORA_DESLIGA_R;
    QSpinBox *SPIN_SEG_DESLIGA_R;
    QSpinBox *SPIN_HORA_LIGA_R;
    QSpinBox *SPIN_MIN_LIGA_R;
    QSpinBox *SPIN_MIN_DESLIGA_R;
    QSpinBox *SPIN_SEG_LIGA_R;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QPushButton *pushButton_3;
    QLabel *label_12;
    QPushButton *pushButton_4;
    QLabel *label_13;
    QLabel *LABEL_HORA;
    QLabel *LABEL_DATA;
    QLabel *LABEL_SERVO1;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(637, 357);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(30, 230, 75, 23));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(480, 230, 121, 23));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 260, 141, 20));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(200, 0, 251, 51));
        QFont font;
        font.setPointSize(25);
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);
        LCD_TEMP = new QLCDNumber(centralWidget);
        LCD_TEMP->setObjectName(QString::fromUtf8("LCD_TEMP"));
        LCD_TEMP->setGeometry(QRect(30, 60, 64, 23));
        LCD_UMI = new QLCDNumber(centralWidget);
        LCD_UMI->setObjectName(QString::fromUtf8("LCD_UMI"));
        LCD_UMI->setGeometry(QRect(140, 60, 64, 23));
        LCD_PRESS = new QLCDNumber(centralWidget);
        LCD_PRESS->setObjectName(QString::fromUtf8("LCD_PRESS"));
        LCD_PRESS->setGeometry(QRect(240, 60, 64, 23));
        LCD_DISTANCIA = new QLCDNumber(centralWidget);
        LCD_DISTANCIA->setObjectName(QString::fromUtf8("LCD_DISTANCIA"));
        LCD_DISTANCIA->setGeometry(QRect(350, 60, 64, 23));
        SLIDER_SERVO1 = new QSlider(centralWidget);
        SLIDER_SERVO1->setObjectName(QString::fromUtf8("SLIDER_SERVO1"));
        SLIDER_SERVO1->setGeometry(QRect(450, 60, 160, 16));
        SLIDER_SERVO1->setMaximum(180);
        SLIDER_SERVO1->setSingleStep(1);
        SLIDER_SERVO1->setOrientation(Qt::Horizontal);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 90, 81, 20));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(150, 90, 61, 20));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(250, 90, 61, 21));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(360, 90, 61, 20));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(470, 40, 47, 13));
        SPIN_HORA_LIGA_M = new QSpinBox(centralWidget);
        SPIN_HORA_LIGA_M->setObjectName(QString::fromUtf8("SPIN_HORA_LIGA_M"));
        SPIN_HORA_LIGA_M->setGeometry(QRect(30, 150, 42, 22));
        SPIN_HORA_LIGA_M->setMaximum(23);
        SPIN_HORA_LIGA_M->setSingleStep(1);
        SPIN_MIN_LIGA_M = new QSpinBox(centralWidget);
        SPIN_MIN_LIGA_M->setObjectName(QString::fromUtf8("SPIN_MIN_LIGA_M"));
        SPIN_MIN_LIGA_M->setGeometry(QRect(80, 150, 42, 22));
        SPIN_MIN_LIGA_M->setMaximum(59);
        SPIN_SEG_LIGA_M = new QSpinBox(centralWidget);
        SPIN_SEG_LIGA_M->setObjectName(QString::fromUtf8("SPIN_SEG_LIGA_M"));
        SPIN_SEG_LIGA_M->setGeometry(QRect(130, 150, 42, 22));
        SPIN_SEG_LIGA_M->setMaximum(59);
        SPIN_HORA_DESLIGA_M = new QSpinBox(centralWidget);
        SPIN_HORA_DESLIGA_M->setObjectName(QString::fromUtf8("SPIN_HORA_DESLIGA_M"));
        SPIN_HORA_DESLIGA_M->setGeometry(QRect(30, 180, 42, 22));
        SPIN_HORA_DESLIGA_M->setMaximum(23);
        SPIN_HORA_DESLIGA_M->setSingleStep(1);
        SPIN_MIN_DESLIGA_M = new QSpinBox(centralWidget);
        SPIN_MIN_DESLIGA_M->setObjectName(QString::fromUtf8("SPIN_MIN_DESLIGA_M"));
        SPIN_MIN_DESLIGA_M->setGeometry(QRect(80, 180, 42, 22));
        SPIN_MIN_DESLIGA_M->setMaximum(59);
        SPIN_SEG_DESLIGA_M = new QSpinBox(centralWidget);
        SPIN_SEG_DESLIGA_M->setObjectName(QString::fromUtf8("SPIN_SEG_DESLIGA_M"));
        SPIN_SEG_DESLIGA_M->setGeometry(QRect(130, 180, 42, 22));
        SPIN_SEG_DESLIGA_M->setMaximum(59);
        SPIN_HORA_DESLIGA_R = new QSpinBox(centralWidget);
        SPIN_HORA_DESLIGA_R->setObjectName(QString::fromUtf8("SPIN_HORA_DESLIGA_R"));
        SPIN_HORA_DESLIGA_R->setGeometry(QRect(370, 180, 42, 22));
        SPIN_HORA_DESLIGA_R->setMaximum(23);
        SPIN_HORA_DESLIGA_R->setSingleStep(1);
        SPIN_SEG_DESLIGA_R = new QSpinBox(centralWidget);
        SPIN_SEG_DESLIGA_R->setObjectName(QString::fromUtf8("SPIN_SEG_DESLIGA_R"));
        SPIN_SEG_DESLIGA_R->setGeometry(QRect(470, 180, 42, 22));
        SPIN_SEG_DESLIGA_R->setMaximum(59);
        SPIN_HORA_LIGA_R = new QSpinBox(centralWidget);
        SPIN_HORA_LIGA_R->setObjectName(QString::fromUtf8("SPIN_HORA_LIGA_R"));
        SPIN_HORA_LIGA_R->setGeometry(QRect(370, 150, 42, 22));
        SPIN_HORA_LIGA_R->setMaximum(23);
        SPIN_HORA_LIGA_R->setSingleStep(1);
        SPIN_MIN_LIGA_R = new QSpinBox(centralWidget);
        SPIN_MIN_LIGA_R->setObjectName(QString::fromUtf8("SPIN_MIN_LIGA_R"));
        SPIN_MIN_LIGA_R->setGeometry(QRect(420, 150, 42, 22));
        SPIN_MIN_LIGA_R->setMaximum(59);
        SPIN_MIN_DESLIGA_R = new QSpinBox(centralWidget);
        SPIN_MIN_DESLIGA_R->setObjectName(QString::fromUtf8("SPIN_MIN_DESLIGA_R"));
        SPIN_MIN_DESLIGA_R->setGeometry(QRect(420, 180, 42, 22));
        SPIN_MIN_DESLIGA_R->setMaximum(59);
        SPIN_SEG_LIGA_R = new QSpinBox(centralWidget);
        SPIN_SEG_LIGA_R->setObjectName(QString::fromUtf8("SPIN_SEG_LIGA_R"));
        SPIN_SEG_LIGA_R->setGeometry(QRect(470, 150, 42, 22));
        SPIN_SEG_LIGA_R->setMaximum(59);
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(180, 150, 81, 16));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(180, 180, 91, 16));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(520, 150, 71, 16));
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(520, 180, 61, 16));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(490, 80, 75, 23));
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(450, 260, 181, 20));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(250, 230, 75, 23));
        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(240, 260, 101, 21));
        LABEL_HORA = new QLabel(centralWidget);
        LABEL_HORA->setObjectName(QString::fromUtf8("LABEL_HORA"));
        LABEL_HORA->setGeometry(QRect(220, 300, 81, 16));
        LABEL_DATA = new QLabel(centralWidget);
        LABEL_DATA->setObjectName(QString::fromUtf8("LABEL_DATA"));
        LABEL_DATA->setGeometry(QRect(320, 300, 81, 16));
        LABEL_SERVO1 = new QLabel(centralWidget);
        LABEL_SERVO1->setObjectName(QString::fromUtf8("LABEL_SERVO1"));
        LABEL_SERVO1->setGeometry(QRect(530, 40, 47, 13));
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Controle Horario", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Status da Porta : FECHADA", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "IHM FURIOSA", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "TEMPERATURA", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "UMIDADE", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "PRESS\303\203O", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "DISTANCIA", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "SERVO1:", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "LIGA MOTOR", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "DESLIGA MOTOR", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "LIGA RELE", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "DESLIGA RELE", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Envia Servo1", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Envia Configura\303\247\303\265es controle horario", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Rel\303\263gio", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Configura rel\303\263gio", nullptr));
        LABEL_HORA->setText(QCoreApplication::translate("MainWindow", "xx:xx:xx", nullptr));
        LABEL_DATA->setText(QCoreApplication::translate("MainWindow", "xx/xx/xxxx", nullptr));
        LABEL_SERVO1->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
