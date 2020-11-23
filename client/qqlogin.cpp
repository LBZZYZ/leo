
#include "qqlogin.h"
#include "QGraphicsDropShadowEffect"
#include <QMouseEvent>
#include <QDebug>
#include "qpixmap.h"
#include "qbitmap.h"
#include <qmenu.h>
#include "qclient.h"
#include <string>
#include <QMessagebox>
#include "qdebug.h"
#include <qpropertyanimation.h>		//渐变关闭头文件


//#include "./Mediator/Mediator.h"
using namespace std;
class Mediator;

QQLogin::QQLogin(QWidget *parent)
	: QWidget(parent)
{	    
	ui.setupUi(this);

	timeId = 0;
	timeId2 = 0;
	sec = 0;
	InitWindow();
	
	//信号和槽
	
	//Mediator* m =new Mediator;
	//connect(ui.pushButton,&QPushButton::pressed, this,&QQLogin::turnPage);
	connect(ui.m_minbutton,&QPushButton::pressed, this, &QQLogin::showMinimized);
	connect(ui.m_closebutton,&QPushButton::pressed, this, &QQLogin::MyClose);		/*渐变关闭*/
	connect(ui.m_rememberpw,&QCheckBox::stateChanged, this, &QQLogin::rememberpassword);
	connect(ui.m_pLoginButton,&QPushButton::pressed, this, &QQLogin::login);
	connect(ui.m_pRegisterCancel, &QPushButton::pressed, this, &QQLogin::turnPage2);
	
	

}

QQLogin::~QQLogin()
{
	
}
void QQLogin::InitWindow()
{
//初始化清除标志
//this->resize(QSize(1000/*546 + 8 + 2*/, 424 + 8 + 2));
//this->setWindowFlags(Qt::FramelessWindowHint | /*Qt::WindowStaysOnTopHint | */Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint);
//圆角
//this->setAttribute(Qt::WA_TranslucentBackground, true);


//按钮贴图
//QIcon icon;
//icon.addFile(tr("Resources/close.png"));
//ui.m_closebutton->setIcon(icon);
//icon.addFile(tr("Resources/minbutton.png"));
//ui.m_minbutton->setIcon(icon);


//动画	
//starMovie.setFileName(QString::fromUtf8("Resources/back.gif"));
//ui.label->setMovie(&starMovie);
//ui.label->setScaledContents(true);
//ui.m_closebutton->raise();
//starMovie.start();

//头像
m_Avatar = new QAvatar(ui.page);
m_Avatar->installEventFilter(this);

ui.qLabel_HeadIcon->installEventFilter(this);
ui.m_passwordlineedit->installEventFilter(this);
ui.m_userNameCom->installEventFilter(this);
ui.m_registaccount->installEventFilter(this);
ui.m_userNameCom->installEventFilter(this);

ui.qLineEdit_UserName->installEventFilter(this);//page3注册账号框
ui.qLineEdit_PassWord->installEventFilter(this);

////阴影
//QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect;
//effect->setOffset(3, 3);
//effect->setColor(QColor(0, 0, 0, 80));
//effect->setBlurRadius(10);
//ui.frame->setGraphicsEffect(effect);

//设置登陆窗口密码框
ui.m_passwordlineedit->setEchoMode(QLineEdit::Password);
ui.m_passwordlineedit->setPlaceholderText(QString("密码"));

}

//转到登录界面窗口
void QQLogin::turnPage2()
{
	this->ui.stackedWidget->setCurrentWidget(ui.page);

}
//处理记住密码
void QQLogin::rememberpassword()
{
	if (ui.m_rememberpw->checkState() == Qt::Checked)
	{
		
	}

}
//处理登陆按钮
void  QQLogin::login()
{
	if (ui.m_userNameCom->itemText(0).isEmpty() || ui.m_passwordlineedit->text().isEmpty())return;
	STRU_LOGIN_RQ stru_login_rq;
	stru_login_rq.llUserID = ui.m_userNameCom->currentText().toLongLong();
	stru_login_rq.packtype = PROTOCOL_LOGIN_RQ;
	Qstringtochar(stru_login_rq.szPassWord,ui.m_passwordlineedit->text(),PASSWORD_SIZE);
	userId = stru_login_rq.llUserID;//全局用户id
	emit SendTcpRQ((const char*)&stru_login_rq, sizeof(STRU_LOGIN_RQ));
	qDebug() << endl;
}
//鼠标移动事件 控制窗口移动
void QQLogin::mouseMoveEvent(QMouseEvent * event)
{
	if (event->buttons() == Qt::LeftButton && (mp != this->frameGeometry().topLeft()))
	{
		this->move(event->globalPos() - mp);
	}
}
//鼠标按压事件 控制窗口移动
void QQLogin::mousePressEvent(QMouseEvent * event)
{   
	mp = this->frameGeometry().topLeft();
	/*if (event->buttons() == Qt::LeftButton&&(event->pos().x()<ui.label->rect().bottomRight().x() && event->pos().y()<ui.label->rect().bottomRight().y()))
	{
		mp = event->globalPos()-this->frameGeometry().topLeft();
	}*/
}
//事件处理器
bool QQLogin::eventFilter(QObject * Watched, QEvent * event)
{
	//头像选择动画
	if (Watched == ui.qLabel_HeadIcon || Watched == m_Avatar)
	{
		if (event->type() == QEvent::Enter)
		{
			timeId = m_Avatar->startTimer(10);		//设置一个十毫秒的定时器
			if (timeId2 != 0)
				m_Avatar->killTimer(timeId2);
			
			return true;
		}
		if (event->type() == QEvent::Leave)
		{
			timeId2 = m_Avatar->startTimer(10);
			m_Avatar->killTimer(timeId);

			
			return true;
		}
		if (event->type() == QEvent::Timer)
		{
			QTimerEvent *qe = static_cast<QTimerEvent*>(event);
			if (qe->timerId() == timeId)
			{
				sec = 5;
				if (m_Avatar->geometry().x() >=100)
				{
					sec = 0;
				}
				m_Avatar->move(m_Avatar->geometry().x() + sec, m_Avatar->geometry().y());
				return true;
			}
			if (qe->timerId() == timeId2)
			{
				sec = 5;
				if (m_Avatar->geometry().x() <= 0)
				{
					sec = 0;
				}
				m_Avatar->move(m_Avatar->geometry().x() - sec, m_Avatar->geometry().y());
				qe->accept();
				return true;		
			}
		}

	}
	//转到注册窗口界面page_3
	if (Watched == ui.m_registaccount)
	{
		if (event->type() == QEvent::MouseButtonPress)
		{
			ui.stackedWidget->setCurrentWidget(ui.page_3);
			return true;
		}
	}
	return QWidget::eventFilter(Watched, event);
}
/*渐变关闭*/
void QQLogin::MyClose()
{
	QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity");
	animation->setDuration(1000);
	animation->setStartValue(1);
	animation->setEndValue(0);
	animation->start();
	connect(animation, SIGNAL(finished()), this, SLOT(close()));
}
