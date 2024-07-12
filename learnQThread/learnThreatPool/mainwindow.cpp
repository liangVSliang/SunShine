#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mythread.h"
#include <QThreadPool>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    Generate *gen=new Generate;
    BubbleSort *bub=new BubbleSort;
    QuickSort *qui=new QuickSort;

    connect(this,&MainWindow::staring,gen,&Generate::recvNum);

    ui->setupUi(this);

    connect(ui->star,&QPushButton::clicked,this,[=]{
        emit staring(10000);
        QThreadPool::globalInstance()->start(gen);   //将对象扔进线程池
    });


    connect(gen,&Generate::sendArray,bub,&BubbleSort::recvArray);
    connect(gen,&Generate::sendArray,qui,&QuickSort::recvArray);

    connect(gen,&Generate::sendArray,this,[=](QVector<int> list){
        QThreadPool::globalInstance()->start(bub);
        QThreadPool::globalInstance()->start(qui);
        for(int i=0;i<list.size();i++)
        {
            ui->randomlist->addItem(QString::number(list.at(i)));
        }
    });
    connect(bub,&BubbleSort::finish,this,[=](QVector<int> list){
        for(int i=0;i<list.size();i++)
        {
            ui->bublelist->addItem(QString::number(list.at(i)));
        }
    });
    connect(qui,&QuickSort::finish,this,[=](QVector<int> list){
        for(int i=0;i<list.size();i++)
        {
            ui->quicklist->addItem(QString::number(list.at(i)));
        }
    });

}
MainWindow::~MainWindow()
{
    delete ui;
}
