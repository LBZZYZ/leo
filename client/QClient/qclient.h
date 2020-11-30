#ifndef _QCLIENT_H_
#define _QCLIENT_H_

#include "qmenu.h"
#include "QPersonList.h"
#include <QWidget>
#include "ui_qclient.h"
#include "QAddFrd.h"
#include "qlistwidget.h"
#include <map>
#include "qnchatmessage.h"
#include <QMouseEvent>
#include <QAvatar.h>
/*
* UI Widget
* textEdit_MessageInput
* pushButton_SendMessage
* listWidget_ChatList
* 
* m_pMessageListWidget
* 
* 
*/

#define CLIENT_OK      0
#define CLIENT_ERROR  -1
#define CLIENT_INVALID 1

typedef int CLIENT_RESULT;



class QClient : public QWidget
{
	Q_OBJECT

public:
	QClient(list<FRINENDLISTMSG> *, QObject *parent = 0);
	~QClient();

public:
	QAddFrd* addui;
	QPersonList* m_pFriendList;									//好友列表指针

protected:
	QMenu* Menu;												 //底部菜单
	QAction* action[4];											 //菜单动作
	QPoint last;
	map<long long, QListWidgetItem*> m_UsrIdToQListWidgetItem;


	typedef struct STRU_MSG_LIST
	{
		QPixmap avatar;
		QString name;
		QString remark;
		QString msg;

	}STRU_MSG_LIST;
	QList<STRU_MSG_LIST> msglist;
protected:
	void dealMessage(QNChatMessage* messageW, QListWidgetItem* item, QString text, QString time, QNChatMessage::User_Type type);
	void dealMessageTime(QString curMsgTime);
	void InitWindow(list<FRINENDLISTMSG>*);
	void loadStyleSheet(const QString& sheetName);

	CLIENT_RESULT UiInitMessageList(void);
	CLIENT_RESULT UiInitFriendList(list<FRINENDLISTMSG>* pFriendlistmsg);

	CLIENT_RESULT GetMsgList(long long userid, int& msgnum, QList<STRU_MSG_LIST>& msglist);
	CLIENT_RESULT GetUsrRemark(long long usrid, QString& remark);
	CLIENT_RESULT GetLastOfflineMsg(long long usrid, QString &msg);
	CLIENT_RESULT GetUsrAvatar(long long usrid, QPixmap& avatar);
	CLIENT_RESULT GetUsrName(long long usrid, QString &name);
	
	CLIENT_RESULT ConnectSignalSlot(void);
public slots:
	void InitAddFriendUi();
	void qqclientclose();
	void adduiclosed();
	void DealAddMsgToMsgListSignal(long long, const char*, int);
	void DealUserAddRQSLot(char* pszBuffer, int nLen);
	void SendAddFrdRsSlot();
	void DealUserAddRsSLot(char* pszBuffer, int nLen);
	void on_pushButton_SendMessage_clicked();
	void editwordcount();

signals:
	void IsAdduiExist(bool);
	void SendAddFrdRsSignal(const char*, int, int);

private:
	Ui::QClient ui;
};

#endif // _QCLIENT_H_
