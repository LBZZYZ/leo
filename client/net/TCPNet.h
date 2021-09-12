#ifndef _TCPNET_H_
#define _TCPNET_H_

#include "INet.h"

#pragma comment(lib, "ws2_32.lib")

class TCPNet : public INet
{

public:
	TCPNet();
	TCPNet(const char *Ip, const int Port);
	~TCPNet();

	bool SendData(const char *pszBuffer, const int nSendLen);
	void Connect(const char *Ip, const int Port);
	void DisConnect(const char *Ip, const int Port);
	bool RecvData(char *pszBuffer, const int nSendLen);
	void RecvDataThread(char *pszBuffer, const int nSendLen);

private:
	bool Init();
	void DeInit();

private:
	SOCKET client_socket;
	HANDLE m_hRecvThread;	//  接受连接的线程
	bool m_bThreadQuitFlag; //  线程退出
};

#endif //_TCPNET_H_