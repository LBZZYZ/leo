#ifndef UdpThread_H
#define UdpThread_H

#include "Thread.h"
#include "UDPNet.h"

class UdpThread : public NetThread
{
	Q_OBJECT

public:
	UdpThread(INet* udp, CallBack_DealData callback, QObject* parent = nullptr);
	~UdpThread();
	void run();

private:
	void DeInit();

private:
	UDPNet * m_udp;

};

#endif // UdpThread_H
