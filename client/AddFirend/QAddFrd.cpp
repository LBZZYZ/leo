#include "QAddFrd.h"

#include <QTableWidgetItem>
#include <QDialog>
#include <QDialogButtonBox>
#include <qlabel.h>
#include <QMessageBox>
#include<QFile>
#include<stdio.h>
#include <QDir>
#include <qdebug.h>
#include <QMouseEvent>
#include <QByteArray>

QAddFrd::QAddFrd(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setAttribute(Qt::WA_DeleteOnClose);
	//添加一个菜单
	m_pmenu = new QMenu();
	QAction *AddFriend = new QAction(QString("添加好友"), this);
	m_pmenu->addAction(AddFriend);

	//事件管理器
	ui.tableWidget->installEventFilter(this);

	connect(ui.m_searchcfirmButton, &QPushButton::pressed, this, &QAddFrd::searchfr);

	connect(AddFriend, SIGNAL(triggered()), this, SLOT(AddFriendSlot()));
}

QAddFrd::~QAddFrd()
{
	ui.retranslateUi(this);

}
void  QAddFrd::searchfr()
{
	STRU_SEARCH_USER_RQ search_rq;
	if (ui.m_searchInfoEdit->text().isEmpty())
		return;
	search_rq.llSearchID = ui.m_searchInfoEdit->text().toLongLong();
	search_rq.llUserID = userId;
	search_rq.packtype = PROTOCOL_SEARCH_USER_RQ;

	//search_rq.packtype = PROTOCOL_LOGIN_RQ;
	emit  sendsearchsignal((const char*)&search_rq, sizeof(STRU_SEARCH_USER_RQ));
}
void   QAddFrd::closeEvent(QCloseEvent * e)//关闭事件
{
	emit adduiclose();
}
bool QAddFrd::eventFilter(QObject *obj, QEvent *event)
{
	if (obj == ui.tableWidget)
	{
		if (event->type() == QEvent::ContextMenu)
		{
			QMouseEvent* e = static_cast<QMouseEvent*>(event);
			if (ui.tableWidget->itemAt(e->pos()) != 0)
			{
				m_pmenu->exec(QCursor::pos());
				return true;
			}
			event->ignore();
		}
	}
	return false;
}

void QAddFrd::DealserchRS(STRU_SEARCH_USER_RS* rs)
{
	if (ui.tableWidget->columnCount() < 3)
	{
		ui.tableWidget->setColumnCount(3);
		QTableWidgetItem* nameItem = new QTableWidgetItem("昵称");
		//nameItem->setTextAlignment(Qt::AlignHCenter);
		ui.tableWidget->setHorizontalHeaderItem(0, nameItem);
		QTableWidgetItem* sexItem = new QTableWidgetItem("性别");
		//sexItem->setTextAlignment(Qt::AlignHCenter);
		ui.tableWidget->setHorizontalHeaderItem(1, sexItem);
		QTableWidgetItem* birdayItem = new QTableWidgetItem("生日");
		//birdayItem->setTextAlignment(Qt::AlignHCenter);
		ui.tableWidget->setHorizontalHeaderItem(2, birdayItem);
		if (ui.tableWidget->rowCount() < 1)
			ui.tableWidget->setRowCount(1);
		QTableWidgetItem * rowItem = new QTableWidgetItem("1");
		ui.tableWidget->setVerticalHeaderItem(0, rowItem);
		QString name;
		ChartoQstring(rs->szUserName, name, NAME_SIZE);
		QString sex = rs->szSex == 'f' ? "女" : "男";
		QString birday;
		ChartoQstring(rs->szBirth, birday, 15);
		QTableWidgetItem* nameItem1 = new QTableWidgetItem(name);
		ui.tableWidget->setItem(0, 0, nameItem1);
		QTableWidgetItem* sexItem1 = new QTableWidgetItem(sex);
		ui.tableWidget->setItem(0, 1, sexItem1);
		QTableWidgetItem* birdayItem2 = new QTableWidgetItem(birday);
		ui.tableWidget->setItem(0, 2, birdayItem2);
		ui.tableWidget->setEditTriggers(false);//不可修改
		ui.tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//只能选中row

	}
	update();
}



