#include "Mediator.h"
#include "chat\qchatwindow.h"
#include "Protocol\Protocol.h"
#include  "qdebug.h"
#include <QMessagebOX>
#include "Net\UDPNet.h"
#include "Agency\AgencyUDP.h"
#include "UDPVerify\UDPVerify.h"
#include  "Agency\AgencyTCP.h"

#include <QDir>


Mediator::Mediator(QWidget *parent)
{
	//InitQClient(NULL);
	
	InitAllNet();
	InitQLogin();
	m_udpthread->start();
	m_tcpthread->start();
	bool ret;
	
	ret = connect(m_pUdpAgency, SIGNAL(DealSendMsgRs(char*, int)), this, SLOT(DealSendMsgSlot(char*, int)), Qt::BlockingQueuedConnection);
	if (false == ret)qDebug() << "Connect Error!";
	ret = connect(m_pUdpAgency, SIGNAL(DealAddFrdRqSignal(char*, int)), v, SLOT(DealUserAddRQSLot(char*, int)), Qt::BlockingQueuedConnection);		/*处理添加好友请求*/
	if (false == ret)qDebug() << "Connect Error!";
	ret = connect(m_pUdpAgency, SIGNAL(DealAddFrdRsSignal(char*, int)), v, SLOT(DealUserAddRsSLot(char *, int)), Qt::BlockingQueuedConnection);/*处理添加好友回复*/
	if (false == ret)qDebug() << "Connect Error!";
	ret = connect(m_pTcpAgency, SIGNAL(DealFriendListSignal(char*, int)), this, SLOT(DealFriendList(char *, int)), Qt::BlockingQueuedConnection);/*处理好友列表回复*/
	if (false == ret)qDebug() << "Connect Error!";
}

Mediator::~Mediator()
{
	if(!m_pUdpAgency)m_pUdpAgency->~CAgency();

	if(!m_pTcpAgency)m_pTcpAgency->~CAgency();

}

void Mediator::InitAllNet()
{
	//UDP
	m_pUdpAgency = new CUDPAgency();
	m_pUdpAgency->InitAgency();
	CUDPAgency::m_UDPverify->InitVerify();

	//TCP
	m_pTcpAgency = new CTCPAgency();
	m_pTcpAgency->InitAgency();


	//UDP线程
	m_udpthread = new UdpThread(m_pUdpAgency->m_pNet, this);
	//TCp线程
	m_tcpthread = new TcpThread(m_pTcpAgency->m_pNet, this);
}

void Mediator::InitQLogin()
{
	w = new QQLogin();
	w->show();


	//请求
	connect(w, SIGNAL(SendUdpRQ(const char*, int, int)), this, SLOT(DealUdpRQ(const char*, int, int)));
	connect(w, SIGNAL(SendTcpRQ(const char*, int)), this, SLOT(DealTcpRQ(const char*, int)));
	connect(m_pUdpAgency, SIGNAL(RegisetrSignal(bool)), this, SLOT(DealRegisterRS(bool)), Qt::BlockingQueuedConnection);
	connect(m_pTcpAgency, SIGNAL(LoginRSSignal(bool)), this, SLOT(DealLoginRS(bool)), Qt::BlockingQueuedConnection);
}

void Mediator::InitQClient(list<FRINENDLISTMSG> * pFriendlistmsg)
{
	
	v = new QClient(pFriendlistmsg,this);
	
	v->show();

	//---------------------------------------------连接信号与槽函数-----------------------------------------------------------------------
	//connect(v, SIGNAL(IsAdduiExist(bool)), this, SLOT(IsAdduiExisted(bool)));
	//connect(v, SIGNAL(deletefriendsignal(const char*, int)), this, SLOT(DealTcpRQ(const char*, int)));
	//connect(m_pTcpAgency, SIGNAL(DeletefrRSsignal(bool)), v->m_pFriendList, SLOT(DealDeletefrslot(bool)), Qt::BlockingQueuedConnection);
	connect(v->m_pFriendList, SIGNAL(openchatwidget(QString)), this, SLOT(initchatwidget(QString)));
	//connect(v, SIGNAL(SendAddFrdRsSignal(const char*, int, int)), this, SLOT(DealUdpRQ(const char*, int, int)));


}


