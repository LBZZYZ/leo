#include "Mediator\Mediator.h"
#include "Net\UDPNet.h"
#include "Agency\AgencyUDP.h"
#include "UDPVerify\UDPVerify.h"
#include "NetThread\UdpThread.h"
#include "chat/qchatwindow.h"
#include "Protocol/Protocol.h"
#include "Net/INet.h"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Mediator mediator;

	//ÁÄÌì´°¿Úµ÷ÊÔ
	/*QChatWindow *p = new QChatWindow;
	p->show();*/
	return a.exec();		
}



