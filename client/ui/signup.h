#ifndef _SIGNUP_H
#define _SIGNUP_H

#include <QtWidgets/QWidget>
#include "ui_login.h"
#include <qmovie.h>
#include <Qsystemtrayicon>
#include "qevent.h"
#include "../net/Protocol/Protocol.h"

//extern long long userId;
class Signup : public QWidget
{
	Q_OBJECT

public:
	Signup(QWidget* parent = 0);
	//~Signup();
	//void InitWindow();

public slots:
	//void TurnToLoginWindow();
	void MatchPassword();
	void MatchAccount();
	void Register();
	//void CloseWindow();
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
	Ui::Login ui;
};
#endif // !_SIGNUP_H