/*客户端发送添加好友请求*/
void QAddFrd::AddFriendSlot()
{
	QDialog dlg(nullptr, Qt::Dialog | Qt::WindowCloseButtonHint);

	dlg.setWindowTitle(QString("%1-添加好友").arg(userId));
	//按钮
	QDialogButtonBox buttonBox;
	buttonBox.setParent(&dlg);
	//buttonBox.setStandardButtons(QDialogButtonBox::Cancel | QDialogButtonBox::Ok);
	buttonBox.addButton("确定", QDialogButtonBox::YesRole);
	buttonBox.addButton("取消", QDialogButtonBox::NoRole);
	connect(&buttonBox, SIGNAL(accepted()), &dlg, SLOT(accept()));
	connect(&buttonBox, SIGNAL(rejected()), &dlg, SLOT(rejecte()));
	//备注编辑框

	QLabel namelable(&dlg);
	namelable.setText("备注姓名");
	QLineEdit qName(&dlg);
	qName.setFocus();
	qName.selectAll();
	//水平布局
	QHBoxLayout *hlayout = new QHBoxLayout;
	hlayout->addWidget(&namelable, 2);
	hlayout->addWidget(&qName, 8);



	QLabel grouplable(&dlg);
	grouplable.setText("分组");
	QComboBox groupcom(&dlg);
	groupcom.setEnabled(true);
	//
	groupcom.addItem("我的好友");
	groupcom.addItem("家人");
	QHBoxLayout *hlayout1 = new QHBoxLayout;
	hlayout1->addWidget(&grouplable, 2);
	hlayout1->addWidget(&groupcom, 8);

	//布局管理
	QVBoxLayout *layout = new QVBoxLayout;
	//添加布局要管理的控件
	layout->addLayout(hlayout);
	layout->addLayout(hlayout1);
	layout->addWidget(&buttonBox);
	dlg.setLayout(layout);


	int res = dlg.exec();

	/*按下确认键*/
	if (res == QDialog::Accepted)
	{
		/*本地化待添加的好友信息*/
		QFile file("ReadyFriend");
		//qint64 pos = file.size();
		//file.seek(pos);				
		
		//comtext.seek(pos);				//偏移到文件尾
		if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
		{
			qDebug() << tr("打开失败") << file.OpenError;


			file.close();
			return;
		}
		else
		{
			// << 插入运算符
			// >> 读取运算符
			QTextStream comtext(&file);
			comtext << ui.m_searchInfoEdit->text() << "#";	//搜索的ID
			comtext << qName.text() << "#";                 //备注名

			QList<QTableWidgetItem*> lsttable = ui.tableWidget->selectedItems();
			QList<QTableWidgetItem*>::iterator ite = lsttable.begin();

			while (ite != lsttable.end())
			{

				comtext << (*ite)->text() << "#";
				ite = lsttable.erase(ite);
			}
			comtext << groupcom.currentText();
		}
		file.close();

		/*构造添加好友请求包*/
		STRU_USER_ADD_RQ add_rq;
		add_rq.llSearchID = ui.m_searchInfoEdit->text().toLongLong();
		add_rq.nPackNum = packId++;
		add_rq.llUserID = userId;
		add_rq.packtype = PROTOCOL_USER_ADD_RQ;


		/*触发发送添加好友请求信号*/
		emit SendAddFrdRqSignal((const char*)&add_rq, add_rq.nPackNum, sizeof(STRU_USER_ADD_RQ));
		
		/*提示对话框(消息已发送)*/
		QMessageBox* box = new QMessageBox(QMessageBox::NoIcon, QString("%1-添加好友").arg(userId), QString("已经发送请求"), QMessageBox::Ok);
		box->show();

		/*将等待验证的信息添加到消息界面中*/
		QString lsv_Searchname = ui.tableWidget->item(0, 0)->text();
		char lsv_Name[20] = { 0 };
		Qstringtochar(lsv_Name, lsv_Searchname, 20);
		emit AddMsgToMsgListSignal(add_rq.llSearchID,lsv_Name,1);

	}

	/*按下取消键*/
	if (res == QDialog::Rejected)//取消键有问题
	{
		QMessageBox::about(NULL, "提示", " 您点击了关闭按钮！");
		//添加关闭时你要的行为
	}
}
