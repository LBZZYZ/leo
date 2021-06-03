#pragma once
#include "INet.h"
#include "Agency.h"

#pragma comment(lib,"ws2_32.lib")


class UDPNet : public INet
{
public:

	SOCKET client_socket;
	HANDLE m_hAcceptThread;
	bool m_bQuitThread;
	Agency *m_pAgency;
public:
	UDPNet(Agency *pAgency);
	virtual ~UDPNet();
public:
	virtual bool Init();
	virtual void DeInit();
	virtual bool SendData(ULONG uIP,const char *pszBuffer, int nLen);
	
public:
	static unsigned int __stdcall RecvThreadProc(UDPNet *, CallBack_DealData);
};