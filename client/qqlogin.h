#ifndef QQLOGIN_H
#define QQLOGIN_H

#include <QtWidgets/QWidget>
#include "ui_qqlogin.h"
#include <qmovie.h>
#include <Qsystemtrayicon>
#include "qevent.h"
#include <Protocol\Protocol.h>
#include <QAvatar.h>

#pragma warning (disable:4786)
extern long long userId;
class QQLogin : public QWidget
{
	Q_OBJECT



public:
	QQLogin(QWidget *parent = 0);
	~QQLogin();
	void InitWindow();

public slots:
	void turnPage2();
	void rememberpassword();
	void login();
	void MyClose();


signals:
	void SendTcpRQ(const char*, int);
signals:
	void SendUdpRQ(const char*, int,int);
	

public:
	virtual void  mouseMoveEvent(QMouseEvent* event);
	virtual void mousePressEvent(QMouseEvent *event);

	bool eventFilter(QObject* Watched, QEvent* event);
	

private:
	
	//鼠标按压的坐标
	QPoint mp;
	QMovie starMovie;
	//QQ号码 编辑框
	QLineEdit* Num;
	
	/*QMap< QLineEdit*, bool > MatchFalgs;*/

public:
	QString passWord;
	int timeId;
	int timeId2;
	int sec;
	QAvatar* m_Avatar;
	// int countflault;//注册窗口
	Ui::QQLoginClass ui;

	
};

#endif // QQLOGIN_H
