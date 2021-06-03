#ifndef _LOGIN_H_
#define _LOGIN_H_

#include <QtWidgets/QWidget>
#include "ui_login.h"
#include <qmovie.h>
#include <Qsystemtrayicon>
#include "qevent.h"
#include <QLineEdit>
#include "./../base/QAvatar.h"
#include "../build/path.h"

class Login : public QWidget
{
	Q_OBJECT

public slots:
	void TurnToLoginWindow();
	void TurnToRegisterWindow();
	bool IsRememberPasswordChecked();
	void login();
	void CloseWindow();
	void OnAccountChanged(int current_index);
	
public:
	Login(QWidget* parent = 0);
	~Login();
	void InitWindow();
	void RegisterWatchedObject();
	void LoadLocalSavedUser();
	void ConnectSignalSlot(void);

	void mouseMoveEvent(QMouseEvent* event);
	void mousePressEvent(QMouseEvent *event);
	bool eventFilter(QObject* Watched, QEvent* event);
	
	
private:
	QPoint current_cursor_pos;
	QLineEdit* Num;
	QString passWord;
	QMap<QString, QString> account_password;

	Ui::Login ui;
};

#endif // _LOGIN_H_
