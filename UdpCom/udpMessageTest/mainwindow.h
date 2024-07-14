#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QUdpSocket>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QLabel *labSocketState;     //状态栏的标签
    QUdpSocket *udpSocket;      //用于UDP通信的socket

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void do_socketReadyRead();              //读取socket传入的数据

    void on_actStart_clicked();

    void on_actStop_clicked();

    void on_btnSend_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
