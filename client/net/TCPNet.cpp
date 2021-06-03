#include "TCPNet.h"
#include <process.h>
#include <qdebug.h>
#include "TCPThread.h"

TCPNet::TCPNet() :
	client_socket(0),
	m_hRecvThread(0),
	m_bThreadQuitFlag(true)
{
	thread_of_receiving_data = nullptr;
}


TCPNet::~TCPNet(void)
{
	this->DeInit();
}

bool TCPNet::Init()
{
	WORD wVersionRequested = MAKEWORD(2, 2);
	WSADATA wsaData;
	int err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0) 
	{
		return false;
	}
	if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2)
	{                              
		return false;
	}

	client_socket = ::socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if(client_socket == INVALID_SOCKET)
	{
		return false;
	}


	sockaddr_in addr;
	addr.sin_addr.S_un.S_addr = inet_addr(IP);
	addr.sin_family = AF_INET;
	addr.sin_port = htons(TCP_PORT);
	
	if (::connect(client_socket, (const sockaddr*)&addr, sizeof(addr)) == SOCKET_ERROR)
	{
		return false;
	}
	return true;
	start_message_loop();
}

void TCPNet::start_message_loop()
{
	thread_of_receiving_data = new TcpThread(nullptr, (CallBack_DealData*)&CallBack);
}

void TCPNet::DeInit()
{

	m_bThreadQuitFlag = false;

	if(client_socket != 0)
	{
		::closesocket(client_socket);
		client_socket = 0;
	}

	::WSACleanup();
}
bool TCPNet::SendData(const char* pszBuffer, const int nSendLen)
 {
	if (client_socket == 0 || pszBuffer == 0 || nSendLen <= 0)
		return false;

	if (::send(client_socket, pszBuffer, nSendLen, 0) <= 0)
		return false;

	return true;
}


unsigned int __stdcall TCPNet::RecvThreadProc(TCPNet * pVoid, CallBack_DealData callback)
{
	TCPNet *pThis = (TCPNet*)pVoid;


	while(pVoid->m_bThreadQuitFlag){
		int nRecvLen = 0;
		if (recv(pThis->client_socket, (char*)&nRecvLen, 4, 0) <= 0)
		{			
			int nError = WSAGetLastError();
			if (WSAECONNRESET == nError)   // 客户端已经关闭
				break;
		}

		int nOffset = 0;
		char *pszRecvBuffer = new char[nRecvLen];
		while (1)
		{
			int nLen = recv(pThis->client_socket, pszRecvBuffer + nOffset, nRecvLen - nOffset, 0);
			if (nLen <= 0)
			{
				int nError = WSAGetLastError();
				if (WSAECONNRESET == nError)
					break;
			}

			nOffset = nOffset + nLen;
			if (nOffset >= nRecvLen)
				break;
		}

		callback(pszRecvBuffer, nRecvLen);

		delete []pszRecvBuffer;
		pszRecvBuffer = 0;
	}
	return 0;
}