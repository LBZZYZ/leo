#include "qclient.h"
#include <QGraphicsDropShadowEffect>
#include "qheadicon.h"
#include "qpushbutton.h"
#include "qpixmap.h"
#include "qbitmap.h"
#include "qmenubar.h"
#include "../QClient/QMessageItem.h"
#include "qdebug.h"
#include <iostream>
#include "Mediator.h"
#include "qdatetime.h"
#include "qstring.h"


QClient::QClient(list<FRINENDLISTMSG> * pFriendlistmsg, QObject *parent)

{
	ui.setupUi(this);
	setAttribute(Qt::WA_DeleteOnClose);
	InitWindow(pFriendlistmsg);
	this->loadStyleSheet("QClient/QFreindTreeWidegt.css");
	
	addui = nullptr;

	//组件连接
	connect(ui.textEdit_MessageInput, &QTextEdit::textChanged, this, &QClient::editwordcount);
	//connect(ui.pushButton_SendMessage, &QPushButton::clicked, this, &QClient::on_pushButton_SendMessage_clicked);
	
}
QClient::~QClient()
{
	delete m_pFriendList;
	m_pFriendList = NULL;

}

/*字数检查*/
void  QClient::editwordcount()
{

	QString textContent = ui.textEdit_MessageInput->toPlainText();
	// qDebug() << textContent;

	int length = textContent.toUtf8().size();
	int maxLength = 480; // 最大字节数
	qDebug() << length;


	if (length > maxLength) {
		QTextCursor cursor = ui.textEdit_MessageInput->textCursor();
		cursor.movePosition(QTextCursor::End);
		if (cursor.hasSelection()) {
			cursor.clearSelection();
		}
		cursor.deletePreviousChar();
		//设置当前的光标为更改后的光标
		ui.textEdit_MessageInput->setTextCursor(cursor);
	}

	//length = ui.m_chatedit->toPlainText().count();
	//qDebug() << (QString("%1/%2").arg(MAX_SIZE - length).arg(MAX_SIZE));





}


void QClient::InitWindow(list<FRINENDLISTMSG> *pFriendlistmsg)
{
	//无边框窗口
	this->setWindowFlags(Qt::FramelessWindowHint |/* Qt::WindowStaysOnTopHint|*/ Qt::
		WindowSystemMenuHint | Qt::WindowMinimizeButtonHint);
	//窗口透明
	//this->setAttribute(Qt::WA_TranslucentBackground, true);

	//窗口阴影
	//QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect;
	//effect->setOffset(4, 4);
	//effect->setColor(QColor(0, 0, 0, 80));
	//effect->setBlurRadius(8);
	//ui.frame->setGraphicsEffect(effect);

	//头像
	QPixmap* icon = new QPixmap;
	QHeadIcon* HeadIcon = new QHeadIcon(icon, 410, 0, 48, 48,false,ui.frame);

	//close按钮
	QPushButton* closebutton = new QPushButton(ui.frame);
	QPixmap pixmap("Resources/TopbuttonBack.png");
	closebutton->resize(QSize(48,32));
	closebutton->setMask(QBitmap(pixmap.mask()));
	closebutton->setGeometry(this->width()- closebutton->width(), 0, 40, 32);
	closebutton->setStyleSheet(QString("QPushButton{background-color:rgb(0, 0, 0,0);border-image:url(Resources/closebutton.png);border-top-right-radius:2px}QPushButton:hover{border:none;background-color:red;}"));


	QPushButton* minbutton = new QPushButton(ui.frame);
	minbutton->resize(QSize(48,32));
	minbutton->setMask(QBitmap(pixmap.mask()));
	minbutton->setGeometry(this->width() - closebutton->width()-minbutton->width(), 0, 40, 32);
	minbutton->setStyleSheet(QString("QPushButton{background-color:rgb(0, 0, 0,0);border-image:url(Resources/minbutton.png);}\n"
		"QPushButton:hover{border:none;background-color:#BDBDBD;}"));

	//事件管理器
	ui.m_pMessageListWidget->installEventFilter(ui.tabWidget);

	//消息框

	QListWidgetItem *ITEM = new QListWidgetItem();
	QPixmap pixmap1("Resources/QQimage.png");
	QString str;
	str = QString::number(1);
	QMessageItem* widget = new QMessageItem(this, nullptr, QString(str), QString("***********"),0,QMessageItem::USUER);
	QSize size = ITEM->sizeHint();
	ITEM->setSizeHint(QSize(this->ui.m_pMessageListWidget->width(), 72));
	ui.m_pMessageListWidget->addItem(ITEM);
	widget->setSizeIncrement(size.width(), 72);
	ui.m_pMessageListWidget->setItemWidget(ITEM, widget);
		
	//定义好友列表对象
	 m_pFriendList= new QPersonList(pFriendlistmsg,ui.tabWidget->widget(1));
	 m_pFriendList->installEventFilter(ui.tabWidget->widget(1));
	
	connect(closebutton,& QPushButton::pressed, this,&QClient::qqclientclose);
	connect(minbutton, &QPushButton::pressed, this, &QClient::showMinimized);
	//connect(action[0], SIGNAL(triggered()), this, SLOT(qqclientclose()));
	//connect(action[1], SIGNAL(triggered()), this, SLOT(returnlogin()));
	//connect(action[2], SIGNAL(triggered()), this, SLOT(InitAddFriendUi()));


	

}

