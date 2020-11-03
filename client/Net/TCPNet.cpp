#include "TCPNet.h"
#include <process.h>
#include <qdebug.h>

CTCPNet::CTCPNet(CAgency *Agency)
{
	m_Agency = Agency;
	m_socketClient = 0;
	m_hRecvThread = 0;
	m_bThreadQuitFlag = true;
}


CTCPNet::~CTCPNet(void)
{
	this->UnInitNet();
}

bool CTCPNet::InitNet()
{
	//  1.  加载库
	WORD wVersionRequested = MAKEWORD(2, 2);
	WSADATA wsaData;
	int err= WSAStartup(wVersionRequested, &wsaData);
	if (err != 0) 
	{
		return false;
	}
	if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2)
	{                              
		return false;
	}
	//  2.  创建socket 
	m_socketClient = ::socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if(m_socketClient == INVALID_SOCKET)
	{
		return false;
	}
	//  3.  连接

	sockaddr_in addr;
	addr.sin_addr.S_un.S_addr = inet_addr(IP);
	addr.sin_family = AF_INET;
	addr.sin_port = htons(TCP_PORT);
	
	if (::connect(m_socketClient, (const sockaddr*)&addr, sizeof(addr)) == SOCKET_ERROR)
	{
		qDebug() << "tcp连接失败" << WSAGetLastError();
		return false;
	}
	return true;
	//  4. 创建线程   让线程取接受连接
	//m_hRecvThread = (HANDLE)_beginthreadex(0,0,&CTCPNet::RecvThreadProc,this,0,0);
	//return true;
}
void CTCPNet::UnInitNet()
{
	//  线程退出
	m_bThreadQuitFlag = false;
	//  关闭socket
	if(m_socketClient != 0)
	{
		::closesocket(m_socketClient);
		m_socketClient = 0;
	}
	//  卸载库
	::WSACleanup();
}
bool CTCPNet::SendTCPData(const char* pszBuffer, int nSendLen)
 {
	if (m_socketClient == 0 || pszBuffer == 0 || nSendLen <= 0)
		return false;
	STRU_LOGIN_RQ* rq = (STRU_LOGIN_RQ*)pszBuffer;
	qDebug() << rq->llUserID;
	qDebug() << rq->szPassWord;
	/*if (send(m_socketClient, (const char*)&nSendLen, 4, 0) <= 0)
	{
		qDebug() << WSAGetLastError();
		return false;
	}*/

	if (send(m_socketClient, pszBuffer, nSendLen, 0) <= 0)
		return false;

	return true;
}


unsigned int __stdcall CTCPNet::RecvThreadProc( CTCPNet * pVoid)
{
	CTCPNet *pThis = (CTCPNet*)pVoid;

	//  接收数据
	while(pVoid->m_bThreadQuitFlag){
		int nRecvLen = 0;
		if (recv(pThis->m_socketClient, (char*)&nRecvLen, 4, 0) <= 0)
		{			
			int nError = WSAGetLastError();
			// 判断客户端有没有关闭
			if (WSAECONNRESET == nError)   // 客户端已经关闭
				break;
			cout << "error code:" << nError << endl;
		}

		int nOffset = 0;
		char *pszRecvBuffer = new char[nRecvLen];
		while (1)
		{
			int nLen = recv(pThis->m_socketClient, pszRecvBuffer + nOffset, nRecvLen - nOffset, 0);
			if (nLen <= 0)
			{
				int nError = WSAGetLastError();
				// 判断客户端有没有关闭
				if (WSAECONNRESET == nError)   // 客户端已经关闭
					break;
				cout << "error code:" << nError << endl;
			}

			nOffset = nOffset + nLen;
			if (nOffset >= nRecvLen)
				break;
		}

		pThis->m_Agency->DealTCPData(pThis->m_socketClient, pszRecvBuffer, nRecvLen);

		delete []pszRecvBuffer;
		pszRecvBuffer = 0;

		Sleep(100);
	}
	return 0;
}