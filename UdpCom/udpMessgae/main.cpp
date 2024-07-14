#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    // 设置背景图片路径，确保路径正确
    QString backgroundImagePath = ":/new/prefix1/img/xiaolan.jpg";

    // 设置样式表，使用背景图
    w.setStyleSheet(QString("QMainWindow { background-image: url(%1); }").arg(backgroundImagePath));
    w.show();
    return a.exec();
}
