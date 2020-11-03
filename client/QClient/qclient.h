#ifndef QCLIENT_H
#define QCLIENT_H
#include "qmenu.h"
#include "QPersonList.h"
#include <QWidget>
#include "ui_qclient.h"
#include "QAddFrd.h"
#include "qlistwidget.h"
#include <map>		/*用户ID和消息小窗口的映射*/
#include "qnchatmessage.h"
#include <QMouseEvent>
class QClient : public QWidget
{
	Q_OBJECT

public:
	QClient(list<FRINENDLISTMSG> *, QObject *parent = 0);
	~QClient();
    //加载窗口
	void InitWindow(list<FRINENDLISTMSG> *);
	//记载qss样式函数
	void loadStyleSheet(const QString & sheetName);

	
public slots:
	void InitAddFriendUi();
	void qqclientclose();
	void adduiclosed();
	void DealAddMsgToMsgListSignal(long long, const char*, int);
	void DealUserAddRQSLot(char *pszBuffer, int nLen);
	void SendAddFrdRsSlot();
	void DealUserAddRsSLot(char *pszBuffer,int nLen);
	
signals:
	void IsAdduiExist(bool);
	void SendAddFrdRsSignal(const char*,int,int);
	
public slots:
	void on_pushButton_SendMessage_clicked();
	void editwordcount();
	
private:
	Ui::QClient ui;
	
protected:
	
	QMenu* Menu;												 //底部菜单
	QAction* action[4];											 //菜单动作

public:
	QAddFrd* addui;
	QPersonList* m_pFriendList;									//好友列表指针
	map<long long, QListWidgetItem*> m_UsrIdToQListWidgetItem;

	void dealMessage(QNChatMessage* messageW, QListWidgetItem* item, QString text, QString time, QNChatMessage::User_Type type);

	void dealMessageTime(QString curMsgTime);


protected:
	void mousePressEvent(QMouseEvent* e);
	void mouseMoveEvent(QMouseEvent* e);
	void mouseReleaseEvent(QMouseEvent* e);
private:
	QPoint last;
};

#endif // QCLIENT_H
