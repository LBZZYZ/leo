#include "QMessageItem.h"

QMessageItem::QMessageItem(QWidget *parent, QPixmap* Head , QString Name , QString signature ,long long Id, ItemStyle style)
	: QWidget(parent)
{
	
	m_Id = Id;									//账号
	m_pHead = new QPushButton(this);			//头像
	m_style = style;							//窗口样式


	QPixmap pixmap("Resources/Head.png");	
	m_pHead->resize(pixmap.size());
	
	m_pHead->setMask(QBitmap(pixmap.mask()));
	if (Head != nullptr)
	{
		pixphead = *Head;
		Head->scaled(pixmap.size());
		QIcon Icon(*Head);
	}
	else
	{
		pixphead.load("Resources/QQimage.png");
		m_pHead->setIcon(QIcon(pixphead));
	}
	m_pHead->setIconSize(QSize(70,70));
	

	m_pHead->setGeometry(m_pHead->rect().topLeft().x()+10, m_pHead->rect().topLeft().y() + 6, pixmap.size().width(), pixmap.size().height());

	m_pHead->setFlat(true);

	//网名
	QFont font;
	font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
	font.setPointSize(14);
	
	m_pNote = nullptr;
	m_pName = Name;
	
	m_pNameLable = new QLabel(Name,this);
	m_pNameLable->setGeometry(m_pHead->rect().topLeft().x() + 10+55+10, m_pHead->rect().topLeft().y() + 8, 150, 30);
	m_pNameLable->setFont(font);
	m_pNameLable->setStyleSheet("background-color:rgb(0,0,0,0);");
	

	//个性签名
    m_pSignature =new QLabel(signature, this);
	m_pSignature->setGeometry(m_pHead->rect().topLeft().x() + 10 + 55 + 10, m_pHead->rect().topLeft().y() + 8+32, 200, 25);

	font.setPointSize(10);
	m_pSignature->setFont(font);
	m_pSignature->setStyleSheet("background-color:rgb(0,0,0,0);");

	//MessageItem窗口样式
	switch (style)
	{
	case QMessageItem::USUER:
		m_firmButton = NULL;
		break;
	case QMessageItem::SendVerification:
		m_firmButton = NULL;
		break;
	case QMessageItem::RecvVerification:
		m_firmButton = new QPushButton(QString("同意"), this);
		m_firmButton->setGeometry(m_pHead->rect().topLeft().x() + 10 + 55 + 10 +260, m_pHead->rect().topLeft().y() + 8 + 32, 50, 30);
		break;
	default:
		break;
	}

}

QMessageItem::~QMessageItem()
{

}


