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
    QPlainTextEdit *textEdit;
    QPushButton *actStop;
    QPushButton *actStart;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *editMsg;
    QPushButton *btnSend;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(481, 626);
        MainWindow->setMaximumSize(QSize(1677, 16777215));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        textEdit = new QPlainTextEdit(centralwidget);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(20, 20, 441, 441));
        actStop = new QPushButton(centralwidget);
        actStop->setObjectName("actStop");
        actStop->setGeometry(QRect(370, 510, 92, 71));
        actStart = new QPushButton(centralwidget);
        actStart->setObjectName("actStart");
        actStart->setGeometry(QRect(20, 510, 92, 71));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 470, 441, 31));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        editMsg = new QLineEdit(layoutWidget);
        editMsg->setObjectName("editMsg");

        horizontalLayout_4->addWidget(editMsg);

        btnSend = new QPushButton(layoutWidget);
        btnSend->setObjectName("btnSend");

        horizontalLayout_4->addWidget(btnSend);

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
        actStop->setText(QCoreApplication::translate("MainWindow", "\350\247\243\351\231\244\347\273\221\345\256\232", nullptr));
        actStart->setText(QCoreApplication::translate("MainWindow", "\347\273\221\345\256\232\345\260\217\347\272\242", nullptr));
        btnSend->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\344\277\241\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
