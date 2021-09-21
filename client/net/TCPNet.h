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


	void Connect(const char *Ip, const int Port);
	void DisConnect();

	bool SendData(const char *pszBuffer, const int nSendLen);
	bool RecvData(char **recv_buf, int *len);
	static void RecvDataThread(char *pszBuffer, const int nSendLen);	//Thread work function

private:
	bool Init();
	void DeInit();
	void HandleError(int err);

private:
	SOCKET client_socket;
};

#endif //_TCPNET_H_