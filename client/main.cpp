#include "Mediator\Mediator.h"
#include "Net\UDPNet.h"
#include "Agency\AgencyUDP.h"
#include "UDPVerify\UDPVerify.h"
#include "NetThread\UdpThread.h"
#include "Protocol/Protocol.h"
#include "Net/INet.h"
#include "QClient/qclient.h"
#include "protobuf/leo.pb.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	list<FRINENDLISTMSG> list;
	FRINENDLISTMSG msg;
	msg.avatar.load("./userData/280761575/FriendAvatar/19846121581.jpg");
	msg.name = "ZZ Zhang";
	msg.remark = "";
	msg.userid = 208761575;
	msg.signature = "this is a signature";

	list.push_back(msg);

	QClient client(&list, nullptr);
	client.show();

	return a.exec();		
}



