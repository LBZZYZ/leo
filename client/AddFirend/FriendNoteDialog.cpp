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

	//dlg.setWindowTitle(QString("%1-��Ӻ���").arg(userId));
	////��ť
	//QDialogButtonBox buttonBox;
	//buttonBox.setParent(&dlg);
	////buttonBox.setStandardButtons(QDialogButtonBox::Cancel | QDialogButtonBox::Ok);
	//buttonBox.addButton("ȷ��", QDialogButtonBox::YesRole);
	//buttonBox.addButton("ȡ��", QDialogButtonBox::NoRole);
	//connect(&buttonBox, SIGNAL(accepted()), &dlg, SLOT(accept()));
	//connect(&buttonBox, SIGNAL(rejected()), &dlg, SLOT(rejecte()));
	////��ע�༭��

	//QLabel namelable(&dlg);
	//namelable.setText("��ע����");
	//QLineEdit qName(&dlg);
	//qName.setFocus();
	//qName.selectAll();
	////ˮƽ����
	//QHBoxLayout *hlayout = new QHBoxLayout;
	//hlayout->addWidget(&namelable, 2);
	//hlayout->addWidget(&qName, 8);



	//QLabel grouplable(&dlg);
	//grouplable.setText("����");
	//QComboBox groupcom(&dlg);
	//groupcom.setEnabled(true);
	////
	//groupcom.addItem("�ҵĺ���");
	//groupcom.addItem("����");
	//QHBoxLayout *hlayout1 = new QHBoxLayout;
	//hlayout1->addWidget(&grouplable, 2);
	//hlayout1->addWidget(&groupcom, 8);

	////���ֹ���
	//QVBoxLayout *layout = new QVBoxLayout;
	////��Ӳ���Ҫ����Ŀؼ�
	//layout->addLayout(hlayout);
	//layout->addLayout(hlayout1);
	//layout->addWidget(&buttonBox);
	//dlg.setLayout(layout);


	//int res = dlg.exec();

/*����ȷ�ϼ�*/
	//if (/*res == */QDialog::Accepted)
	//{
	//	/*���ػ�����ӵĺ�����Ϣ*/
	//	QFile file("ReadyFriend");
	//	//qint64 pos = file.size();
	//	//file.seek(pos);				

	//	//comtext.seek(pos);				//ƫ�Ƶ��ļ�β
	//	if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
	//	{
	//		qDebug() << tr("��ʧ��") << file.OpenError;


	//		file.close();
	//		return;
	//	}
	//	else
	//	{
	//		// << ���������
	//		// >> ��ȡ�����
	//		QTextStream comtext(&file);
	//		//comtext << ui.m_searchInfoEdit->text() << "#";	//������ID
	//		//comtext << qName.text() << "#";                 //��ע��

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

	//	/*������Ӻ��������*/
	//	STRU_USER_ADD_RQ add_rq;
	//	//add_rq.llSearchID = ui.m_searchInfoEdit->text().toLongLong();
	//	add_rq.nPackNum = packId++;
	//	add_rq.llUserID = userId;
	//	add_rq.packtype = PROTOCOL_USER_ADD_RQ;


	//	/*����������Ӻ��������ź�*/
	//	emit SendAddFriendRequest((const char*)&add_rq, add_rq.nPackNum, sizeof(STRU_USER_ADD_RQ));

	//	/*��ʾ�Ի���(��Ϣ�ѷ���)*/
	//	QMessageBox* box = new QMessageBox(QMessageBox::NoIcon, QString("%1-��Ӻ���").arg(userId), QString("�Ѿ���������"), QMessageBox::Ok);
	//	box->show();

	//	/*���ȴ���֤����Ϣ��ӵ���Ϣ������*/
	//	//QString lsv_Searchname = ui.tableWidget->item(0, 0)->text();
	//	char lsv_Name[20] = { 0 };
	//	//Qstringtochar(lsv_Name, lsv_Searchname, 20);
	//	emit AddMsgToMsgList(add_rq.llSearchID, lsv_Name, 1);

	//}

	///*����ȡ����*/
	//if (res == QDialog::Rejected)//ȡ����������
	//{
	//	QMessageBox::about(NULL, "��ʾ", " ������˹رհ�ť��");
	//	//��ӹر�ʱ��Ҫ����Ϊ
	//}
}
