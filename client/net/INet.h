#pragma once
#include <WinSock2.h>
#include <Ws2tcpip.h>
#include <QObject>

#include "Agency.h"
#include "Thread.h"

class INet: public QObject
{
	Q_OBJECT

public:
	INet() {}
	virtual ~INet() {}
public:
	virtual bool Init() = 0;
	virtual void DeInit() = 0;
	virtual bool SendData(const char* pszBuffer, const int nSendLen){ return false; }

protected:        
	NetThread* thread_of_receiving_data                                                                 ;
};