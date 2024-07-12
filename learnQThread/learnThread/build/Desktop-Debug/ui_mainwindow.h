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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout;
    QGroupBox *randombox;
    QListWidget *randomlist;
    QGroupBox *bubulbox;
    QListWidget *bublelist;
    QGroupBox *quickbox;
    QListWidget *quicklist;
    QPushButton *star;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(120, 50, 581, 471));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget1 = new QWidget(widget);
        widget1->setObjectName("widget1");
        horizontalLayout = new QHBoxLayout(widget1);
        horizontalLayout->setObjectName("horizontalLayout");
        randombox = new QGroupBox(widget1);
        randombox->setObjectName("randombox");
        randomlist = new QListWidget(randombox);
        randomlist->setObjectName("randomlist");
        randomlist->setGeometry(QRect(0, 20, 181, 391));

        horizontalLayout->addWidget(randombox);

        bubulbox = new QGroupBox(widget1);
        bubulbox->setObjectName("bubulbox");
        bublelist = new QListWidget(bubulbox);
        bublelist->setObjectName("bublelist");
        bublelist->setGeometry(QRect(0, 20, 181, 391));

        horizontalLayout->addWidget(bubulbox);

        quickbox = new QGroupBox(widget1);
        quickbox->setObjectName("quickbox");
        quicklist = new QListWidget(quickbox);
        quicklist->setObjectName("quicklist");
        quicklist->setGeometry(QRect(0, 20, 181, 391));

        horizontalLayout->addWidget(quickbox);


        verticalLayout->addWidget(widget1);

        star = new QPushButton(widget);
        star->setObjectName("star");

        verticalLayout->addWidget(star);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        randombox->setTitle(QCoreApplication::translate("MainWindow", "\351\232\217\346\234\272\347\232\204", nullptr));
        bubulbox->setTitle(QCoreApplication::translate("MainWindow", "\345\206\222\346\263\241\346\216\222\345\272\217\347\273\223\346\236\234", nullptr));
        quickbox->setTitle(QCoreApplication::translate("MainWindow", "\345\277\253\351\200\237\346\216\222\345\272\217\347\273\223\346\236\234", nullptr));
        star->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
