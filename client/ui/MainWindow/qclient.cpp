﻿#include "qclient.h"

MainWindow* MainWindow::mainwindow = nullptr;

MainWindow::MainWindow(list<FRINENDLISTMSG> * pFriendlistmsg, QObject *parent)
{
	ui.setupUi(this);

	addfriends_window = nullptr;
	InitWindow(pFriendlistmsg);
	ConnectSignalSlot();
}

void MainWindow::InitWindow(list<FRINENDLISTMSG>* pFriendlistmsg)
{
	setAttribute(Qt::WA_DeleteOnClose);

	this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint);

	ui.listWidget_ChatList->setFrameShape(QListWidget::NoFrame);
	ui.m_pMessageListWidget->setFrameShape(QListWidget::NoFrame);
	ui.tabWidget->setDocumentMode(true);

	if (CLIENT_ERROR == this->UiInitMessageList())
	{
		qDebug() << "Function UiInitMessageList error";
	}
	if (CLIENT_ERROR == this->UiInitFriendList(pFriendlistmsg))
	{
		qDebug() << "Function UiInitFriendList error";
	}
}

CLIENT_RESULT MainWindow::UiInitMessageList(void)
{
	//get local message list
	int msgnum = 1;

	this->GetMsgList(0/*userid*/, msgnum, msglist);

	//draw message list using local data
	QListWidgetItem* ITEM = new QListWidgetItem[msgnum]();
	QSize size = ITEM[0].sizeHint();

	for (int index = 0; index < msgnum; ++index)
	{
		QItemBase* item = new QMsgListItem(this, msglist[index].avatar, msglist[index].name, msglist[index].remark);
		ui.m_pMessageListWidget->addItem(&ITEM[index]);
		ui.m_pMessageListWidget->setItemWidget(&ITEM[index], item);
	}

	return CLIENT_OK;
}

CLIENT_RESULT MainWindow::UiInitFriendList(list<FRINENDLISTMSG>* pFriendlistmsg)
{
	m_pFriendList = new QPersonList(pFriendlistmsg, ui.tabWidget->widget(1));
	m_pFriendList->installEventFilter(ui.tabWidget->widget(1));

	return CLIENT_OK;
}

CLIENT_RESULT MainWindow::ConnectSignalSlot(void)
{
	connect(ui.textEdit_MessageInput, &QTextEdit::textChanged, this, &MainWindow::editwordcount);
	connect(ui.m_btnMin, &QPushButton::pressed, this, &MainWindow::showMinimized);
	connect(ui.m_btnMax, &QPushButton::pressed, this, &MainWindow::showMaximized);
	connect(ui.m_btnClose, &QPushButton::pressed, this, &MainWindow::close);

	return CLIENT_OK;
}

MainWindow::~MainWindow()
{
	if (m_pFriendList != nullptr)
	{
		delete m_pFriendList;
		m_pFriendList = nullptr;
	}
}



void  MainWindow::editwordcount()
{
	QString textContent = ui.textEdit_MessageInput->toPlainText();

	int length = textContent.toUtf8().size();
	int maxLength = 480;

	if (length > maxLength) 
	{
		QTextCursor cursor = ui.textEdit_MessageInput->textCursor();
		cursor.movePosition(QTextCursor::End);
		if (cursor.hasSelection()) {
			cursor.clearSelection();
		}
		cursor.deletePreviousChar();
		ui.textEdit_MessageInput->setTextCursor(cursor);
	}
}

void MainWindow::loadStyleSheet(const QString &sheetName)
{
	QFile file(sheetName);
	file.open(QFile::ReadOnly);
	if (file.isOpen())
	{
		QString styleSheet = this->styleSheet();
		styleSheet += QLatin1String(file.readAll());
	this->setStyleSheet(styleSheet);
	}
}

void MainWindow::InitAddFriendUi()
{
	addfriends_window = AddFriendWindow::GetInstance();
	addfriends_window->show();
	emit IsAdduiExist(true);
}

