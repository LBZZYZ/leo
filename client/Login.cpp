#include "login.h"
#include "../net/Protocol/Protocol.h"
#include <QMouseEvent>
#include <QPushButton>
#include <QMessagebox>
#include <qpropertyanimation.h>	
#include <QFile>
#include <QPainter>
#include "../net/TCPAgency.h"

Login::Login(QWidget *parent)
	: QWidget(parent)
{	    
	ui.setupUi(this);

	ConnectSignalSlot();
	InitWindow();
	LoadLocalSavedUser();
	
}

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
	CTCPAgency* agency = CTCPAgency::GetInstance();
	agency->DealData((char*)&stru_login_rq, sizeof(STRU_LOGIN_RQ));
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

void Login::LoadLocalSavedUser()
{
	QFile user_info("LoginWindowUserInfo");
	if (!user_info.open(QIODevice::ReadWrite | QIODevice::Text))
		return;
	QTextStream file_paser(&user_info);
	file_paser.setCodec("UTF-8");
	while (!file_paser.atEnd())
	{
		QString line = file_paser.readLine();
		QRegExp pattern("(.*):(.*)");
		line.indexOf(pattern);
		ui.m_userNameCom->addItem(pattern.cap(1));
		account_password[pattern.cap(1)] = pattern.cap(2);
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