#include "TCPNet.h"
#include <process.h>
#include <qdebug.h>
#include <iostream>
#include <thread>

#define _WINSOCK_DEPRECATED_NO_WARNINGS

TCPNet::TCPNet()
{
	this->Init();
}

TCPNet::TCPNet(const char *Ip, const int Port)
{
	this->Init();
	this->Connect(Ip, Port);
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

	client_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (client_socket == INVALID_SOCKET)
	{
		return false;
	}
}

// @Public API : It's used to connect server through ip & port;

void TCPNet::Connect(const char *Ip, const int Port)
{
	sockaddr_in addr;
	addr.sin_addr.S_un.S_addr = inet_addr(Ip);
	addr.sin_family = AF_INET;
	addr.sin_port = htons(Port);

	try
	{
		connect(client_socket, (const sockaddr *)&addr, sizeof(addr));
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}

// @Public API : It's used to send data through exist connection;

bool TCPNet::SendData(const char *pszBuffer, const int nSendLen)
{
	try
	{
		::send(this->client_socket, pszBuffer, nSendLen, 0);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
		return false;
	}

	return true;
}

bool TCPNet::RecvData(char *pszBuffer, const int nSendLen)
{
	return false;
	// std::thread recv_thread(RecvDataThread, pszBuffer, nSendLen);
	// int nRecvLen = 0;
	// 	if (recv(this->client_socket, (char *)&nRecvLen, 4, 0) <= 0)
	// 	{
	// 		int nError = WSAGetLastError();
	// 		if (WSAECONNRESET == nError) // 客户端已经关闭
	// 			break;
	// 	}

	// 	int nOffset = 0;
	// 	char *pszRecvBuffer = new char[nRecvLen];
	// 	while (1)
	// 	{
	// 		int nLen = recv(this->client_socket, pszRecvBuffer + nOffset, nRecvLen - nOffset, 0);
	// 		if (nLen <= 0)
	// 		{
	// 			int nError = WSAGetLastError();
	// 			if (WSAECONNRESET == nError)
	// 				break;
	// 		}

	// 		nOffset = nOffset + nLen;
	// 		if (nOffset >= nRecvLen)
	// 			break;
	// 	}

	// 	callback(pszRecvBuffer, nRecvLen);

	// 	delete[] pszRecvBuffer;
	// 	pszRecvBuffer = 0;
}

void TCPNet::RecvDataThread(char *pszBuffer, const int nSendLen)
{
}


void TCPNet::DisConnect(const char *Ip, const int Port)
{

}

TCPNet::~TCPNet(void)
{
	this->DeInit();
}

void TCPNet::DeInit()
{

	m_bThreadQuitFlag = false;

	if (client_socket != 0)
	{
		::closesocket(client_socket);
		client_socket = 0;
	}

	::WSACleanup();
}


void main()
{
	TCPNet *net = new TCPNet;
	net->Connect();
}