void QClient::loadStyleSheet(const QString &sheetName)
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

void QClient::InitAddFriendUi()//初始化添加好友窗口
{
	if (addui == nullptr)
	{
		addui = new QAddFrd();
		addui->show();
		emit IsAdduiExist(true);//发送添加好友窗口存在的信号
		connect(addui, SIGNAL(adduiclose()), this, SLOT(adduiclosed()));
	}
}

void QClient::qqclientclose()//客户端关闭
{
	if (addui != nullptr)
	{
		addui->close();
	}
	this->close();
}

void QClient::adduiclosed()
{
	emit IsAdduiExist(false);

	addui->close();
	addui = nullptr;
}


/*把等待验证的信息放到消息列表中A*/
void QClient::DealAddMsgToMsgListSignal(long long ID, const char* namestr, int type)
{

	m_UsrIdToQListWidgetItem[ID] = new QListWidgetItem();
	QMessageItem *pWidget = new QMessageItem(this, nullptr, QString(namestr), QString("添加请求已发送。"), ID, QMessageItem::SendVerification);
	QSize size = m_UsrIdToQListWidgetItem[ID]->sizeHint();
	m_UsrIdToQListWidgetItem[ID]->setSizeHint(QSize(size.width(), 72));
	ui.m_pMessageListWidget->addItem(m_UsrIdToQListWidgetItem[ID]);
	pWidget->setSizeIncrement(size.width(), 72);
	ui.m_pMessageListWidget->setItemWidget(m_UsrIdToQListWidgetItem[ID], pWidget);
	
}

/*处理添加好友请求*///B
void QClient::DealUserAddRQSLot(char *pszBuffer, int nLen)
{
	/*把添加好友请求的信息放到消息列表中*/
	STRU_USER_ADD_RQ *lpv_Usraddrq = (STRU_USER_ADD_RQ*)pszBuffer;
	long long llv_SenderId = lpv_Usraddrq->llUserID;
	m_UsrIdToQListWidgetItem[llv_SenderId] = new QListWidgetItem();
	
	QMessageItem* widget = new QMessageItem(this, nullptr,QString("280761575"), QString("想要添加你为好友"), lpv_Usraddrq->llUserID, QMessageItem::RecvVerification);
	QSize size = m_UsrIdToQListWidgetItem[llv_SenderId]->sizeHint();
	m_UsrIdToQListWidgetItem[llv_SenderId]->setSizeHint(QSize(size.width(), 72));
	ui.m_pMessageListWidget->addItem(m_UsrIdToQListWidgetItem[llv_SenderId]);
	widget->setSizeIncrement(size.width(), 72);
	ui.m_pMessageListWidget->setItemWidget(m_UsrIdToQListWidgetItem[llv_SenderId], widget);



	/*connect同意/拒绝按钮*/
	if (false == connect(widget->m_firmButton, &QPushButton::pressed, this, &QClient::SendAddFrdRsSlot))
	{
		qDebug() << "SendAddFrdRsSlot";

	}
	return;
}

/*用户点击同意添加，发送添加好友回复包给服务器，同时把添加好友请求的消息从消息列表中删除，并将其添加的用户添加到他的好友列表中*/
void  QClient::SendAddFrdRsSlot()
{
	QPoint point = ui.m_pMessageListWidget->mapFromGlobal(QCursor::pos());
	QListWidgetItem *p;
	if (NULL == (p = ui.m_pMessageListWidget->itemAt(point)))
	{
		qDebug() << "itemAt";
	}
	int nRow;
	nRow = ui.m_pMessageListWidget->row(p);
	QMessageItem * pWidget = static_cast<QMessageItem*>(ui.m_pMessageListWidget->itemWidget(p));
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
	//1.删除QMessageItem
	delete pWidget;
	//2.添加新的QMessageItem
	m_UsrIdToQListWidgetItem[llv_SenderId]->~QListWidgetItem();
	m_UsrIdToQListWidgetItem[llv_SenderId] = new QListWidgetItem;
	QMessageItem* widget = new QMessageItem(this, nullptr, QString("aa"), QString("可以开始聊天了"), llv_SenderId, QMessageItem::USUER);
	QSize size = m_UsrIdToQListWidgetItem[llv_SenderId]->sizeHint();
	m_UsrIdToQListWidgetItem[llv_SenderId]->setSizeHint(QSize(size.width(), 72));
	ui.m_pMessageListWidget->addItem(m_UsrIdToQListWidgetItem[llv_SenderId]);
	widget->setSizeIncrement(size.width(), 72);
	ui.m_pMessageListWidget->setItemWidget(m_UsrIdToQListWidgetItem[llv_SenderId], widget);

}

