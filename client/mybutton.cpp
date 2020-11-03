#include "mybutton.h"
#include"qpixmap.h"
#include"qbitmap.h"
#include <QTimer>
#include <QTimerEvent>
#include <QDebug>
#include <mybuttonone.h>
// 头像 圆形 控件
MyButton::MyButton(QWidget *parent)
	: QPushButton(parent)
{
	QPixmap pixmap("Resources/QQimage.png");
	setMask(QBitmap(pixmap.mask()));
	setStyleSheet(QString("QPushButton{"
		"border-image:url(Resources/QQimage.png)"
"}"));
	setGeometry(120,70, pixmap.size().width(), pixmap.size().height());

	 
}

MyButton::~MyButton()
{

}

//void MyButton::enterEvent(QEvent *e)
//{
//  timeId = this->startTimer(10);	
//}
//
//void MyButton::leaveEvent(QEvent *e)
//{
//	this->killTimer(timeId);
//}
//
//void MyButton::timerEvent(QTimerEvent *e)
//{
//	static int  sec = 1;
//	if (this->geometry().x() >= 200)
//	{
//		sec = 0;
//	}
//	this->move(geometry().x()+sec, geometry().y());
//	qDebug() << sec;
//	
//	//sec++;
//}
