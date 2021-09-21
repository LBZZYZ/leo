
#include <QWidget>
#include <QApplication>

#include "net/EventDispatch.h"
#include "ui/Login.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	Login *login = new Login;
	login->show();
	
	EventDispatch *dispatcher = EventDispatch::GetInstance();
	// dispatcher->StratEventLoop();

	return a.exec();
}



