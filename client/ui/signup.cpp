#include "signup.h"
Signup::Signup(QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	bool ret;
	connect(ui.qLineEdit_UserName, &QLineEdit::textChanged, this, &Signup::MatchAccount);
	connect(ui.qLineEdit_PassWord, &QLineEdit::textChanged, this, &Signup::MatchPassword);
	connect(ui.qLineEdit_PhoneNumber, &QLineEdit::textChanged, this, &Signup::MathPhoneNumber);

}
//按下请求注册
void  Signup::Register()
{
	STRU_REGISTER_RQ stru_register_rq;
	stru_register_rq.llUserID = (long long)(ui.qLineEdit_UserName->text().toLongLong());
	//qDebug() << stru_register_rq.llUserID;
	stru_register_rq.nPackNum = packId++;
	stru_register_rq.packtype = PROTOCOL_REGISTER_RQ;
	Qstringtochar(stru_register_rq.szPassWord, ui.qLineEdit_PassWord->text(), PASSWORD_SIZE);

	//char* ste = ui.m_registeruserName->text().toUtf8().data();

	emit SendUdpRQ((const char*)&stru_register_rq, stru_register_rq.nPackNum, sizeof(STRU_REGISTER_RQ));

}



//槽函数

void  Signup::MatchAccount()
{
	if (!ui.qLineEdit_UserName->text().toLongLong())
	{
		ui.qLabel_UserName->setText(QStringLiteral("请输入11以下位的数字"));
		ui.m_pRegister->setEnabled(false);
	}
	else
	{
		ui.qLabel_UserName->clear();
		ui.m_pRegister->setEnabled(true);
	}
}



//密码校验槽函数
void Signup::MatchPassword()
{
	if ((ui.qLineEdit_PassWord->text().isLower() ||
		ui.qLineEdit_PassWord->text().isUpper() ||
		ui.qLineEdit_PassWord->text().length() <= 9) &&
		ui.qLineEdit_PassWord->text().length() > 1)
	{
		ui.qLabel_PassWord->setText(QStringLiteral("密码过于简单！"));
		qDebug("aa\n");
		ui.m_pRegister->setEnabled(false);
	}
	else
	{
		ui.qLabel_PassWord->clear();
		ui.m_pRegister->setEnabled(true);
		qDebug("bb\n");
	}
}



void Signup::MathPhoneNumber()
{

}