#include "Login.h"
#include <QWidget>
#include <QApplication>
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	Login *window = new Login;
	window->show();

	return a.exec();
}



