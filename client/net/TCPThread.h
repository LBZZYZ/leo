#ifndef TCPTHREAD_H
#define TCPTHREAD_H

#include "Thread.h"
#include "TCPNet.h"


class TcpThread : public NetThread
{
	Q_OBJECT

public:
	TcpThread(INet* tcp, CallBack_DealData callback, QObject *parent = nullptr);
	~TcpThread();
	void run();

private:
	TCPNet* m_pTcp;
	CallBack_DealData call_back;
private:
	void DeInit();
};

#endif // TCPTHREAD_H
