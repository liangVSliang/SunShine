/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include <qmyvideowidget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QPushButton *btnStop;
    QHBoxLayout *horizontalLayout;
    QLabel *labCurMedia;
    QSlider *test;
    QLabel *LabRatio;
    QPushButton *btnPlay;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_3;
    QMyVideoWidget *videowidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSlider *sliderVolumn;
    QPushButton *btnAdd;
    QPushButton *btnPause;
    QPushButton *pushButton;
    QPushButton *btnSound;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(916, 707);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout_4 = new QHBoxLayout(centralwidget);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName("gridLayout");
        btnStop = new QPushButton(groupBox);
        btnStop->setObjectName("btnStop");

        gridLayout->addWidget(btnStop, 3, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        labCurMedia = new QLabel(groupBox);
        labCurMedia->setObjectName("labCurMedia");

        horizontalLayout->addWidget(labCurMedia);

        test = new QSlider(groupBox);
        test->setObjectName("test");
        test->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(test);

        LabRatio = new QLabel(groupBox);
        LabRatio->setObjectName("LabRatio");

        horizontalLayout->addWidget(LabRatio);


        gridLayout->addLayout(horizontalLayout, 4, 0, 1, 1);

        btnPlay = new QPushButton(groupBox);
        btnPlay->setObjectName("btnPlay");

        gridLayout->addWidget(btnPlay, 1, 1, 1, 1);

        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName("groupBox_2");
        horizontalLayout_3 = new QHBoxLayout(groupBox_2);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        videowidget = new QMyVideoWidget(groupBox_2);
        videowidget->setObjectName("videowidget");

        horizontalLayout_3->addWidget(videowidget);


        gridLayout->addWidget(groupBox_2, 0, 0, 4, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(groupBox);
        label->setObjectName("label");

        horizontalLayout_2->addWidget(label);

        sliderVolumn = new QSlider(groupBox);
        sliderVolumn->setObjectName("sliderVolumn");
        sliderVolumn->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(sliderVolumn);


        gridLayout->addLayout(horizontalLayout_2, 5, 0, 1, 1);

        btnAdd = new QPushButton(groupBox);
        btnAdd->setObjectName("btnAdd");

        gridLayout->addWidget(btnAdd, 0, 1, 1, 1);

        btnPause = new QPushButton(groupBox);
        btnPause->setObjectName("btnPause");

        gridLayout->addWidget(btnPause, 2, 1, 1, 1);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");

        gridLayout->addWidget(pushButton, 4, 1, 1, 1);

        btnSound = new QPushButton(groupBox);
        btnSound->setObjectName("btnSound");

        gridLayout->addWidget(btnSound, 5, 1, 1, 1);


        horizontalLayout_4->addWidget(groupBox);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QString());
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\350\247\206\351\242\221\346\222\255\346\224\276\345\231\250", nullptr));
        btnStop->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242", nullptr));
        labCurMedia->setText(QCoreApplication::translate("MainWindow", "\346\222\255\346\224\276\346\226\207\344\273\266\345\220\215", nullptr));
        LabRatio->setText(QCoreApplication::translate("MainWindow", "\346\222\255\346\224\276\346\226\207\344\273\266\350\277\233\345\272\246", nullptr));
        btnPlay->setText(QCoreApplication::translate("MainWindow", "\346\222\255\346\224\276", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\350\247\206\351\242\221", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\351\237\263\351\207\217", nullptr));
        btnAdd->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
        btnPause->setText(QCoreApplication::translate("MainWindow", "\346\232\202\345\201\234", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\345\205\250\345\261\217", nullptr));
        btnSound->setText(QCoreApplication::translate("MainWindow", "\351\235\231\351\237\263", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
