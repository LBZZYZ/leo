#ifndef _SIGNUP_H
#define _SIGNUP_H

#include <QtWidgets/QWidget>
#include "ui_qqlogin.h"
#include <qmovie.h>
#include <Qsystemtrayicon>
#include "qevent.h"
#include <Protocol\Protocol.h>
#pragma warning (disable:4786)
extern long long userId;
class Signup : public QWidget
{
	Q_OBJECT

public:
	Signup(QWidget* parent = 0);
	//~Signup();
	//void InitWindow();

public slots:
	//void turnPage2();
	void MatchPassword();
	void MatchAccount();
	void Register();
	//void MyClose();
	void MathPhoneNumber();

signals:
	void SendTcpRQ(const char*, int);
signals:
	void SendUdpRQ(const char*, int, int);

public:
	QString passWord;
	int timeId;
	int timeId2;
	int sec;
	Ui::QQLoginClass ui;
};
#endif // !_SIGNUP_H
