#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QFileDialog>
#include <QAudioOutput>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("QMainWindow {background-image:url(:/new/prefix1/img/sheet.webp)}");
    player=new QMediaPlayer(this);    //创建播放器
    QAudioOutput *au=new QAudioOutput(this);
    player->setAudioOutput(au);
    player->setVideoOutput(ui->videowidget);  //设置视频输出组件
    ui->videowidget->setMediaPlayer(player);
    connect(player,&QMediaPlayer::positionChanged,this,&MainWindow::do_positionChanged);
    connect(player,&QMediaPlayer::durationChanged,this,&MainWindow::do_durationChanged);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnAdd_clicked()
{
    //打开文件
    QString curPath=QDir::homePath();
    QString dlgTitle="选择视频文件";
    QString filter="视频文件(*.wmv;*.mp4);;所有文件(*.*)";
    QString aFile=QFileDialog::getOpenFileName(this,dlgTitle,curPath,filter);
    if(aFile.isEmpty())
        return;
    QFileInfo fileInfo(aFile);
    ui->labCurMedia->setText(fileInfo.fileName());
    player->setSource(QUrl::fromLocalFile(aFile));        //设置播放文件
    player->play();
}


void MainWindow::on_btnPlay_clicked()
{
    //播放
    player->play();
}


void MainWindow::on_btnPause_clicked()
{
    //暂停
    player->pause();
}


void MainWindow::on_btnStop_clicked()
{
    //停止
    player->stop();
}


void MainWindow::on_sliderVolumn_valueChanged(int value)
{
    //调节音量
    player->audioOutput()->setVolume(value/100.0);
}


void MainWindow::on_btnSound_clicked()
{
    //静音
    bool mute=player->audioOutput()->isMuted();
    player->audioOutput()->setMuted(!mute);

}


void MainWindow::on_sliderPosition_valueChanged(int value)
{
    //播放位置
     player->setPosition(value);
}


void MainWindow::on_pushButton_clicked()
{
    //全屏
     ui->videowidget->setFullScreen(true);
}

void MainWindow::do_durationChanged(qint64 duration)
{
    //文件时长变化
    ui->test->setMaximum(duration);
    int secs=duration/1000;
    int mins=duration/60;
    secs=secs % 60;
    durationTime=QString::asprintf("%d:%d",mins,secs);
    ui->LabRatio->setText(positionTime+"/"+durationTime);

}
void MainWindow::do_positionChanged(qint64 position)
{
    if(ui->test->isSliderDown())
        return;
     ui->test->setSliderPosition(position);
     int secs=position/1000;
     int mins=secs/60;
     secs=secs % 60;
     positionTime=QString::asprintf("%d:%d",mins,secs);
     ui->LabRatio->setText(positionTime+"/"+durationTime);
}
