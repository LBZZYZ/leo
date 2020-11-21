#ifndef _QITEMBASE_H_
#define _QITEMBASE_H_

#include <QWidget>
#include <QLabel>
#include "QAvatar.h"

#define ITEM_OK      0
#define ITEM_ERROR  -1
#define ITEM_INVALID 1

typedef int ITEM_RESULT;

class QItemBase : public QWidget
{
	Q_OBJECT

public:
	QItemBase(QWidget *parent);
	~QItemBase();

public:
	QAvatar GetAvatar();
	QString GetName();
	QString GetRemark();
	long long GetUserId();

	ITEM_RESULT ItemSetAvatar(QPixmap* avatar);
	ITEM_RESULT ItemSetName(QString name);
	ITEM_RESULT ItemSetRemark(QString remark);

protected:

	long long m_UserId;
	QAvatar *m_Avatar;
	QString m_Name;
	QString m_Remark;
};

inline QAvatar QItemBase::GetAvatar()
{
	return m_Avatar;
}

inline QString QItemBase::GetName()
{
	return m_Name;
}

inline QString QItemBase::GetRemark()
{
	return m_Remark;
}

inline long long QItemBase::GetUserId()
{
	return m_UserId;
}
#endif //_QITEMBASE_H_