#include "UdpThread.h"
#include "qdebug.h"
#include "qmutexLocker"
#include "Net\INet.h"
UdpThread::UdpThread(INet*udp,QObject *parent)
	: QThread(parent)
  {		
	m_udp =(CUDPNet*) udp;

}

UdpThread::~UdpThread()
{
	uninitThread();
}

void UdpThread::run()
{
		CUDPNet::RecvThreadProc(m_udp);
}
void UdpThread::uninitThread()
{

	//  结束m_hAcccptThread 线程
	if (!isRunning())
	{
		QThread::terminate();
		QThread::wait(100);
	}
}
