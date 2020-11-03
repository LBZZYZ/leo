#include "mybuttonone.h"
#include"qpixmap.h"
#include"qbitmap.h"
#include "qevent.h"

Mybuttonone::Mybuttonone(QWidget *parent)
	: QPushButton(parent)
{

	QPixmap pixmap("Resources/addbutton.png");
	resize(48,48);
	setMask(QBitmap(pixmap.mask()));
	setStyleSheet(QString("QPushButton{border-image:url(Resources/addbutton.png)}"));
	setGeometry(200, 60, pixmap.size().width(), pixmap.size().height());
}

Mybuttonone::~Mybuttonone()
{

}