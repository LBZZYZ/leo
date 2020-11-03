#ifndef UdpThread_H
#define UdpThread_H

#include <QThread>
#include "Net\UDPNet.h"
class UdpThread : public QThread
{
	Q_OBJECT
		signals:
public:
	UdpThread(INet*udp ,QObject *parent =nullptr);
	~UdpThread();
	void run();
	
private:
	CUDPNet * m_udp;
private:
	void uninitThread();
};

#endif // UdpThread_H
