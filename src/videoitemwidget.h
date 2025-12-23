#ifndef VIDEOITEMWIDGET_H
#define VIDEOITEMWIDGET_H

#include <Qt>
#include "ui_videoitemwidget.h"
#include "imagewidget.h"

#define VIDEOITEM_IMAGE_WIDTH					100
#define VIDEOITEM_IMAGE_HEIGHT					75

#define VIDEOITEM_TYPE_UNKNOWN					-1
#define VIDEOITEM_TYPE_LOCAL_MOVIE				2
#define VIDEOITEM_TYPE_VIDEO_SNAP				3

class VideoItemWidget : public QWidget, public Ui::VideoItemWidget
{
	Q_OBJECT

	public:
		ImagePixmap videoImage;
		QString videoID;
		QString videoAuthor;
		QString videoTitle;
		QString videoUrlPattern;
		QString authorUrlPattern;
		bool videoImageValid;
		void *myVideoPlayer;
		int itemType;

    	VideoItemWidget(QWidget *parent = 0);

	public slots:
		void setImage(const ImagePixmap &, bool valid = true);
		void setImage(ImagePixmap *, bool valid = true);
		void setID(QString);
		void setTitle(QString);
		void setAuthor(QString);
		void setType(int);
};

#endif // VIDEOITEMWIDGET_H