#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtSql>
#include <QDataWidgetMapper>
#include "tcomboboxdelegate.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QSqlDatabase DB;
    QSqlTableModel *tabModel;
    QItemSelectionModel *selModel;

    TComboBoxDelegate delegateSex;
    TComboBoxDelegate delegateDepart;
    QDataWidgetMapper *dataMapper;
    void openTable();
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actOpenDB_triggered();

    void do_currentRowChanged(const QModelIndex &current,const QModelIndex &previous);

    void on_actAdd_triggered();

    void on_actInsert_triggered();

    void on_actDelete_triggered();

    void on_actPhoto_triggered();

    void on_actSave_triggered();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
