#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QTcpServer>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_setListen_clicked();

private:
    Ui::MainWindow *ui;
    QTcpServer *m_s;
};
#endif // MAINWINDOW_H
