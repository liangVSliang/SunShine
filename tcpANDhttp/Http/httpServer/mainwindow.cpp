#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QNetworkReply>
#include <QFileInfo>
#include <QDesktopServices>
#include <QDir>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::do_finished()
{
    //网络相应结束
    QFileInfo fileInfo(downloadedFile->fileName());
    downloadedFile->close();
    delete downloadedFile;
    reply->deleteLater();
    if(ui->checkBox->isChecked())
        QDesktopServices::openUrl(QUrl::fromLocalFile(fileInfo.absoluteFilePath()));
    ui->btnDownload->setEnabled(true);
}

void MainWindow::do_readyRead()
{
    //读取下载的数据
    downloadedFile->write(reply->readAll());
}

void MainWindow::do_downloadPrrogress(qint64 bytesRead, qint64 totalBytes)
{
    //读取下载进度
    ui->progressBar->setMaximum(totalBytes);
    ui->progressBar->setValue(bytesRead);
}

void MainWindow::on_btnDownload_clicked()
{
    //下载
    QString urlSpec=ui->editURL->text().trimmed();
    if(urlSpec.isEmpty())
    {
        QMessageBox::information(this,"错误","请指定需要下载的URL");
        return;
    }
    QUrl newUrl=QUrl::fromUserInput(urlSpec);  //URL
    if(!newUrl.isValid())
    {
        QString info="无效URL:"+urlSpec+"\n错误信息："+newUrl.errorString();
        QMessageBox::information(this,"错误",info);
        return;
    }
    QString tempDir=ui->editPath->text().trimmed();  //临时文件
    if(tempDir.isEmpty())
    {
        QMessageBox::information(this,"错误","请指定保存下载文件的目录");
        return;
    }

    QString fullFileName=tempDir+newUrl.fileName();
    if(QFile::exists(fullFileName))
        QFile::remove(fullFileName);
    downloadedFile=new QFile(fullFileName);
    if(!downloadedFile->open(QIODevice::WriteOnly))
    {
        QMessageBox::information(this,"错误","临时文件打开错误");
            return;
    }
    reply=networkManager.get(QNetworkRequest(newUrl));
    connect(reply,&QNetworkReply::readyRead,this,&MainWindow::do_readyRead);
    connect(reply,&QNetworkReply::downloadProgress,this,&::MainWindow::do_downloadPrrogress);
    connect(reply,&QNetworkReply::finished,this,&MainWindow::do_finished);
}


void MainWindow::on_btnDefaultPath_clicked()
{
    //默认路径按钮
    QString curPath=QDir::currentPath();
    QDir dir(curPath);
    QString sub="temp";
    dir.mkdir(sub);
    ui->editPath->setText(curPath+"/"+sub+"/");
}

