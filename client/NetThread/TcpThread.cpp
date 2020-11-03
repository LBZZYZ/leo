#include "TcpThread.h"
#include "Net\INet.h"
TcpThread::TcpThread(INet* tcp, QObject *parent)
	: QThread(parent)
{
	m_pTcp =(CTCPNet*)tcp;

}

TcpThread::~TcpThread()
{

	uninitpThread();
}
void TcpThread::run()
{
		CTCPNet::RecvThreadProc(m_pTcp);
}
void TcpThread::uninitpThread()
{

	//  结束m_hAcccptThread 线程
	if (isRunning())
	{
		QThread::terminate();
		QThread::wait(100);
	}
}