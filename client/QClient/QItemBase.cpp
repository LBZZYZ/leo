#include "QItemBase.h"
#include <QDebug>
QItemBase::QItemBase(QWidget *parent)
	: QWidget(parent)
{
}

QItemBase::~QItemBase()
{
}


ITEM_RESULT QItemBase::ItemSetAvatar(QPixmap* avatar)
{
	if (0/*avatar == nullptr*/)
	{
		return ITEM_INVALID;
	}

	m_Avatar = new QAvatar(avatar, QSize(40, 40), E_AVATAR_SHAPE_CIRCLE, (int)avatar->rect().topLeft().x() + 10, (int)avatar->rect().topLeft().y() + 6, false, (QWidget*)this);

	return ITEM_OK;
}


ITEM_RESULT QItemBase::ItemSetName(QString name)
{
	QFont font;
	//font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
	font.setPointSize(14);

	QLabel* m_pNameLable = new QLabel(name, this);
	m_pNameLable->setGeometry(m_Avatar->rect().topLeft().x() + 10 + 55 + 10, m_Avatar->rect().topLeft().y() + 8, 150, 30);
	m_pNameLable->setFont(font);
	m_pNameLable->setStyleSheet("background-color:rgb(0,0,0,0);");

	return ITEM_OK;
}
ITEM_RESULT QItemBase::ItemSetRemark(QString remark)
{
	QFont font;
	font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
	font.setPointSize(14);

	QLabel* m_pNameLable = new QLabel(remark, this);
	m_pNameLable->setGeometry(m_Avatar->rect().topLeft().x() + 10 + 55 + 10, m_Avatar->rect().topLeft().y() + 8, 150, 30);
	m_pNameLable->setFont(font);
	m_pNameLable->setStyleSheet("background-color:rgb(0,0,0,0);");

	return ITEM_OK;
}


void QItemBase::mouseDoubleClickEvent(QMouseEvent* event)
{
	qDebug() << "QItemBase mouse event";
	//if (event->button() == Qt::LeftButton)
	//{
	//	emit openchatwidget(item->GetName());
	//}
}