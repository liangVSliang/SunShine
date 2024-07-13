#ifndef TMYVIDEOWIDGET_H
#define TMYVIDEOWIDGET_H

#include <QVideoWidget>
#include <QMediaPlayer>
#include <QKeyEvent>
class QMyVideoWidget : public QVideoWidget
{
    Q_OBJECT
private:
    QMediaPlayer *m_Player;

public:
    explicit QMyVideoWidget(QWidget *parent = nullptr);
    void setMediaPlayer(QMediaPlayer *player);

    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
};



#endif // TMYVIDEOWIDGET_H
