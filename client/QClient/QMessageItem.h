#ifndef QMESSAGEITEM_H
#define QMESSAGEITEM_H
#include<QPushButton>
#include <QWidget>
#include <QBitmap>
#include <QPixmap>
#include <QLabel>
#include "Protocol/Protocol.h"
//好友列表 好友项控件

class QMessageItem : public QWidget
{
	Q_OBJECT

public:
	enum ItemStyle { USUER, SendVerification, RecvVerification };
	QMessageItem(QWidget *parent, QPixmap* pHead = nullptr, QString Name = "", QString signature = "", long long usrId = 0, ItemStyle style= USUER);
	~QMessageItem();

	//得到头像的pix图片
	QPixmap GetHeadPixmap();
	//拿到qq名字
	QString GetName();
	//个性签名
	QString GetSignatrue();

	//获取备注
	QString GetNote();
	//设置备注
	void  SetNote(QString);

	//设置头像
	void  SetHead(QPixmap);
	//设置名字
	void  SetName(QString);
     //设置个性签名
	void  SetSignatrue(QString);

	//qq名的lable
	QLabel*  GetNameLabel();
	//设置显示名备注或qq名
	void  setNameLabelText();

	//设置用户ID
	void SetUserId(long long);
	//获取用户ID
	long long GetUserId();

public:
	QPushButton* m_firmButton;

private:
	long long m_Id;					//用户ID
	QPixmap pixphead;				//用户头像pix
	QLabel*  m_pNameLable;			
	QLabel*  m_pSignature;			//用户签名
	QPushButton* m_pHead;			//头像控件
	QString m_pName;				//用户名
	QString m_pNote;				//备注
	ItemStyle m_style;				//MessageItem样式(USUER, SendVerification, RecvVerification)
	//QString* m_pHaedFilePath;

};
inline QPixmap QMessageItem::GetHeadPixmap()
{
	return pixphead;
}

inline QString QMessageItem::GetName()
{
	return m_pName;
}

inline void  QMessageItem::SetName(QString name)
{
	m_pName = name;
	setNameLabelText();
}

inline QString  QMessageItem::GetSignatrue()
{
	return m_pSignature->text();
}

inline void  QMessageItem::SetHead(QPixmap pix)
{
	m_pHead->setIcon(QIcon(pix));
}

inline void  QMessageItem::SetSignatrue(QString  signature)
{
	m_pSignature->setText(signature);
}

inline QString  QMessageItem::GetNote()
{	
	return  m_pNote;
}

inline void  QMessageItem::SetNote(QString  note)
{
	m_pNote = note;
	setNameLabelText();
}

inline QLabel* QMessageItem::GetNameLabel()
{
	return m_pNameLable;
}

inline void  QMessageItem::setNameLabelText()
{
	if (m_pNote.isEmpty())
		m_pNameLable->setText(m_pName);
	else
		m_pNameLable->setText(m_pNote);
}

inline void  QMessageItem::SetUserId(long long llv_Usrid)
{
	this->m_Id = llv_Usrid;
	
}

inline long long QMessageItem::GetUserId()
{
	return m_Id;
}
#endif // QMESSAGEITEM_H
