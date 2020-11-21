#ifndef _QMSGLISTITEM_H_
#define _QMSGLISTITEM_H_

#include <QWidget>
#include <QItemBase.h>

class QMsgListItem : public QItemBase
{
	Q_OBJECT

public:
	QMsgListItem(QWidget* parent, QPixmap& avatar, QString& name, QString& remark);
	~QMsgListItem();

protected:
	void InitWindow(QPixmap& avatar, QString& name, QString& remark);
};

#endif //_QMSGLISTITEM_H_