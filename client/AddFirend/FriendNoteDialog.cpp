#include "FriendNoteDialog.h"

FriendNoteDialog::FriendNoteDialog(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

FriendNoteDialog::~FriendNoteDialog()
{
}


void FriendNoteDialog::Init()
{
	//QDialog dlg(nullptr, Qt::Dialog | Qt::WindowCloseButtonHint);

	//dlg.setWindowTitle(QString("%1-添加好友").arg(userId));
	////按钮
	//QDialogButtonBox buttonBox;
	//buttonBox.setParent(&dlg);
	////buttonBox.setStandardButtons(QDialogButtonBox::Cancel | QDialogButtonBox::Ok);
	//buttonBox.addButton("确定", QDialogButtonBox::YesRole);
	//buttonBox.addButton("取消", QDialogButtonBox::NoRole);
	//connect(&buttonBox, SIGNAL(accepted()), &dlg, SLOT(accept()));
	//connect(&buttonBox, SIGNAL(rejected()), &dlg, SLOT(rejecte()));
	////备注编辑框

	//QLabel namelable(&dlg);
	//namelable.setText("备注姓名");
	//QLineEdit qName(&dlg);
	//qName.setFocus();
	//qName.selectAll();
	////水平布局
	//QHBoxLayout *hlayout = new QHBoxLayout;
	//hlayout->addWidget(&namelable, 2);
	//hlayout->addWidget(&qName, 8);



	//QLabel grouplable(&dlg);
	//grouplable.setText("分组");
	//QComboBox groupcom(&dlg);
	//groupcom.setEnabled(true);
	////
	//groupcom.addItem("我的好友");
	//groupcom.addItem("家人");
	//QHBoxLayout *hlayout1 = new QHBoxLayout;
	//hlayout1->addWidget(&grouplable, 2);
	//hlayout1->addWidget(&groupcom, 8);

	////布局管理
	//QVBoxLayout *layout = new QVBoxLayout;
	////添加布局要管理的控件
	//layout->addLayout(hlayout);
	//layout->addLayout(hlayout1);
	//layout->addWidget(&buttonBox);
	//dlg.setLayout(layout);


	//int res = dlg.exec();

/*按下确认键*/
	//if (/*res == */QDialog::Accepted)
	//{
	//	/*本地化待添加的好友信息*/
	//	QFile file("ReadyFriend");
	//	//qint64 pos = file.size();
	//	//file.seek(pos);				

	//	//comtext.seek(pos);				//偏移到文件尾
	//	if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
	//	{
	//		qDebug() << tr("打开失败") << file.OpenError;


	//		file.close();
	//		return;
	//	}
	//	else
	//	{
	//		// << 插入运算符
	//		// >> 读取运算符
	//		QTextStream comtext(&file);
	//		//comtext << ui.m_searchInfoEdit->text() << "#";	//搜索的ID
	//		//comtext << qName.text() << "#";                 //备注名

	//		//QList<QTableWidgetItem*> lsttable = ui.tableWidget->selectedItems();
	//		//QList<QTableWidgetItem*>::iterator ite = lsttable.begin();

	//		//while (ite != lsttable.end())
	//		{

	//			//comtext << (*ite)->text() << "#";
	//			//ite = lsttable.erase(ite);
	//		}
	//		//comtext << groupcom.currentText();
	//	}
	//	file.close();

	//	/*构造添加好友请求包*/
	//	STRU_USER_ADD_RQ add_rq;
	//	//add_rq.llSearchID = ui.m_searchInfoEdit->text().toLongLong();
	//	add_rq.nPackNum = packId++;
	//	add_rq.llUserID = userId;
	//	add_rq.packtype = PROTOCOL_USER_ADD_RQ;


	//	/*触发发送添加好友请求信号*/
	//	emit SendAddFriendRequest((const char*)&add_rq, add_rq.nPackNum, sizeof(STRU_USER_ADD_RQ));

	//	/*提示对话框(消息已发送)*/
	//	QMessageBox* box = new QMessageBox(QMessageBox::NoIcon, QString("%1-添加好友").arg(userId), QString("已经发送请求"), QMessageBox::Ok);
	//	box->show();

	//	/*将等待验证的信息添加到消息界面中*/
	//	//QString lsv_Searchname = ui.tableWidget->item(0, 0)->text();
	//	char lsv_Name[20] = { 0 };
	//	//Qstringtochar(lsv_Name, lsv_Searchname, 20);
	//	emit AddMsgToMsgList(add_rq.llSearchID, lsv_Name, 1);

	//}

	///*按下取消键*/
	//if (res == QDialog::Rejected)//取消键有问题
	//{
	//	QMessageBox::about(NULL, "提示", " 您点击了关闭按钮！");
	//	//添加关闭时你要的行为
	//}
}
