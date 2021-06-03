#include "UdpThread.h"
#include "qmutexLocker"
#include "INet.h"

UdpThread::UdpThread(INet*udp, CallBack_DealData callback, QObject *parent)
  {		
	m_udp =(UDPNet*) udp;
}

UdpThread::~UdpThread()
{
	DeInit();
}

void UdpThread::run()
{
	UDPNet::RecvThreadProc(m_udp, CallBack);
}
void UdpThread::DeInit()
{
	if (!isRunning())
	{
		QThread::terminate();
		QThread::wait(100);
	}
}
