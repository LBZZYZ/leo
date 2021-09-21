#include "QAvatar.h"
#include"qpixmap.h"
#include <QBitmap>

QAvatar::QAvatar(QWidget* parent)
{

}

QAvatar::QAvatar(QPixmap *avatar, QSize size, EN_AVATAR_SHAPE shape, int x, int y, bool isclickable, QWidget *parent):
	m_AvaFile(*avatar),
	m_AvaSize(size),
	m_AvaShape(shape),
	m_AvaIsClickable(isclickable),
	m_AvaPosX(x),
	m_AvaPosY(y),
	QPushButton(parent)
{
	QPixmap pixmap("Resources/HeadPortraits.png");
	setMask(QBitmap(pixmap.mask()));
	
	this->setGeometry(m_AvaPosX,m_AvaPosY,m_AvaSize.rwidth(),m_AvaSize.rheight());
	//this->setEnabled(isEnabled);
	this->setIcon(QIcon(*avatar));
	this->setIconSize(size);
}


QAvatar::~QAvatar()
{

}
