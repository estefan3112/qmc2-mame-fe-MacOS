#include "videosnapplayerwidget.h"

#include <QVBoxLayout>
#include <QFile>
#include <QUrl>
#include <QMediaPlayer>
#include <QVideoWidget>

VideoSnapPlayerWidget::VideoSnapPlayerWidget(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    player = new QMediaPlayer(this);
    videoWidget = new QVideoWidget(this);

    player->setVideoOutput(videoWidget);
    layout->addWidget(videoWidget);
}

void VideoSnapPlayerWidget::setVideoFile(const QString &path)
{
    if (QFile::exists(path)) {
        player->setMedia(QUrl::fromLocalFile(path));
        player->play();
    } else {
        player->stop();
    }
}

void VideoSnapPlayerWidget::stop()
{
    player->stop();
}