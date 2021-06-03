#include "TcpThread.h"

TcpThread::TcpThread(INet* tcp, CallBack_DealData callback, QObject *parent)
{
	m_pTcp =(TCPNet*)tcp;
}

TcpThread::~TcpThread()
{
	this->DeInit();
}
void TcpThread::run()
{
		TCPNet::RecvThreadProc(this->m_pTcp, (CallBack_DealData*)&CallBack);
}
void TcpThread::DeInit()
{
	if (isRunning())
	{
		QThread::terminate();
		QThread::wait(100);
	}
}