void MainWindow::closed()
{
	emit IsAdduiExist(false);

	addfriends_window->close();
	addfriends_window = nullptr;
}

/*把等待验证的信息放到消息列表中A*/
void MainWindow::DealAddMsgToMsgList(long long ID, const char* namestr, int type)
{

	m_UsrIdToQListWidgetItem[ID] = new QListWidgetItem();
	QFrdListItem *pWidget = new QFrdListItem(this, nullptr, QString(namestr), QString("添加请求已发送。"), ID, E_ITEM_SENDVERIFICATION);
	QSize size = m_UsrIdToQListWidgetItem[ID]->sizeHint();
	m_UsrIdToQListWidgetItem[ID]->setSizeHint(QSize(size.width(), 72));
	ui.m_pMessageListWidget->addItem(m_UsrIdToQListWidgetItem[ID]);
	pWidget->setSizeIncrement(size.width(), 72);
	ui.m_pMessageListWidget->setItemWidget(m_UsrIdToQListWidgetItem[ID], pWidget);
	
}

/*处理添加好友请求*///B
void MainWindow::DealUserAddRQSLot(char *pszBuffer, int nLen)
{
	/*把添加好友请求的信息放到消息列表中*/
	STRU_USER_ADD_RQ *lpv_Usraddrq = (STRU_USER_ADD_RQ*)pszBuffer;
	long long llv_SenderId = lpv_Usraddrq->llUserID;
	m_UsrIdToQListWidgetItem[llv_SenderId] = new QListWidgetItem();
	
	QFrdListItem* widget = new QFrdListItem(this, nullptr,QString("280761575"), QString("想要添加你为好友"), lpv_Usraddrq->llUserID, E_ITEM_RECVVERIFICATION);
	QSize size = m_UsrIdToQListWidgetItem[llv_SenderId]->sizeHint();
	m_UsrIdToQListWidgetItem[llv_SenderId]->setSizeHint(QSize(size.width(), 72));
	ui.m_pMessageListWidget->addItem(m_UsrIdToQListWidgetItem[llv_SenderId]);
	widget->setSizeIncrement(size.width(), 72);
	ui.m_pMessageListWidget->setItemWidget(m_UsrIdToQListWidgetItem[llv_SenderId], widget);


	return;
}

/*用户点击同意添加，发送添加好友回复包给服务器，同时把添加好友请求的消息从消息列表中删除，并将其添加的用户添加到他的好友列表中*/
void  MainWindow::SendAddFrdRsSlot()
{
	QPoint point = ui.m_pMessageListWidget->mapFromGlobal(QCursor::pos());
	QListWidgetItem *p;
	if (NULL == (p = ui.m_pMessageListWidget->itemAt(point)))
	{
		qDebug() << "itemAt";
	}
	int nRow;
	nRow = ui.m_pMessageListWidget->row(p);
	QFrdListItem * pWidget = static_cast<QFrdListItem*>(ui.m_pMessageListWidget->itemWidget(p));
	long long llv_SenderId = pWidget->GetUserId();
	STRU_USER_ADD_RS *rs = new STRU_USER_ADD_RS;
	//test
	rs->packtype = PROTOCOL_USER_ADD_RS;
	rs->result = SUCCEED;
	rs->llSenderID = userId;
	rs->llReceiverID = pWidget->GetUserId();
	rs->nPackNum = packId;
	qDebug() << QCursor::pos() << "message";
	qDebug() << "鼠标" << ui.m_pMessageListWidget->mapFromGlobal(QCursor::pos());
	qDebug() << "userid:" << pWidget->GetUserId();
	emit SendAddFrdRsSignal((const char*)rs,rs->nPackNum,sizeof(STRU_USER_ADD_RS));



	/*把客户端B的同意窗口改成聊天窗口*/
	//1.删除QFrdListItem
	delete pWidget;
	//2.添加新的QFrdListItem
	m_UsrIdToQListWidgetItem[llv_SenderId]->~QListWidgetItem();
	m_UsrIdToQListWidgetItem[llv_SenderId] = new QListWidgetItem;
	QFrdListItem* widget = new QFrdListItem(this, nullptr, QString("aa"), QString("可以开始聊天了"), llv_SenderId, E_ITEM_USUER);
	QSize size = m_UsrIdToQListWidgetItem[llv_SenderId]->sizeHint();
	m_UsrIdToQListWidgetItem[llv_SenderId]->setSizeHint(QSize(size.width(), 72));
	ui.m_pMessageListWidget->addItem(m_UsrIdToQListWidgetItem[llv_SenderId]);
	widget->setSizeIncrement(size.width(), 72);
	ui.m_pMessageListWidget->setItemWidget(m_UsrIdToQListWidgetItem[llv_SenderId], widget);

}

