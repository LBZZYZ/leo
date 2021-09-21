#include "login.h"

#include <iostream>
#include <QMouseEvent>
#include <QPushButton>
#include <QMessagebox>
#include <qpropertyanimation.h>	
#include <QFile>
#include <QPainter>
#include <QSettings>
#include "../net/EventDispatch.h"
#include "../net/Protocol.h"

Login::Login(QWidget *parent)
	: QWidget(parent)
{	    
	ui.setupUi(this);

	ConnectSignalSlot();
	InitWindow();
	LoadConfigFile();
	
}

const char * Login::ini_path = "D:/wd/leo/client/res/ini/LoginSettings.ini";

void Login::ConnectSignalSlot(void)
{
	connect(ui.m_minbutton, &QPushButton::pressed, this, &Login::showMinimized);
	connect(ui.m_rememberpw, &QCheckBox::stateChanged, this, &Login::IsRememberPasswordChecked);
	connect(ui.LoginButton, &QPushButton::pressed, this, &Login::login);
	connect(ui.m_pRegisterCancel, &QPushButton::pressed, this, &Login::TurnToLoginWindow);
	connect(ui.m_userNameCom, SIGNAL(currentIndexChanged(int)), this, SLOT(OnAccountChanged(int)));
}

bool Login::IsRememberPasswordChecked()
{
	if (ui.m_rememberpw->checkState() == Qt::Checked)
		return true;

	return false;
}

void  Login::login()
{
	if (ui.m_userNameCom->itemText(0).isEmpty() || ui.m_passwordlineedit->text().isEmpty())return;
	STRU_LOGIN_RQ stru_login_rq;
	stru_login_rq.llUserID = ui.m_userNameCom->currentText().toLongLong();
	stru_login_rq.packtype = PROTOCOL_LOGIN_RQ;
	Qstringtochar(stru_login_rq.szPassWord, ui.m_passwordlineedit->text(), PASSWORD_SIZE);
	EventDispatch* dispatcher = EventDispatch::GetInstance();
	dispatcher->net->SendData((char*)&stru_login_rq, sizeof(STRU_LOGIN_RQ));
}

void Login::TurnToLoginWindow()
{
	this->ui.stackedWidget->setCurrentWidget(ui.LoginPage);
}

void Login::OnAccountChanged(int current_index)
{
	QString account = ui.m_userNameCom->itemText(current_index);
	ui.m_passwordlineedit->setText(account_password[account]);

	QIcon icon;
	icon.addFile(USER_DATA + "\\common\\Avatar\\" + account + ".jpg");
	ui.pushButton_2->setIcon(icon);
	ui.pushButton_2->setIconSize(QSize(70, 70));
}

void Login::InitWindow()
{
	RegisterWatchedObject();
}

void Login::RegisterWatchedObject()
{
	ui.m_passwordlineedit->installEventFilter(this);
	ui.m_userNameCom->installEventFilter(this);
	ui.m_registaccount->installEventFilter(this);
	ui.m_userNameCom->installEventFilter(this);
	ui.qLineEdit_UserName->installEventFilter(this);
	ui.qLineEdit_PassWord->installEventFilter(this);
}

void Login::LoadConfigFile()
{
	QSettings config_file(QString("D:\\wd\\leo\\client\\res\\ini\\LoginSettings.ini"), QSettings::IniFormat);
	QSettings* test = new QSettings(QCoreApplication::applicationDirPath()+"\\config.ini", QSettings::IniFormat, this);
	std::cout << QCoreApplication::applicationDirPath().toStdString() << std::endl;
	test->setIniCodec("UTF-8");
	test->setValue("/setting/currentTabIndex", "20");
	test->sync();
	const char* remember_password = config_file.value(QString("RememberPassword")).toString().toStdString().c_str();
	if(remember_password == "true")
	{
		ui.m_rememberpw->setChecked(true);
	}
	else
	{
		ui.m_rememberpw->setChecked(false);
	}

}

Login::~Login()
{
	this->CloseWindow();
}

void Login::CloseWindow()
{
	QPropertyAnimation* animation = new QPropertyAnimation(this, "windowOpacity");
	animation->setDuration(1000);
	animation->setStartValue(1);
	animation->setEndValue(0);
	animation->start();
	connect(animation, SIGNAL(finished()), this, SLOT(close()));
}

bool Login::eventFilter(QObject * Watched, QEvent * event)
{

	if (Watched == ui.m_registaccount)
	{
		if (event->type() == QEvent::MouseButtonPress)
		{
			TurnToRegisterWindow();
			return true;
		}
	}
	return QWidget::eventFilter(Watched, event);
}

void Login::TurnToRegisterWindow()
{
	this->ui.stackedWidget->setCurrentWidget(ui.RegisterPage);
}


//override
void Login::mouseMoveEvent(QMouseEvent* event)
{
	const QPoint MoveTo = event->globalPos();
	QPoint TopLeft = this->pos();
	int disX = current_cursor_pos.x() - TopLeft.x();
	int disY = current_cursor_pos.y() - TopLeft.y();
	this->move(MoveTo.x() - disX, MoveTo.y() - disY);
	current_cursor_pos = MoveTo;
}

void Login::mousePressEvent(QMouseEvent* event)
{
	current_cursor_pos = event->globalPos();
}