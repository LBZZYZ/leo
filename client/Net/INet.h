#pragma once
#include <WinSock2.h>
#include <Ws2tcpip.h>
#include <QObject>
class INet: public QObject
{
	Q_OBJECT
public:
	INet() {}
	virtual ~INet() {}
public:
	virtual bool InitNet() = 0;
	virtual void UnInitNet() = 0;
	virtual bool SendTCPData(const char* pszBuffer, int nSendLen){ return false; }
	virtual bool SendUDPData(ULONG uIP, const char* pszBuffer, int nSendLen){ return false; }
};