/*处理添加好友回复包A*/
void MainWindow::DealUserAddRsSLot(char *pszBuffer, int nLen)
{
	if (pszBuffer == NULL || nLen <= 0)
	{
		qDebug() << "DealUserAddRSSlot";
		return;
	}
	STRU_USER_ADD_RS *lpv_Useraddrs = (STRU_USER_ADD_RS*)pszBuffer;
	long long llv_SenderId = lpv_Useraddrs->llSenderID;
	if (lpv_Useraddrs->result == SUCCEED)
	{
		/*把ReadyFriend中的信息写入好友信息表*/
		QFrdListItem * pWidget = static_cast<QFrdListItem*>(ui.m_pMessageListWidget->itemWidget(m_UsrIdToQListWidgetItem[llv_SenderId]));
		delete pWidget;
		pWidget = NULL;
		m_UsrIdToQListWidgetItem[llv_SenderId]->~QListWidgetItem();
		/*把消息列表中的等待验证变成与此人的聊天消息*/
		m_UsrIdToQListWidgetItem[llv_SenderId] = new QListWidgetItem;
		QFrdListItem *widget = new QFrdListItem(this, nullptr, QString("280761575"), QString("可以开始聊天了"), llv_SenderId, E_ITEM_USUER);
		QSize size = m_UsrIdToQListWidgetItem[llv_SenderId]->sizeHint();
		m_UsrIdToQListWidgetItem[llv_SenderId]->setSizeHint(QSize(size.width(), 72));
		ui.m_pMessageListWidget->addItem(m_UsrIdToQListWidgetItem[llv_SenderId]);
		widget->setSizeIncrement(size.width(), 72);
		ui.m_pMessageListWidget->setItemWidget(m_UsrIdToQListWidgetItem[llv_SenderId], widget);
		
	}
	else
	{
		/*把好友请求消息的状态变成已拒绝*/

	}
	qDebug() << "DealUserAddRSSlot";
}

void MainWindow::on_pushButton_SendMessage_clicked()
{
	bool isSending = true;
	QString time = QString::number(QDateTime::currentDateTime().toTime_t()); //时间戳
	QString msg = ui.textEdit_MessageInput->toPlainText();
	ui.textEdit_MessageInput->setText("");
	
	{
		//发包
		STRU_SEND_MSG_RQ rq;
		rq.nPackNum = packId++;
		rq.msgtype = PRIVATEMSG;
		rq.packtype = PROTOCOL_SEND_MSG_RQ;
		rq.llID = 280761575;
		rq.llUserID = 280761575;
		Qstringtochar(rq.szText, msg, msg.size());
		//emit  sendchatmsgsignal((const char*)&rq, rq.nPackNum, sizeof(STRU_SEND_MSG_RQ));

	}

	this->dealMessageTime(time);	
	QNChatMessage* message = new QNChatMessage(ui.listWidget_ChatList);
	QListWidgetItem* item = new QListWidgetItem(ui.listWidget_ChatList);
	this->dealMessage(message, item, msg, time, QNChatMessage::User_Me);

	ui.listWidget_ChatList->setCurrentRow(ui.listWidget_ChatList->count() - 1);
}


