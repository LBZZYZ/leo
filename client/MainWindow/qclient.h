#ifndef _QCLIENT_H_
#define _QCLIENT_H_

#include <QWidget>
#include <list>
#include <map>
#include "AddFriendWindow.h"

#include "QPersonList.h"
#include "QMsgListItem.h"
#include "ui_client.h"

#define CLIENT_OK      0
#define CLIENT_ERROR  -1
#define CLIENT_INVALID 1

typedef int CLIENT_RESULT;



class MainWindow : public QWidget
{
	Q_OBJECT

public slots:
	void InitAddFriendUi();
	void closed();
	void DealAddMsgToMsgList(long long, const char*, int);
	void DealUserAddRQSLot(char* pszBuffer, int nLen);
	void SendAddFrdRsSlot();
	void DealUserAddRsSLot(char* pszBuffer, int nLen);
	void on_pushButton_SendMessage_clicked();
	void editwordcount();

signals:
	void IsAdduiExist(bool);
	void SendAddFrdRsSignal(const char*, int, int);


private:
	MainWindow(list<FRINENDLISTMSG>*, QObject* parent = 0);
	MainWindow();
	~MainWindow();

protected:
	void dealMessage(QNChatMessage* messageW, QListWidgetItem* item, QString text, QString time, QNChatMessage::User_Type type);
	void dealMessageTime(QString curMsgTime);
	void InitWindow(list<FRINENDLISTMSG>*);
	void loadStyleSheet(const QString& sheetName);

	CLIENT_RESULT UiInitMessageList(void);
	CLIENT_RESULT UiInitFriendList(list<FRINENDLISTMSG>* pFriendlistmsg);

	CLIENT_RESULT GetMsgList(long long userid, int& msgnum, QList<STRU_MSG_LIST>& msglist);
	CLIENT_RESULT GetUsrRemark(long long usrid, QString& remark);
	CLIENT_RESULT GetLastOfflineMsg(long long usrid, QString& msg);
	CLIENT_RESULT GetUsrAvatar(long long usrid, QPixmap& avatar);
	CLIENT_RESULT GetUsrName(long long usrid, QString& name);
	CLIENT_RESULT ConnectSignalSlot(void);

public:
	static MainWindow* GetInstance();
	static MainWindow* DeleteInstance();

private:
	static MainWindow* mainwindow;
	AddFriendWindow* addfriends_window;
	QPersonList* m_pFriendList;
	map<long long, QListWidgetItem*> m_UsrIdToQListWidgetItem;

	typedef struct STRU_MSG_LIST
	{
		QPixmap avatar;
		QString name;
		QString remark;
		QString msg;

	}STRU_MSG_LIST;
	QList<STRU_MSG_LIST> msglist;

private:
	Ui::MainWindow ui;

};

#endif // _QCLIENT_H_
