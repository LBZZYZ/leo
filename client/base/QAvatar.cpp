#include "QAvatar.h"
#include"qpixmap.h"
#include <QBitmap>

QAvatar::QAvatar(QWidget* parent)
{

}

QAvatar::QAvatar(QPixmap *avatar, QSize size, EN_AVATAR_SHAPE shape, QPoint pos, bool isclickable, QWidget *parent):
	m_AvaFile(*avatar),
	m_AvaSize(size),
	m_AvaShape(shape),
	m_AvaIsClickable(isclickable),
	m_AvaPos(pos),
	QPushButton(parent)
{
	QPixmap pixmap("Resources/HeadPortraits.png");
	setMask(QBitmap(pixmap.mask()));
	
	this->setGeometry(m_AvaPos.x(), m_AvaPos.y(),m_AvaSize.rwidth(),m_AvaSize.rheight());
	this->setIcon(QIcon(*avatar));
	this->setIconSize(size);
}


QAvatar::~QAvatar()
{

}

void QAvatar::SetAvatar(QPixmap* avatar)
{
	this->setIcon(QIcon(*avatar));
	this->setIconSize(QSize(48, 48));
	this->setGeometry(0, 0, 48, 48);
}
