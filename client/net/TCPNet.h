#pragma once

#include "INet.h"

#include "Protocol/Protocol.h"

#pragma comment(lib,"ws2_32.lib")

class TCPNet : public INet
{
public:
	SOCKET client_socket;
	HANDLE m_hRecvThread;			//  接受连接的线程
	bool m_bThreadQuitFlag;			//  线程退出
public:
	TCPNet();
	~TCPNet(void);
public:
	bool Init();
	void DeInit();
	bool SendData(const char* pszBuffer, const int nSendLen);
	static unsigned int __stdcall RecvThreadProc(TCPNet* , CallBack_DealData);
	 void start_message_loop();
};