void MainWindow::dealMessage(QNChatMessage* messageW, QListWidgetItem* item, QString text, QString time, QNChatMessage::User_Type type)
{
	messageW->setFixedWidth(ui.listWidget_ChatList->width());
	QSize size = messageW->fontRect(text);
	item->setSizeHint(size);
	size = QSize(ui.listWidget_ChatList->width(), 80);
	messageW->resize(size);
	messageW->setText(text, time, size, type);
	ui.listWidget_ChatList->setItemWidget(item, messageW);
}

void MainWindow::dealMessageTime(QString curMsgTime)
{
	bool isShowTime = false;

	if (ui.listWidget_ChatList->count() > 0) 
	{
		QListWidgetItem* lastItem = ui.listWidget_ChatList->item(ui.listWidget_ChatList->count() - 1);
		QNChatMessage* messageW = (QNChatMessage*)ui.listWidget_ChatList->itemWidget(lastItem);
		int lastTime = messageW->time().toInt();
		int curTime = curMsgTime.toInt();
		qDebug() << "curTime lastTime:" << curTime - lastTime;
		isShowTime = ((curTime - lastTime) > 60); // 两个消息相差一分钟
												  //        isShowTime = true;
	}
	else 
	{
		isShowTime = true;
	}

	if (isShowTime) 
	{
		QNChatMessage* messageTime = new QNChatMessage(ui.listWidget_ChatList);
		QListWidgetItem* itemTime = new QListWidgetItem(ui.listWidget_ChatList);

		QSize size = QSize(ui.listWidget_ChatList->width(), 40);
		messageTime->resize(size);
		itemTime->setSizeHint(size);
		messageTime->setText(curMsgTime, curMsgTime, size, QNChatMessage::User_Time);
		ui.listWidget_ChatList->setItemWidget(itemTime, messageTime);
	}
}


CLIENT_RESULT MainWindow::GetMsgList(long long userid, int &msgnum, QList<STRU_MSG_LIST> &msglist)
{
	const QString path = "./userData/280761575/MessageList.txt";
	QString name;
	QString remark;
	QString msg;
	QPixmap avatar;
	STRU_MSG_LIST msgstru;
	
	QFile file(path);
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		qDebug() << "GetMsgList() open file failed";
		return CLIENT_ERROR;
	}

	bool flag = true;
	while (!file.atEnd()) {
		QByteArray line = file.readLine();
		if (flag)
		{
			msgnum = std::stoi(line.toStdString());
			flag = false;
			continue;
		}
		GetUsrName(0, msgstru.name);
		GetUsrRemark(0, msgstru.remark);
		GetLastOfflineMsg(0, msgstru.msg);
		GetUsrAvatar(0, msgstru.avatar);
		msglist.push_back(msgstru);
	}
	return CLIENT_OK;
}



CLIENT_RESULT MainWindow::GetUsrRemark(long long usrid, QString& remark)
{
	remark = "remark";
	return CLIENT_OK;
}

CLIENT_RESULT MainWindow::GetLastOfflineMsg(long long usrid, QString& msg)
{
	const QString path = "./userData";
	msg = "this is the last message";
	return CLIENT_OK;
}
CLIENT_RESULT MainWindow::GetUsrAvatar(long long usrid, QPixmap &avatar)
{
	const QString path = "./userData/280761575/FriendAvatar/18804635241.jpg";

	avatar.load(path);
	return CLIENT_OK;
}
CLIENT_RESULT MainWindow::GetUsrName(long long usrid, QString &name)
{
	name = "name";
	return CLIENT_OK;
}


MainWindow* MainWindow::GetInstance()
{
	if (mainwindow == nullptr)
	{
		mainwindow = new MainWindow();
	}

	return mainwindow;
}

MainWindow* MainWindow::DeleteInstance()
{
	delete mainwindow;
	mainwindow = nullptr;
}