/*初始化聊天窗口*/
void Mediator::initchatwidget(QString name)//初始化聊天窗口
{
	 
	//v->ui.widget = new QChatWindow();
	//v->ui.widget->move(430,50);
	//v->ui.widget->show();

	//connect(v->ui.widget, SIGNAL(sendchatmsgsignal(const char*, int, int)), this, SLOT(DealUdpRQ(const char*, int, int)));

}


void Mediator::LoginFail()
{

	QMessageBox message(QMessageBox::Information, QString("提示"), QString("登录失败"), QMessageBox::Ok);
	int ret = message.exec();
	if (ret == QMessageBox::RejectRole || QMessageBox::AcceptRole)
	{
		w->show();
		return;
	}
}

void Mediator::DealTcpRQ(const char*rq, int nSendLen)//处理Tcp的请求
{
	qDebug() << userId;
	m_pTcpAgency->GetNet()->SendTCPData((const char*)rq, nSendLen);
}

void Mediator::DealUdpRQ(const char* rq, int pack, int nSendLen)//处理udp请求
{
	CUDPAgency::m_UDPverify->AddVerify((char*)rq, pack, nSendLen);
	m_pUdpAgency->GetNet()->SendUDPData(inet_addr(IP), (const char*)rq, nSendLen);
}

void Mediator::DealRegisterRS(bool result)//处理注册回复
{
	if (result)
	{
		QMessageBox message(QMessageBox::Information, QString("提示"), QString("注册成功"), QMessageBox::Ok);
		int ret = message.exec();
		if (ret == QMessageBox::RejectRole || QMessageBox::AcceptRole)
		{
			//w->turnPage2();
			return;
		}
	}
	else
	{
		QMessageBox message(QMessageBox::Information, QString("提示"), QString("注册失败"), QMessageBox::Ok);
		
		return;
	}

}

void Mediator::DealLoginRS(bool result)
{
	if (result)
	{
		this->GetFriendList();				//登录成功，首先向服务器请求获取好友列表
		

		w->hide();
		/*
		QDir dir;
		if (!dir.exists("./userData"))
			dir.mkdir("userData");
		if (!dir.exists(QString("./userData/%1").arg(userId)))
			dir.mkdir(QString("./userData/%1").arg(userId));
		QString  str(QString("./userData/%1").arg(userId));
		//qDebug() << str;
		if (!dir.setCurrent(str))
		{
			qDebug() << "设置失败";
		}
		qDebug() << dir.path() << dir.currentPath();
		QFile pf;
		if (pf.exists(QString("%1").arg(userId)))//文件是否存在
		{
			qDebug() << QObject::tr("文件存在") << pf.ExistingOnly;
			pf.close();
			return;
		}
		pf.setFileName(QString("%1").arg(userId));
		if (!pf.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
		{
			qDebug() << tr("打开失败") << pf.OpenError;
			pf.close();
			return;
		}
		char id[20] = { 0 };
		Qstringtochar(id, QString("%1").arg(userId), 20);
		pf.write(id, 20);
		pf.write("/n");
		pf.close();
		*/
	}
	else
	{
		userId = 0;
		LoginFail();
	}

}

