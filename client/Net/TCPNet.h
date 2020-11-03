#pragma once
#include "INet.h"
#include "Agency/Agency.h"
#include "Protocol/Protocol.h"
#include <iostream>
using namespace std;

#pragma comment(lib,"ws2_32.lib")



class CTCPNet : public INet
{
private:
	CAgency *m_Agency;
	SOCKET m_socketClient;				//  监听socket
	HANDLE m_hRecvThread;			 //  接受连接的线程
	bool m_bThreadQuitFlag;			//  线程退出
public:
	CTCPNet(CAgency *agency);
	~CTCPNet(void);
public:
	bool InitNet();
	void UnInitNet();
	bool SendTCPData(const char* pszBuffer,int nSendLen);
public:  
	static unsigned int __stdcall RecvThreadProc( CTCPNet * );      //  接收数据的线程
};

