#include "UDPNet.h"
#include "Protocol/Protocol.h"
#include <process.h>
#include <functional>
#include <iostream>
#include "qdebug.h"
//using namespace std;


UDPNet::UDPNet(Agency *pAgency)
{
	m_pAgency = pAgency;
	client_socket = 0;
	m_hAcceptThread = 0;
	m_bQuitThread = true;
}

UDPNet::~UDPNet()
{
	this->DeInit();
}

bool UDPNet::Init()
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

	client_socket = ::socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (client_socket == INVALID_SOCKET)
		return false;

	sockaddr_in serverAddr;
	serverAddr.sin_addr.S_un.S_addr = INADDR_ANY;
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(UDP_PORT);
	if(::bind(client_socket, (const sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
		return false;
	qDebug() << inet_ntoa(serverAddr.sin_addr);
	
	//m_hAcceptThread = (HANDLE)_beginthreadex(0, 1000, &UDPNet::RecvThreadProc, this, 0, 0);
	//if (m_hAcceptThread == 0)
	//	return false;

	return true;
}

void UDPNet::DeInit()
{
	m_bQuitThread = false;

	/*if (m_hAcceptThread != 0)
	{
		if (WaitForSingleObject(m_hAcceptThread, 10) == WAIT_TIMEOUT)
			TerminateThread(m_hAcceptThread, 0);
		CloseHandle(m_hAcceptThread);
		m_hAcceptThread = 0;
	}*/

	if (client_socket != 0)
	{
		closesocket(client_socket);
		client_socket = 0;
	}

	WSACleanup();
}

bool UDPNet::SendData(ULONG uIP, const char *pszBuffer, int nLen)
{
 	if (pszBuffer == 0)
		return false;

	sockaddr_in clientAddr;
	int nLenAddr = sizeof(clientAddr);
	clientAddr.sin_addr.S_un.S_addr = uIP;
	clientAddr.sin_family = AF_INET;
	clientAddr.sin_port = htons(UDP_PORT);
	if (sendto(client_socket, pszBuffer, nLen, 0, (sockaddr*)&clientAddr, nLenAddr) <= 0)
		return false;

	return true;
}


unsigned int __stdcall UDPNet::RecvThreadProc(UDPNet *pVoid, CallBack_DealData callback)
{
	UDPNet *pThis = (UDPNet*)pVoid;
	char buf[UDP_RECV_BUFFER_SIZE] = { 0 };
	sockaddr_in clientAddr;
	while (pThis->m_bQuitThread)
	{
		ZeroMemory(buf, UDP_RECV_BUFFER_SIZE);
		int nLen = sizeof(clientAddr);
		int nRecvLen = recvfrom(pThis->client_socket, buf, UDP_RECV_BUFFER_SIZE, 0, (sockaddr*)&clientAddr, &nLen);
		if (nRecvLen > 0)
		{
			callback(clientAddr.sin_addr.S_un.S_addr, buf, nRecvLen);
		}
	}
	return 0;
}
