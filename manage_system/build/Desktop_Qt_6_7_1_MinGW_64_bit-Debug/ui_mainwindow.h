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
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actOpenDB;
    QAction *actAdd;
    QAction *actInsert;
    QAction *actDelete;
    QAction *actPhoto;
    QAction *actSave;
    QWidget *centralwidget;
    QTableView *tableView;
    QGroupBox *groupBox_4;
    QLabel *label_8;
    QLabel *label_7;
    QLabel *label_6;
    QLabel *label_5;
    QLabel *label_4;
    QLabel *label_3;
    QLineEdit *dbEditName;
    QLabel *label_2;
    QLineEdit *dbComboSex;
    QLineEdit *dbEditBirth;
    QLineEdit *dbComboProvince;
    QLineEdit *dbComboDep;
    QLineEdit *dbSpinSalary;
    QLineEdit *dbSpinEmpNo;
    QGroupBox *groupBox_5;
    QHBoxLayout *horizontalLayout_9;
    QLabel *dbLabPhoto;
    QGroupBox *groupboxs;
    QPlainTextEdit *dbEditMemo;
    QSplitter *splitter;
    QPushButton *pushButton;
    QLineEdit *findName;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1063, 679);
        actOpenDB = new QAction(MainWindow);
        actOpenDB->setObjectName("actOpenDB");
        actOpenDB->setCheckable(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/img/start.png"), QSize(), QIcon::Normal, QIcon::Off);
        actOpenDB->setIcon(icon);
        actOpenDB->setVisible(true);
        actOpenDB->setMenuRole(QAction::NoRole);
        actOpenDB->setIconVisibleInMenu(true);
        actAdd = new QAction(MainWindow);
        actAdd->setObjectName("actAdd");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/img/add.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actAdd->setIcon(icon1);
        actAdd->setMenuRole(QAction::NoRole);
        actInsert = new QAction(MainWindow);
        actInsert->setObjectName("actInsert");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/img/inserts.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actInsert->setIcon(icon2);
        actInsert->setMenuRole(QAction::NoRole);
        actDelete = new QAction(MainWindow);
        actDelete->setObjectName("actDelete");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/img/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        actDelete->setIcon(icon3);
        actDelete->setMenuRole(QAction::NoRole);
        actPhoto = new QAction(MainWindow);
        actPhoto->setObjectName("actPhoto");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/prefix1/img/set.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actPhoto->setIcon(icon4);
        actPhoto->setMenuRole(QAction::NoRole);
        actSave = new QAction(MainWindow);
        actSave->setObjectName("actSave");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/prefix1/img/save.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actSave->setIcon(icon5);
        actSave->setMenuRole(QAction::NoRole);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(10, 50, 411, 451));
        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(470, 40, 301, 461));
        label_8 = new QLabel(groupBox_4);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(20, 340, 51, 19));
        label_7 = new QLabel(groupBox_4);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(20, 290, 61, 27));
        label_6 = new QLabel(groupBox_4);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 240, 71, 27));
        label_5 = new QLabel(groupBox_4);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 190, 71, 27));
        label_4 = new QLabel(groupBox_4);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 140, 51, 27));
        label_3 = new QLabel(groupBox_4);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 90, 51, 29));
        dbEditName = new QLineEdit(groupBox_4);
        dbEditName->setObjectName("dbEditName");
        dbEditName->setGeometry(QRect(100, 90, 181, 27));
        label_2 = new QLabel(groupBox_4);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 40, 51, 29));
        dbComboSex = new QLineEdit(groupBox_4);
        dbComboSex->setObjectName("dbComboSex");
        dbComboSex->setGeometry(QRect(100, 140, 181, 27));
        dbEditBirth = new QLineEdit(groupBox_4);
        dbEditBirth->setObjectName("dbEditBirth");
        dbEditBirth->setGeometry(QRect(100, 190, 181, 27));
        dbComboProvince = new QLineEdit(groupBox_4);
        dbComboProvince->setObjectName("dbComboProvince");
        dbComboProvince->setGeometry(QRect(100, 240, 181, 27));
        dbComboDep = new QLineEdit(groupBox_4);
        dbComboDep->setObjectName("dbComboDep");
        dbComboDep->setGeometry(QRect(100, 290, 181, 27));
        dbSpinSalary = new QLineEdit(groupBox_4);
        dbSpinSalary->setObjectName("dbSpinSalary");
        dbSpinSalary->setGeometry(QRect(100, 340, 181, 27));
        dbSpinEmpNo = new QLineEdit(groupBox_4);
        dbSpinEmpNo->setObjectName("dbSpinEmpNo");
        dbSpinEmpNo->setGeometry(QRect(100, 40, 181, 27));
        groupBox_5 = new QGroupBox(centralwidget);
        groupBox_5->setObjectName("groupBox_5");
        groupBox_5->setGeometry(QRect(770, 40, 251, 271));
        horizontalLayout_9 = new QHBoxLayout(groupBox_5);
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        dbLabPhoto = new QLabel(groupBox_5);
        dbLabPhoto->setObjectName("dbLabPhoto");

        horizontalLayout_9->addWidget(dbLabPhoto);

        groupboxs = new QGroupBox(centralwidget);
        groupboxs->setObjectName("groupboxs");
        groupboxs->setGeometry(QRect(770, 310, 251, 191));
        dbEditMemo = new QPlainTextEdit(groupboxs);
        dbEditMemo->setObjectName("dbEditMemo");
        dbEditMemo->setGeometry(QRect(0, 20, 251, 171));
        dbEditMemo->setCenterOnScroll(false);
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName("splitter");
        splitter->setGeometry(QRect(20, 10, 301, 28));
        splitter->setOrientation(Qt::Horizontal);
        pushButton = new QPushButton(splitter);
        pushButton->setObjectName("pushButton");
        splitter->addWidget(pushButton);
        findName = new QLineEdit(splitter);
        findName->setObjectName("findName");
        splitter->addWidget(findName);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        toolBar->setIconSize(QSize(60, 60));
        toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);

        toolBar->addAction(actOpenDB);
        toolBar->addAction(actAdd);
        toolBar->addAction(actInsert);
        toolBar->addAction(actDelete);
        toolBar->addAction(actPhoto);
        toolBar->addAction(actSave);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\344\277\241\346\201\257\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        actOpenDB->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
        actOpenDB->setIconText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
        actAdd->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240", nullptr));
        actInsert->setText(QCoreApplication::translate("MainWindow", "\346\217\222\345\205\245", nullptr));
        actDelete->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244", nullptr));
        actPhoto->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256\347\205\247\347\211\207", nullptr));
        actSave->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "\345\255\246\347\224\237\350\257\246\347\273\206\344\277\241\346\201\257", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\346\210\220\347\273\251\357\274\232", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\347\217\255\347\272\247\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\345\207\272\347\224\237\347\234\201\344\273\275\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\345\207\272\347\224\237\346\227\245\346\234\237\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\346\200\247\345\210\253\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\345\247\223\345\220\215\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\345\255\246\345\217\267\357\274\232", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "\345\255\246\347\224\237\345\244\264\345\203\217", nullptr));
        dbLabPhoto->setText(QCoreApplication::translate("MainWindow", "\347\202\271\345\207\273\345\267\245\345\205\267\346\240\217\350\256\276\347\275\256\345\244\264\345\203\217", nullptr));
        groupboxs->setTitle(QCoreApplication::translate("MainWindow", "\345\255\246\347\224\237\344\273\213\347\273\215", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\346\237\245\350\257\242\345\247\223\345\220\215", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
