#include "UDPNet.h"
#include "Protocol/Protocol.h"
#include <process.h>
#include <functional>
#include <iostream>
#include "qdebug.h"
//using namespace std;


CUDPNet::CUDPNet(CAgency *pAgency)
{
	m_pAgency = pAgency;
	m_socketClient = 0;
	m_hAcceptThread = 0;
	m_bQuitThread = true;
}

CUDPNet::~CUDPNet()
{
	this->UnInitNet();
}

bool CUDPNet::InitNet()
{
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;

	wVersionRequested = MAKEWORD(2, 2);
	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0)
		return false;

	if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2)
		return false;
	else
		printf("The Winsock 2.2 dll was found okay\n");

	m_socketClient = ::socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (m_socketClient == INVALID_SOCKET)
		return false;

	sockaddr_in serverAddr;
	serverAddr.sin_addr.S_un.S_addr = INADDR_ANY;
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(UDP_PORT);
	if(::bind(m_socketClient, (const sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
		return false;
	qDebug() << inet_ntoa(serverAddr.sin_addr);
	
	//m_hAcceptThread = (HANDLE)_beginthreadex(0, 1000, &CUDPNet::RecvThreadProc, this, 0, 0);
	//if (m_hAcceptThread == 0)
	//	return false;

	return true;
}

void CUDPNet::UnInitNet()
{
	m_bQuitThread = false;

	/*if (m_hAcceptThread != 0)
	{
		if (WaitForSingleObject(m_hAcceptThread, 10) == WAIT_TIMEOUT)
			TerminateThread(m_hAcceptThread, 0);
		CloseHandle(m_hAcceptThread);
		m_hAcceptThread = 0;
	}*/

	if (m_socketClient != 0)
	{
		closesocket(m_socketClient);
		m_socketClient = 0;
	}

	WSACleanup();
}

bool CUDPNet::SendUDPData(ULONG uIP, const char *pszBuffer, int nLen)
{
 	if (pszBuffer == 0)
		return false;

	sockaddr_in clientAddr;
	int nLenAddr = sizeof(clientAddr);
	clientAddr.sin_addr.S_un.S_addr = uIP;
	qDebug() << inet_ntoa(clientAddr.sin_addr);
	clientAddr.sin_family = AF_INET;
	clientAddr.sin_port = htons(UDP_PORT);
	if (sendto(m_socketClient, pszBuffer, nLen, 0, (sockaddr*)&clientAddr, nLenAddr) <= 0)
		return false;

	return true;
}


unsigned int __stdcall CUDPNet::RecvThreadProc(CUDPNet *pVoid)
{
	CUDPNet *pThis = (CUDPNet*)pVoid;
	char buf[UDP_RECV_BUFFER_SIZE] = { 0 };
	sockaddr_in clientAddr;
	while (pThis->m_bQuitThread)
	{
		ZeroMemory(buf, UDP_RECV_BUFFER_SIZE);
		int nLen = sizeof(clientAddr);
		int nRecvLen = recvfrom(pThis->m_socketClient, buf, UDP_RECV_BUFFER_SIZE, 0, (sockaddr*)&clientAddr, &nLen);
		if (nRecvLen > 0)
		{
			pThis->m_pAgency->DealUDPData(clientAddr.sin_addr.S_un.S_addr, buf, nRecvLen);
		}
	}
	return 0;
}
