#include "QFrdListItem.h"
#include <QLabel>
#include <QDebug>
QFrdListItem::QFrdListItem(QWidget *parent, QPixmap* avatar , QString name , QString signature ,long long userid, EN_ITEM_STYLE style)
	: QItemBase(parent)
{
	m_style = style;

	this->ItemSetAvatar(avatar);
	this->ItemSetName(name);
	this->ItemSetSignatrue(signature);

	switch (style)
	{
	case E_ITEM_USUER:
		m_firmButton = NULL;
		break;
	case E_ITEM_SENDVERIFICATION:
		m_firmButton = NULL;
		break;
	case E_ITEM_RECVVERIFICATION:
		m_firmButton = new QPushButton(QString("同意"), this);
		m_firmButton->setGeometry(m_Avatar->rect().topLeft().x() + 10 + 55 + 10 +260, m_Avatar->rect().topLeft().y() + 8 + 32, 50, 30);
		break;
	default:
		break;
	}

}

QFrdListItem::~QFrdListItem()
{

}

ITEM_RESULT QFrdListItem::ItemSetSignatrue(QString signature)
{
	if (signature == "")
	{
		qDebug() << "ItemSetSignatrue signature empty";
		return ITEM_INVALID;
	}
	m_pSignature = new QLabel(signature, this);
	m_pSignature->setGeometry(m_Avatar->rect().topLeft().x() + 10 + 55 + 10, m_Avatar->rect().topLeft().y() + 8 + 32, 200, 25);

	QFont font;
	font.setPointSize(10);
	m_pSignature->setFont(font);
	m_pSignature->setStyleSheet("background-color:rgb(0,0,0,0);");
	return ITEM_OK;
}




