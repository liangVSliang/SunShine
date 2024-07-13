#include "qmyvideowidget.h"

QMyVideoWidget::QMyVideoWidget(QWidget *parent)
    : QVideoWidget{parent}
{}

void QMyVideoWidget::setMediaPlayer(QMediaPlayer *player)
{
    m_Player=player;
}

void QMyVideoWidget::mousePressEvent(QMouseEvent *event)
{
    //鼠标事件处理函数，点击时暂停播放或继续播放
    if(event->button()==Qt::LeftButton)
    {
        if(m_Player->playbackState()==QMediaPlayer::PlayingState)
            m_Player->pause();
        else
            m_Player->play();
    }
    QVideoWidget::mousePressEvent(event);
}

void QMyVideoWidget::keyPressEvent(QKeyEvent *event)
{
    //按键事件处理函数，按ESC键退出全屏状态
    if((event->key()==Qt::Key_Escape)&&(isFullScreen()))
    {
        setFullScreen(false);
        event->accept();
        QVideoWidget::keyPressEvent(event);
    }
}
