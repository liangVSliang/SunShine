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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *editMsg;
    QPushButton *btnSend;
    QPushButton *actStart;
    QPushButton *actStop;
    QPlainTextEdit *textEdit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(485, 643);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 480, 441, 31));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        editMsg = new QLineEdit(layoutWidget);
        editMsg->setObjectName("editMsg");

        horizontalLayout_4->addWidget(editMsg);

        btnSend = new QPushButton(layoutWidget);
        btnSend->setObjectName("btnSend");

        horizontalLayout_4->addWidget(btnSend);

        actStart = new QPushButton(centralwidget);
        actStart->setObjectName("actStart");
        actStart->setGeometry(QRect(20, 520, 92, 71));
        actStop = new QPushButton(centralwidget);
        actStop->setObjectName("actStop");
        actStop->setGeometry(QRect(370, 520, 92, 71));
        textEdit = new QPlainTextEdit(centralwidget);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(20, 30, 441, 441));
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
        btnSend->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\344\277\241\346\201\257", nullptr));
        actStart->setText(QCoreApplication::translate("MainWindow", "\347\273\221\345\256\232\345\260\217\350\223\235", nullptr));
        actStop->setText(QCoreApplication::translate("MainWindow", "\350\247\243\351\231\244\347\273\221\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
