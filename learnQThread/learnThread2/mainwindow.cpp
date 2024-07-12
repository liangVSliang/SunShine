#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mythread.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QThread *t1=new QThread;
    QThread *t2=new QThread;
    QThread *t3=new QThread;

    Generate *gen=new Generate;
    BubbleSort *bub=new BubbleSort;
    QuickSort *qui=new QuickSort;

    gen->moveToThread(t1);
    bub->moveToThread(t2);
    qui->moveToThread(t3);

    ui->setupUi(this);

    connect(ui->star,&QPushButton::clicked,this,[=]{
        emit staring(10000);
        t1->start();
    });
    connect(this,&MainWindow::staring,gen,&Generate::working);

    connect(gen,&Generate::sendArray,bub,&BubbleSort::working);
    connect(gen,&Generate::sendArray,qui,&QuickSort::working);

    connect(gen,&Generate::sendArray,this,[=](QVector<int> list){
        t2->start();
        t3->start();
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

connect(this,&MainWindow::destroyed,this,[=](){
        t1->quit();
        t1->wait();
        t1->deleteLater();

        t2->quit();
        t2->wait();
        t2->deleteLater();

        t3->quit();
        t3->wait();
        t3->deleteLater();

        gen->deleteLater();
        bub->deleteLater();
        qui->deleteLater();
});

}
MainWindow::~MainWindow()
{
    delete ui;
}
