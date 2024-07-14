#include "sendfile.h"
#include <QFile>
#include <QFileInfo>
SendFile::SendFile(QObject *parent)
    : QObject{parent}
{}

void SendFile::connectServer(unsigned short port, QString ip)
{
    m_tcp=new QTcpSocket;
    m_tcp->connectToHost(QHostAddress(ip),port);
    connect(m_tcp,&QTcpSocket::connected,this,&SendFile::connectOK);
    connect(m_tcp,&QTcpSocket::disconnected,this,[=](){
        m_tcp->close();
        m_tcp->deleteLater();
        emit gameover();
    });
}

void SendFile::sendFile(QString path)
{
    QFile file(path);
    QFileInfo info(path);
    int fileSize=info.size();

    file.open(QFile::ReadOnly);

    while (!file.atEnd())
    {
        static int num=0;
        if(num==0)
        {
            m_tcp->write((char*)&fileSize,4);//将len个字节数据从data指向的内存位置写入，发送一个字符串，指定大小为4
        }
        QByteArray line=file.readLine();
        num+=line.size();
        int precent=(num*100/fileSize);
        emit curPercent(precent);
        m_tcp->write(line);
    }
}
