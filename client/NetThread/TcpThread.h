#ifndef TCPTHREAD_H
#define TCPTHREAD_H

#include <QThread>
#include <Net\TCPNet.h>
class TcpThread : public QThread
{
	Q_OBJECT

public:
	TcpThread(INet* tcp,QObject *parent =nullptr);
	~TcpThread();
	void run();

private:
	CTCPNet* m_pTcp;
private:
	void uninitpThread();
};

#endif // TCPTHREAD_H
