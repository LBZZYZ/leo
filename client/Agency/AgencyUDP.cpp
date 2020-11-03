#include "AgencyUDP.h"
#include "Net/UDPNet.h"

#include "qdebug.h"
CUDPVerify* CUDPAgency::m_UDPverify = 0;
CUDPAgency::CUDPAgency()
{
	m_pNet = new CUDPNet(this);
	m_UDPverify = new CUDPVerify(this);
}
CUDPAgency::~CUDPAgency() 
{
	delete m_UDPverify;
	m_UDPverify = 0;
	delete m_pNet;
	m_pNet = 0;
}

PROTOCOL_BEGIN_UDP
	PROTOCOL_UDP(PROTOCOL_SERVER_RS,&CUDPAgency::ServerRes)
	PROTOCOL_UDP(PROTOCOL_REGISTER_RS,&CUDPAgency::RegisterRS)
	PROTOCOL_UDP(PROTOCOL_USER_ADD_RQ, &CUDPAgency::USER_ADD_RQ)
	PROTOCOL_UDP(PROTOCOL_USER_ADD_RS, &CUDPAgency::USER_ADD_RS)
	PROTOCOL_UDP(PROTOCOL_SEND_MSG_RQ, &CUDPAgency::Send_Msg_Rs)
PROTOCOL_END_UDP

bool CUDPAgency::ServerRes(ULONG uIP, char * pszBuffer, int nLen)
{
	STRU_SERVER_RS *ssRS = (STRU_SERVER_RS *)pszBuffer;

	list<STRU_VerifyNum *>::iterator iteVerNum = m_UDPverify->m_lstVerifyNum.begin();

	while (iteVerNum != m_UDPverify->m_lstVerifyNum.end())
	{
		if ((*iteVerNum)->vRes == VERIFIED)
		{
			(*iteVerNum)->nPackNum = ssRS->nPackNum;
			(*iteVerNum)->vRes = UNVERIFIED;
		}
		++iteVerNum;
	}

	if (iteVerNum == m_UDPverify->m_lstVerifyNum.end())
	{
		STRU_VerifyNum *svnum = new STRU_VerifyNum;
		svnum->nPackNum = ssRS->nPackNum;
		svnum->vRes = UNVERIFIED;
		m_UDPverify->m_lstVerifyNum.push_back(svnum);
	}
	return false;
}

bool CUDPAgency::RegisterRS(ULONG uIP, char * pszBuffer, int nLen)//注册回复
{
	STRU_REGISTER_RS* stregister_rs = (STRU_REGISTER_RS*)pszBuffer;
	if (/*stregister_rs->nPackNum == packId++ &&*/stregister_rs->result == SUCCEED)
	{
		emit RegisetrSignal(true);
		return true;
	}
	else
	{
	    emit RegisetrSignal(false);
		return true;
	}
	return false;
}
bool CUDPAgency::USER_ADD_RQ(ULONG uIP, char *pszBuffer, int nLen)//收到添加好友请求
{
	emit DealAddFrdRqSignal(pszBuffer, nLen);
	STRU_USER_ADD_RQ *p = (STRU_USER_ADD_RQ*)pszBuffer;
	return true;
}

bool CUDPAgency::USER_ADD_RS(ULONG uIP, char *pszBuffer, int nLen)//收到添加好友回复
{
	STRU_USER_ADD_RS* stregister_rs = (STRU_USER_ADD_RS*)pszBuffer;
	emit DealAddFrdRsSignal(pszBuffer,nLen);
	return true;
}


bool CUDPAgency::Send_Msg_Rs(ULONG uIP, char *pszBuffer, int nLen)
{
	if (uIP <= 0 || NULL == pszBuffer || nLen <= 0)
		return false;
	STRU_SEND_MSG_RS *lpv_Sendmsgrs = (STRU_SEND_MSG_RS*)pszBuffer;
	emit DealSendMsgRs(pszBuffer, nLen);
	return true;
}


bool CUDPAgency::InitAgency()
{
	if (m_pNet->InitNet() == false)
		return false;
	return true;
}

void CUDPAgency::UnInitAgency()
{
	m_pNet->UnInitNet();
}


bool CUDPAgency::DealUDPData(ULONG uIP, char *pszBuffer, int nLen)
{
	PackType packtype = *pszBuffer;
	STRU_ONLINE_MAP_UDP *pTemp = OnLineUDPMap;
	while (1)
	{
		if (pTemp->packtype == 0 && pTemp->pfn == 0)
			return false;

		if (pTemp->packtype == packtype)
		{
			(this->*(pTemp->pfn))(uIP, pszBuffer, nLen);
			return true;
		}

		pTemp++;
	}

	return true;
}
