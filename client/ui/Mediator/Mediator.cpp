#include "Mediator.h"

Mediator::Mediator(QWidget *parent)
{
	//UiInitMainWindow(NULL);
	
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
	if(!m_pUdpAgency)m_pUdpAgency->~Agency();

	if(!m_pTcpAgency)m_pTcpAgency->~Agency();

}

void Mediator::InitAllNet()
{
	//UDP
	m_pUdpAgency = new CUDPAgency();
	m_pUdpAgency->Init();
	CUDPAgency::m_UDPverify->InitVerify();

	//TCP
	m_pTcpAgency = new EventDispatch();
	m_pTcpAgency->Init();


	//UDP线程
	m_udpthread = new UdpThread(m_pUdpAgency->net, this);
	//TCp线程
	m_tcpthread = new TcpThread(m_pTcpAgency->net, this);
}

void Mediator::InitQLogin()
{
	w = new Login();
	w->show();


	//请求
	connect(w, SIGNAL(SendUdpRQ(const char*, int, int)), this, SLOT(DealUdpRQ(const char*, int, int)));
	connect(m_pUdpAgency, SIGNAL(RegisetrSignal(bool)), this, SLOT(DealRegisterRS(bool)), Qt::BlockingQueuedConnection);
	connect(m_pTcpAgency, SIGNAL(LoginRSSignal(bool)), this, SLOT(DealLoginRS(bool)), Qt::BlockingQueuedConnection);
}

void Mediator::UiInitMainWindow(list<FRINENDLISTMSG> * pFriendlistmsg)
{
	mainwindow = MainWindow::GetInstance();
	mainwindow->show();
	connect(mainwindow->m_pFriendList, SIGNAL(openchatwidget(QString)), this, SLOT(initchatwidget(QString)));
}


/*初始化聊天窗口*/
void Mediator::initchatwidget(QString name)//初始化聊天窗口
{

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
			//w->TurnToLoginWindow();
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
		connect(v->addfriends_window, SIGNAL(SearchFriendsRequestSignal(const char*, int)), this, SLOT(DealTcpRQ(const char*, int)));
		connect(m_pTcpAgency, SIGNAL(SerchRsSiganl(STRU_SEARCH_USER_RS*)), v->addfriends_window, SLOT(DealserchRS(STRU_SEARCH_USER_RS*)), Qt::BlockingQueuedConnection);
		bool ret = connect(v->addfriends_window, SIGNAL(SendAddFriendRequest(const char*, int, int)), this, SLOT(DealUdpRQ(const char*, int, int)));	/*发送添加好友请求*/
		if (ret == false)
		{
			QDialog dlg(nullptr, Qt::Dialog | Qt::WindowCloseButtonHint);
			dlg.show();

		}



		connect(v->addfriends_window, SIGNAL(AddMsgToMsgList(long long, const char*, int)), v, SLOT(DealAddMsgToMsgList(long long, const char*, int)));



	}
	else
	{
		disconnect(v->addfriends_window, SIGNAL(SearchFriendsRequestSignal(const char*, int)), this, SLOT(DealTcpRQ(const char*, int)));
		disconnect(m_pTcpAgency, SIGNAL(SerchRsSiganl(STRU_SEARCH_USER_RS*)), v->addfriends_window, SLOT(DealserchRS(STRU_SEARCH_USER_RS*)));
		//disconnect(v->addfriends_window, SIGNAL(SendAddFrdRsSignal(const char*, int, int)), this, SLOT(DealUdpRQ(const char*, int, int)));
		//disconnect(v->addfriends_window, SIGNAL(SendAddFriendRequest(const char*, int, int)), this, SLOT(DealUdpRQ(const char*, int, int)));			/*发送添加好友请求*/
		//disconnect(m_pUdpAgency, SIGNAL(DealAddFrdRqSignal(const char*, int)), this, SLOT(DealUserAddRQSLot(const char*, int)));		/*处理添加好友请求*/
		//disconnect(m_pUdpAgency, SIGNAL(DealAddFrdRsSignal(bool)), v->m_pFriendList, SLOT(DealUserAddRSSLot(bool)));					/*处理添加好友回复*/

	}

}



