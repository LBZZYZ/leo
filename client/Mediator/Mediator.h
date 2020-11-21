#ifndef MEDIATOR_H
#define MEDIATOR_H


#include <QObject>
#include "qqlogin.h"
#include "Agency\Agency.h"
#include "NetThread\UdpThread.h"
#include "NetThread\TcpThread.h"
#include "QClient\qclient.h"
#include "signup.h"
class Mediator:public QObject
{
	Q_OBJECT
		
public:
	Mediator(QWidget *parent=0);
	~Mediator();
public:
	QQLogin* w;
	QClient* v;
	CAgency* m_pUdpAgency;//Udp网络中介
	CAgency* m_pTcpAgency;//
	UdpThread* m_udpthread;
	TcpThread* m_tcpthread;
	void InitQClient(list<FRINENDLISTMSG> *);
public slots:
    
	void DealUdpRQ(const char*,int,int);		//处理Udp的请求
	void DealTcpRQ(const char*, int);			//处理Tcp的请求
	void initchatwidget(QString);				//初始化聊天窗口
	void DealSendMsgSlot(char*, int);
	void GetFriendList(void);					//向服务器获取好友列表
   // void DealLoginRS(STRU_LOGIN_RS*);//处理登入回复
	void DealRegisterRS(bool);
	void DealLoginRS(bool);//处理登入回复
	void IsAdduiExisted(bool);//窗口是否存在
	void DealFriendList(char *pszBuffer, int nLen);

signals:
	//void SendloginQS(STRU_LOGIN_RS*);
private:
	void InitQLogin();
	void LoginFail();
	void InitAllNet();
};

#endif // MEDIATOR_H