/*处理添加好友回复包A*/
void QClient::DealUserAddRsSLot(char *pszBuffer, int nLen)
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
		QMessageItem * pWidget = static_cast<QMessageItem*>(ui.m_pMessageListWidget->itemWidget(m_UsrIdToQListWidgetItem[llv_SenderId]));
		delete pWidget;
		pWidget = NULL;
		m_UsrIdToQListWidgetItem[llv_SenderId]->~QListWidgetItem();
		/*把消息列表中的等待验证变成与此人的聊天消息*/
		m_UsrIdToQListWidgetItem[llv_SenderId] = new QListWidgetItem;
		QMessageItem *widget = new QMessageItem(this, nullptr, QString("280761575"), QString("可以开始聊天了"), llv_SenderId, QMessageItem::USUER);
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




/*发送按钮点击事件*/
//on_XXX_clicked()只需实现XXX对应的槽函数 无需手动绑定，由moc完成
void QClient::on_pushButton_SendMessage_clicked()
{
	QString msg = ui.textEdit_MessageInput->toPlainText();
	ui.textEdit_MessageInput->setText("");
	QString time = QString::number(QDateTime::currentDateTime().toTime_t()); //时间戳

	//发包
	STRU_SEND_MSG_RQ rq;
	rq.nPackNum = packId++;
	rq.msgtype = PRIVATEMSG;
	rq.packtype = PROTOCOL_SEND_MSG_RQ;
	rq.llID = 280761575;
	rq.llUserID = 280761575;
	Qstringtochar(rq.szText, msg, msg.size());

	//emit  sendchatmsgsignal((const char*)&rq, rq.nPackNum, sizeof(STRU_SEND_MSG_RQ));
	bool isSending = true; // 发送中
	qDebug() << "addMessage" << msg << time << ui.listWidget_ChatList->count();
	//if (ui.listWidget->count() % 2) {
	if (isSending) {
		dealMessageTime(time);
		
		QNChatMessage* messageW = new QNChatMessage(ui.listWidget_ChatList);
		QListWidgetItem* item = new QListWidgetItem(ui.listWidget_ChatList);
		dealMessage(messageW, item, msg, time, QNChatMessage::User_Me);
	}
	else {
		bool isOver = true;
		for (int i = ui.listWidget_ChatList->count() - 1; i > 0; i--) {
			QNChatMessage* messageW = (QNChatMessage*)ui.listWidget_ChatList->itemWidget(ui.listWidget_ChatList->item(i));
			if (messageW->text() == msg) {
				isOver = false;
				messageW->setTextSuccess();
			}
		}
		if (isOver) {
			dealMessageTime(time);

			QNChatMessage* messageW = new QNChatMessage(ui.listWidget_ChatList->parentWidget());
			QListWidgetItem* item = new QListWidgetItem(ui.listWidget_ChatList);
			dealMessage(messageW, item, msg, time, QNChatMessage::User_Me);
			messageW->setTextSuccess();
		}
	}
	ui.listWidget_ChatList->setCurrentRow(ui.listWidget_ChatList->count() - 1);
}


void QClient::dealMessage(QNChatMessage* messageW, QListWidgetItem* item, QString text, QString time, QNChatMessage::User_Type type)
{
	messageW->setFixedWidth(this->width());
	QSize size = messageW->fontRect(text);
	item->setSizeHint(size);
	size = QSize(this->width(), 80);
	messageW->resize(size);
	messageW->setText(text, time, size, type);
	ui.listWidget_ChatList->setItemWidget(item, messageW);
}

void QClient::dealMessageTime(QString curMsgTime)
{
	bool isShowTime = false;
	if (ui.listWidget_ChatList->count() > 0) {
		QListWidgetItem* lastItem = ui.listWidget_ChatList->item(ui.listWidget_ChatList->count() - 1);
		QNChatMessage* messageW = (QNChatMessage*)ui.listWidget_ChatList->itemWidget(lastItem);
		int lastTime = messageW->time().toInt();
		int curTime = curMsgTime.toInt();
		qDebug() << "curTime lastTime:" << curTime - lastTime;
		isShowTime = ((curTime - lastTime) > 60); // 两个消息相差一分钟
												  //        isShowTime = true;
	}
	else {
		isShowTime = true;
	}
	if (isShowTime) {
		QNChatMessage* messageTime = new QNChatMessage(ui.listWidget_ChatList->parentWidget());
		QListWidgetItem* itemTime = new QListWidgetItem(ui.listWidget_ChatList);

		QSize size = QSize(this->width(), 40);
		messageTime->resize(size);
		itemTime->setSizeHint(size);
		messageTime->setText(curMsgTime, curMsgTime, size, QNChatMessage::User_Time);
		ui.listWidget_ChatList->setItemWidget(itemTime, messageTime);
	}
}


void QClient::mousePressEvent(QMouseEvent* e)
{
	last = e->globalPos();
}
void QClient::mouseMoveEvent(QMouseEvent* e)
{
	int dx = e->globalX() - last.x();
	int dy = e->globalY() - last.y();
	last = e->globalPos();
	move(x() + dx, y() + dy);
}
void QClient::mouseReleaseEvent(QMouseEvent* e)
{
	int dx = e->globalX() - last.x();
	int dy = e->globalY() - last.y();
	move(x() + dx, y() + dy);
}

