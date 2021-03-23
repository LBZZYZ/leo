#include "AddFriendWindow.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	AddFriendWindow window(nullptr);
	window.show();

	return a.exec();
}



