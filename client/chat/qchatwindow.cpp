#include "qchatwindow.h"
#include <QDateTime>
#include <QDebug>
#include <qfilesystemwatcher.h>

/*构造函数*/
QChatWindow::QChatWindow(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	
	//setFocusPolicy(Qt::NoFocus);											// 去除item选中时的虚线边框  
    ui.listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);	//水平滚动条关闭  
	this->setAttribute(Qt::WA_DeleteOnClose);								//窗口关闭后自动销毁资源
	setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint); hide();

	/*将消息写入消息列表中*/
	QFileSystemWatcher fsWatcher;
	//fsWatcher.addPath(FileName);
	//connect(&fsWatcher, SIGNAL(fileChanged(QString)), this, SLOT(UpdateMsg(QString)));
}

/*析构函数*/
QChatWindow::~QChatWindow()
{

}







void QChatWindow::resizeEvent(QResizeEvent *event)
{
	Q_UNUSED(event);


	//ui.textEdit->resize(this->width() - 20, ui.widget->height() - 20);
	//ui.textEdit->move(10, 10);

	//ui.pushButton->move(ui.textEdit->width() + ui.textEdit->x() - ui.pushButton->width() - 10,
		//ui.textEdit->height() + ui.textEdit->y() - ui.pushButton->height() - 10);


	for (int i = 0; i < ui.listWidget->count(); i++) {
		QNChatMessage* messageW = (QNChatMessage*)ui.listWidget->itemWidget(ui.listWidget->item(i));
		QListWidgetItem* item = ui.listWidget->item(i);

		//dealMessage(messageW, item, messageW->text(), messageW->time(), messageW->userType());
	}
}


/*处理好友消息的槽函数*/
void QChatWindow::DealSendMsgRsSlot(char* pszBuffer, int nLen)
{
	if (NULL == pszBuffer || nLen <= 0)
		return;
	
	STRU_SEND_MSG_RS *lpv_Sendmsgrs = (STRU_SEND_MSG_RS*)pszBuffer;
	QNChatMessage* messageW = new QNChatMessage(ui.listWidget->parentWidget());
	QListWidgetItem* item = new QListWidgetItem(ui.listWidget);
	QString msg = (QString)lpv_Sendmsgrs->szText;
	//dealMessage(messageW, item, msg, "11:20", QNChatMessage::User_Me);
	
}