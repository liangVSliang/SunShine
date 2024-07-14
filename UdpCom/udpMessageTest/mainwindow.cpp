#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QHostInfo>
#include <QHostAddress>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("小蓝");

    udpSocket=new QUdpSocket(this);

    connect(udpSocket,SIGNAL(readyRead()),this,SLOT(do_socketReadyRead()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::do_socketReadyRead()
{
    //读取收到的数据报
    QByteArray datagram;
    datagram.resize(udpSocket->pendingDatagramSize());
    QHostAddress peerAddr;                //对方地址
    quint16  peerPort;                    //对方端口
    udpSocket->readDatagram(datagram.data(),datagram.size(),&peerAddr,&peerPort);
    QString str=datagram.data();

    ui->textEdit->appendPlainText("小蓝："+str);

}

void MainWindow::on_actStart_clicked()
{
    //绑定端口
    quint16 port=1314;
    if(udpSocket->bind(port))
    {
        ui->textEdit->appendPlainText("已连接小蓝");
    }else{
        ui->textEdit->appendPlainText("绑定失败");
    }
}


void MainWindow::on_actStop_clicked()
{
    udpSocket->abort();
    ui->textEdit->appendPlainText("解除绑定");
}




void MainWindow::on_btnSend_clicked()
{
    //发送消息按钮
    QString targetIP="127.0.0.1";                   //目标IP地址
    QHostAddress targetAddr(targetIP);              //目标主机
    quint16 targetPort=520;                         //目标端口
    QString msg=ui->editMsg->text();
    QByteArray str=msg.toUtf8();
    udpSocket->writeDatagram(str,targetAddr,targetPort);
    ui->textEdit->appendPlainText("小红："+msg);
    ui->editMsg->clear();
    ui->editMsg->setFocus();
}



