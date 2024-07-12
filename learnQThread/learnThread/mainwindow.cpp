#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "generate.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //创建子线程对象
    Generate* gen=new Generate;
    BubbleSort *bubble=new BubbleSort;
    QuickSort *quick=new QuickSort;

    //2.主线程接收starting参数，主函数变化
    connect(this,&MainWindow::starting,gen,&Generate::recvNum);

    connect(gen,&Generate::sendArray,bubble,&BubbleSort::recvArray);
    connect(gen,&Generate::sendArray,quick,&QuickSort::recvArray);

    //1.点击按钮向主函数发送数据并启动子线程
    connect(ui->star,&QPushButton::clicked,this,[=](){
        emit starting(10000);
        gen->start();
    });


    // 3.子线程发生变化并向主线程递交数据线程发送的数据
    connect(gen,&Generate::sendArray,this,[=](QVector<int> list){
        //此时随机序列已经生成
        bubble->start();
        quick->start();
        for(int i=0;i<list.size();i++){
            ui->randomlist->addItem(QString::number(list.at(i)));
        }
    });
    connect(bubble,&BubbleSort::finish,this,[=](QVector<int> list){
        for(int i=0;i<list.size();i++){
            ui->bublelist->addItem(QString::number(list.at(i)));
        }
    });
    connect(quick,&QuickSort::finish,this,[=](QVector<int> list){
        for(int i=0;i<list.size();i++){
            ui->quicklist->addItem(QString::number(list.at(i)));
        }
    });
    //销毁线程
    connect(this,&MainWindow::destroyed,this,[=](){
        //请求线程退出
        gen->quit();
        //等待线程真正退出
        gen->wait();
        //含销毁线程的方法
        gen->deleteLater();

        bubble->quit();
        bubble->wait();
        bubble->deleteLater();

        quick->quit();
        quick->wait();
        quick->deleteLater();

    });
}
MainWindow::~MainWindow()
{
    delete ui;
}