void Mediator::IsAdduiExisted(bool result)
{
	if (result)
	{
		connect(v->addui, SIGNAL(sendsearchsignal(const char*, int)), this, SLOT(DealTcpRQ(const char*, int)));
		connect(m_pTcpAgency, SIGNAL(SerchRsSiganl(STRU_SEARCH_USER_RS*)), v->addui, SLOT(DealserchRS(STRU_SEARCH_USER_RS*)), Qt::BlockingQueuedConnection);
		bool ret = connect(v->addui, SIGNAL(SendAddFrdRqSignal(const char*, int, int)), this, SLOT(DealUdpRQ(const char*, int, int)));	/*发送添加好友请求*/
		if (ret == false)
		{
			QDialog dlg(nullptr, Qt::Dialog | Qt::WindowCloseButtonHint);
			dlg.show();

		}



		connect(v->addui, SIGNAL(AddMsgToMsgListSignal(long long, const char*, int)), v, SLOT(DealAddMsgToMsgListSignal(long long, const char*, int)));



	}
	else
	{
		disconnect(v->addui, SIGNAL(sendsearchsignal(const char*, int)), this, SLOT(DealTcpRQ(const char*, int)));
		disconnect(m_pTcpAgency, SIGNAL(SerchRsSiganl(STRU_SEARCH_USER_RS*)), v->addui, SLOT(DealserchRS(STRU_SEARCH_USER_RS*)));
		//disconnect(v->addui, SIGNAL(SendAddFrdRsSignal(const char*, int, int)), this, SLOT(DealUdpRQ(const char*, int, int)));
		//disconnect(v->addui, SIGNAL(SendAddFrdRqSignal(const char*, int, int)), this, SLOT(DealUdpRQ(const char*, int, int)));			/*发送添加好友请求*/
		//disconnect(m_pUdpAgency, SIGNAL(DealAddFrdRqSignal(const char*, int)), this, SLOT(DealUserAddRQSLot(const char*, int)));		/*处理添加好友请求*/
		//disconnect(m_pUdpAgency, SIGNAL(DealAddFrdRsSignal(bool)), v->m_pFriendList, SLOT(DealUserAddRSSLot(bool)));					/*处理添加好友回复*/

	}

}
void Mediator::DealSendMsgSlot(char* pszBuffer, int nLen)
{
	if (NULL == pszBuffer || nLen <= 0)
	{
		qDebug() << "DealSendMsgSlot Error!";
		return;
	}

	/*将收到的消息写入文件*/
	STRU_SEND_MSG_RS *lpv_Msg = (STRU_SEND_MSG_RS*)pszBuffer;
	char FileName[12] = { 0 };
	itoa(lpv_Msg->llID, FileName, 10);
	QFile MsgFile(FileName);
	MsgFile.open(QFile::WriteOnly | QFile::Append);
	QTextStream writer(&MsgFile);
	writer << lpv_Msg->szText << endl;
	MsgFile.close();


}



/*********************************************
函数名       : DealFriendList
函数功能描述 : 处理服务端返回的好友列表
函数参数     : char * pszBuffer, int nLen
函数返回值   : void
函数作者     : 李柄志
函数创建日期 : 2019.07.23
函数修改日期 : *
修改人       : *
修改原因     : *
版本         : 1.0
历史版本     : 无
*********************************************/
void Mediator::DealFriendList(char * pszBuffer, int nLen)
{
	if (pszBuffer == NULL || nLen <= 0)
		return;
	STRU_GET_FRIENDLIST_RS *lpv_Getfriendlistrs = (STRU_GET_FRIENDLIST_RS*)pszBuffer;
	InitQClient(lpv_Getfriendlistrs->pFriendList);
}


/*********************************************
函数名       : GetFriendList
函数功能描述 : 向服务端获取登录用户的好友列表
函数参数     : void
函数返回值   : void
函数作者     : 李柄志
函数创建日期 : 2019.07.23
函数修改日期 : *
修改人       : *
修改原因     : *
版本         : 1.0
历史版本     : 无
*********************************************/
void Mediator::GetFriendList(void)
{
	//1.构造获取好友列表请求包
	STRU_GET_FRIENDLIST_RQ lsv_Getfrinedlistrq;
	lsv_Getfrinedlistrq.packtype = PROTOCOL_GET_FRIENDLIST_RQ;
	lsv_Getfrinedlistrq.llUserID = userId;
	if (false == m_pTcpAgency->GetNet()->SendTCPData((char*)&lsv_Getfrinedlistrq, sizeof(STRU_GET_FRIENDLIST_RQ)))
		return;

}


