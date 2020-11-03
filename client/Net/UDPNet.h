#pragma once
#include "INet.h"
#include "Agency\Agency.h"

#pragma comment(lib,"ws2_32.lib")


class CUDPNet : public INet
{
public:

	SOCKET m_socketClient;
	HANDLE m_hAcceptThread;
	bool m_bQuitThread;
	CAgency *m_pAgency;
public:
	CUDPNet(CAgency *pAgency);
	virtual ~CUDPNet();
public:
	virtual bool InitNet();
	virtual void UnInitNet();
	virtual bool SendUDPData(ULONG uIP,const char *pszBuffer, int nLen);
	
public:
	static unsigned int __stdcall RecvThreadProc(CUDPNet *);
};