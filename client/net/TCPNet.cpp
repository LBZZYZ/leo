#include "TCPNet.h"

#include <process.h>

#include <string>
#include <iostream>
#include <thread>

#define PRINT_LOG 1
#define _WINSOCK_DEPRECATED_NO_WARNINGS

#ifdef PRINT_LOG
#define DBG_LOG 	std::cout << "Func: " << __FUNCTION__ << "Line: " << __LINE__ << std::endl;
#else
#define DBG_LOG
#endif

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

	client_socket = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
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

	int err = connect(client_socket, (const sockaddr *)&addr, sizeof(addr));
	if(err < 0)
	{
		std::cout << "Func: " << __FUNCTION__ << ", Line: " << __LINE__ << std::endl;
		HandleError(err);
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

// @Public API : It's used to receive data from IM server.

bool TCPNet::RecvData(char **recv_buf, int *len)
{
	if(recv_buf == nullptr || len <= 0)
		exit(1);
	
	// step1: get message tpye.
	char* begin = *recv_buf;
	size_t read, remaining;
	int package_size = 0;
	const int package_header_size = 4;
	// std::thread recv_thread(TCPNet::RecvDataThread, pszBuffer, nSendLen);

	int err = recv(this->client_socket, (char*)&package_size, package_header_size, 0);
	if (err <= 0)
	{
		std::cout << "Func: " << __FUNCTION__ << ", Line: " << __LINE__ << std::endl;
		HandleError(err);
	}
		
	if(package_size > *len)
	{
		//re-allocate receive buffer
		delete *recv_buf;
		*recv_buf = new char[package_size];
		memset(*recv_buf, 0, package_size);
		*len = package_size;
	}

	// step2: save message to the buffer.

	read = remaining = package_size;
	
	while (remaining)
	{
		read = recv(this->client_socket, *recv_buf, remaining, 0);
		if (read <= 0)
			HandleError(err);

		begin += read;
		remaining -= read;
	}

	return true;
}

void TCPNet::RecvDataThread(char *pszBuffer, const int nSendLen)
{
	//TBD
}

// @Public API : It's used to disconncet server while has been connected by TCPNet::Connect.

void TCPNet::DisConnect()
{
	if (client_socket != 0)
	{
		::closesocket(client_socket);
		client_socket = 0;
	}

	::WSACleanup();
}

TCPNet::~TCPNet(void)
{
	this->DeInit();
}

void TCPNet::DeInit()
{
	this->DisConnect();
}



void TCPNet::HandleError(int err)
{
	std::cout << "errno:" << WSAGetLastError() << std::endl;
	exit(1);
}

// void main()
// {
// 	TCPNet *net = new TCPNet;
// 	net->Connect("39.108.143.167", 39999);

// 	int len = 12;
// 	char* recv_buf = new char[len];
// 	memset(recv_buf, 0, len);
// 	net->RecvData(&recv_buf, &len);
// 	std::cout << "RecvData recevied: " << recv_buf << std::endl;
// 	std::cout << "errno: " << WSAGetLastError() << std::endl;
// }