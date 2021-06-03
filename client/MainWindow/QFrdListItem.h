#ifndef _QFRDLISTITEM_H_
#define _QFRDLISTITEM_H_

#include<QPushButton>
#include <QWidget>
#include <QBitmap>
#include <QPixmap>
#include <QLabel>

#include "Protocol/Protocol.h"
#include "QItemBase.h"

typedef enum
{
	E_ITEM_USUER, 
	E_ITEM_SENDVERIFICATION, 
	E_ITEM_RECVVERIFICATION

}EN_ITEM_STYLE;

class QFrdListItem : public QItemBase
{
	Q_OBJECT

public:
	
	QFrdListItem(QWidget *parent, QPixmap* avatar = nullptr, QString name = "", QString signature = "", long long userid = 0, EN_ITEM_STYLE style = E_ITEM_USUER);
	~QFrdListItem();

	QString GetSignatrue(void);
	ITEM_RESULT SetSignatrue(QString);
	ITEM_RESULT ItemSetSignatrue(QString);
private:	
	QString m_Signature;
	QLabel*  m_pSignature;	
	QPushButton* m_firmButton;
	EN_ITEM_STYLE m_style;
};

inline QString  QFrdListItem::GetSignatrue()
{
	return m_Signature;
}

inline ITEM_RESULT QFrdListItem::SetSignatrue(QString  signature)
{
	m_Signature = signature;
	m_pSignature->setText(signature);
	return ITEM_OK;
}

#endif //_QFRDLISTITEM_H_
