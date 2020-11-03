#include "qheadicon.h"
#include"qpixmap.h"
#include"qbitmap.h"
QHeadIcon::QHeadIcon(QPixmap *Icon, int x, int y, int w, int h, bool isEnabled, QWidget* parent)
: QPushButton(parent)
{
	this->setGeometry(x,y,w,h);
	this->setEnabled(isEnabled);
	QPixmap pixmap("Resources/HeadPortraits.png");
	setMask(QBitmap(pixmap.mask()));
	setStyleSheet(QString("QPushButton{background-image:url(Resources/QQImage.png);border:none}"));
}


QHeadIcon::~QHeadIcon()
{

}
