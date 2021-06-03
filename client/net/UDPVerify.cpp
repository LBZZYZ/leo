#include "UDPVerify.h"
#include <process.h>

CUDPVerify::CUDPVerify(Agency *Agency)
{
	agency = Agency;
	m_bThreadQuitFlag = true;
	m_hVerifyThread = 0;
	m_hEvent = 0;
}

CUDPVerify::~CUDPVerify()
{
	m_bThreadQuitFlag = false;
	list<STRU_Verify *>::iterator iteVer = m_lstVerify.begin();

	while (iteVer != m_lstVerify.end())
	{
		delete[] (*iteVer)->pszBuf;
		(*iteVer)->pszBuf = 0;
		delete (*iteVer);
		(*iteVer) = 0;
		iteVer = m_lstVerify.erase(iteVer);
	}

	list<STRU_VerifyNum *>::iterator iteVerNum = m_lstVerifyNum.begin();

	while (iteVerNum != m_lstVerifyNum.end())
	{
		delete (*iteVerNum);
		(*iteVerNum) = 0;
		iteVerNum = m_lstVerifyNum.erase(iteVerNum);
	}

}

bool CUDPVerify::InitVerify()
{
	m_hVerifyThread = (HANDLE)_beginthreadex(0, 0, &CUDPVerify::VerifyProc, this, 0, 0);
	if (m_hVerifyThread == 0)
		return false;

	m_hEvent = ::CreateEvent(0, FALSE, FALSE, 0);
	if (m_hEvent == 0)
		return false;

	return true;
}

bool CUDPVerify::AddVerify(char *szBuf, int nPack, int nSize)
{
	//分配验证结构体空间及分配包空间并初始化
	STRU_Verify *pTemp = new STRU_Verify;
	memset(pTemp, 0, sizeof(STRU_Verify));
	char *psz = new char[nSize];
	memset(psz, 0, nSize);
	//给验证结构体赋值
	pTemp->pszBuf = psz;
	memcpy_s(pTemp->pszBuf, nSize, szBuf, nSize);
	pTemp->nCount = 0;
	pTemp->nPackNum = nPack;
	pTemp->nSize = nSize;
	pTemp->vRes = UNVERIFIED;
	//添加到验证结构体链表
	m_lstVerify.push_back(pTemp);
	//唤醒验证线程
	::SetEvent(m_hEvent);
	return true;
}

unsigned int __stdcall CUDPVerify::VerifyProc(void *pVoid)
{
	CUDPVerify *pThis = (CUDPVerify*)pVoid;

	while (pThis->m_bThreadQuitFlag)
	{
		WaitForSingleObject(pThis->m_hEvent, INFINITE);
		while (1)
		{
			Sleep(6);
			
			list<STRU_Verify *>::iterator iteVer = pThis->m_lstVerify.begin();
		
			while(iteVer != pThis->m_lstVerify.end() || pThis->m_bThreadQuitFlag == false)
			{
				list<STRU_VerifyNum *>::iterator iteVerNum = pThis->m_lstVerifyNum.begin();
				while (iteVerNum != pThis->m_lstVerifyNum.end())
				{
					if ((*iteVer)->nPackNum == (*iteVerNum)->nPackNum)
					{
						delete[](*iteVer)->pszBuf;
						(*iteVer)->pszBuf = 0;
						delete (*iteVer);
						(*iteVer) = 0;
						iteVer = pThis->m_lstVerify.erase(iteVer);
						(*iteVerNum)->vRes = VERIFIED;
						break;
					}
					++iteVerNum;
				}

				if (iteVerNum != pThis->m_lstVerifyNum.end())
					continue;

				if ((*iteVer)->nCount == 5)
				{
					//重传
					pThis->agency->net->SendUDPData(inet_addr(IP), (*iteVer)->pszBuf, (*iteVer)->nSize);
					(*iteVer)->nCount = 0;
					continue;
				}
				(*iteVer)->nCount++;
				++iteVer;
			}
			if (pThis->m_lstVerify.empty() == true || pThis->m_bThreadQuitFlag == false)
				break;
		}
	}
	return 0;
}