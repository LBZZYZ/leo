#include "QMsgListItem.h"
#include <QLabel>
QMsgListItem::QMsgListItem(QWidget* parent, QPixmap& avatar, QString& name, QString& remark)
	:QItemBase(parent)
{
	 m_Name = name;
	 m_Remark = remark;
	 InitWindow(avatar, name, remark);
}

QMsgListItem::~QMsgListItem()
{
	delete m_Avatar;
	m_Avatar = nullptr;
}

void QMsgListItem::InitWindow(QPixmap& avatar, QString& name, QString& remark)
{
	ItemSetAvatar(&avatar);
	if (remark == "")
	{
		ItemSetName(name);
	}
	else
	{
		ItemSetRemark(remark);
	}

}
