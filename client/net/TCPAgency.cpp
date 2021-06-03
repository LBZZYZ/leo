#include "TCPAgency.h"
#include "TCPNet.h"
#include "TCPThread.h"

CTCPAgency::CTCPAgency()
{
	this->Init();
}
CTCPAgency::~CTCPAgency()
{
	this->DeInit();
}

PROTOCOL_BEGIN_TCP
		PROTOCOL(PROTOCOL_LOGIN_RS, &CTCPAgency::LoginRS)
		PROTOCOL(PROTOCOL_SEARCH_USER_RS, &CTCPAgency::SearchRS)
		PROTOCOL(PROTOCOL_USER_DELETE_RS, &CTCPAgency::DeleteRS)
		PROTOCOL(PROTOCOL_GET_FRIENDLIST_RS, &CTCPAgency::GetFriendListRS)
		PROTOCOL(PROTOCOL_GET_FRIENDLIST_RQ, &TCPNet::SendData)
PROTOCOL_END_TCP


bool CTCPAgency::Init()
{
	net = new TCPNet;
	if (net->Init() == false)
		return false;
	return true;
}
void CTCPAgency::DeInit()
{
	delete net;
	net = nullptr;
}

bool CTCPAgency::DealData(char *pszBuffer, int nLen)
{
	PackType packtype = (PackType)*pszBuffer;
	STRU_ONLINE_MAP_TCP *pTemp = OnLineTCPMap;
	while (1)
	{
		if (pTemp->packtype == 0 && pTemp->pfn == 0)
			return false;

		if (pTemp->packtype == packtype)
		{
			(this->*(pTemp->pfn))(pszBuffer, nLen);
			return true;
		}

		pTemp++;
	}

	return true;
}

bool CTCPAgency::LoginRS(const char *pszBuffer, const int nLen)
{
	STRU_LOGIN_RS* login_RS = (STRU_LOGIN_RS*)pszBuffer;

	if (login_RS->result == SUCCEED)
	{
		emit LoginRSSignal(true);
		return true;
	}
	else
	{
		emit LoginRSSignal(false);
		return true;
	}
	
}
bool CTCPAgency::SearchRS(const char *pszBuffer,const int nLen)
{

	emit  SerchRsSiganl((STRU_SEARCH_USER_RS*)pszBuffer);
	return true;
}
bool CTCPAgency::DeleteRS(const char *pszBuffer, const int nLen)
{
	STRU_SEARCH_DELETE_RS* rs = (STRU_SEARCH_DELETE_RS*)pszBuffer;
	if(rs->result)
	emit DeletefrRSsignal(true);
	else
	emit DeletefrRSsignal(false);
	return true;
}




/*********************************************
函数名       : GetFriendListRS
函数功能描述 : 接收服务器发回的好友列表回复包，通过发送信号的方式交给Mediator类中的槽函数处理
函数参数     : char *pszBuffer int nLen
函数返回值   : bool 成功返回true 失败返回false
函数作者     : 李柄志
函数创建日期 : 2019.07.23
函数修改日期 : *
修改人       : *
修改原因     : *
版本         : 1.0
历史版本     : 无
*********************************************/
bool CTCPAgency::GetFriendListRS(const char *pszBuffer, const int nLen)
{
	if (pszBuffer == NULL || nLen <= 0)
		return false;
	emit DealFriendListSignal(pszBuffer,nLen);
	return true;
}


CTCPAgency* CTCPAgency::GetInstance()
{
	if (agency == nullptr)
	{
		agency = new CTCPAgency;
	}
	return agency;
}