#ifndef VIDEOSNAPPLAYERWIDGET_H
#define VIDEOSNAPPLAYERWIDGET_H

#include <QWidget>
#include <QMediaPlayer>
#include <QVideoWidget>

class VideoSnapPlayerWidget : public QWidget {
    Q_OBJECT

public:
    explicit VideoSnapPlayerWidget(QWidget *parent = nullptr);
    void setVideoFile(const QString &path);
    void stop();

private:
    QMediaPlayer *player;
    QVideoWidget *videoWidget;
};

#endif // VIDEOSNAPPLAYERWIDGET_H