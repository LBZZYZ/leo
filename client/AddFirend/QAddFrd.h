#ifndef QADDFRD_H
#define QADDFRD_H

#include <QWidget>
#include "ui_QAddFrd.h"
#include "Protocol\Protocol.h"
#include <QMenu>
class QAddFrd : public QWidget
{
	Q_OBJECT

public:
	QAddFrd(QWidget *parent = 0);
	~QAddFrd();
	void  closeEvent(QCloseEvent * e);
protected:
	bool eventFilter(QObject *obj, QEvent *event) override;
	//void contextMenuEvent(QContextMenuEvent * event) override;
public	slots:
	void searchfr();
	void DealserchRS(STRU_SEARCH_USER_RS*);
	void AddFriendSlot();
	
signals:
		void adduiclose();
signals:
		void sendsearchsignal(const char*, int);
signals:
		void SendAddFrdRqSignal(const char*,int, int);
signals:
	void AddMsgToMsgListSignal(long long,const char*,int);
private:
	Ui::QAddFrd ui;
	QMenu* m_pmenu;
};

#endif // QADDFRD_H
