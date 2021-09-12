#ifndef _INET_H_
#define _INET_H_

#include <WinSock2.h>
#include <Ws2tcpip.h>

class INet
{

public:
	INet() {}
	virtual ~INet() {}

	virtual void Connect(const char *Ip, const int Port) = 0;
	virtual void DisConnect(const char *Ip, const int Port) = 0;
	virtual bool SendData(const char *pszBuffer, const int nSendLen) { return false; }
	virtual bool RecvData(char *pszBuffer, const int nSendLen) { return true; }

protected:
	virtual bool Init() = 0;
	virtual void DeInit() = 0;

};

#endif //_INET_H_