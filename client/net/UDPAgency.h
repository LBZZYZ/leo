#pragma once
#include "Agency.h"
#include "Protocol/Protocol.h"
#include "UDPVerify.h"
#include <QObject>
class CUDPAgency;
typedef  bool (CUDPAgency:: *PUDPFUN)(ULONG, char*, int);
struct STRU_ONLINE_MAP_UDP
{
	PackType packtype;
	PUDPFUN pfn;
};

#define PROTOCOL_BEGIN_UDP STRU_ONLINE_MAP_UDP OnLineUDPMap[] = {
#define PROTOCOL_UDP(ThePackType,TheFunAddr) {ThePackType,TheFunAddr},
#define PROTOCOL_END_UDP	{0,0}};

using namespace std;
class CUDPAgency : public Agency
{
	Q_OBJECT
public:
	CUDPAgency();
	virtual ~CUDPAgency();


public:
	static CUDPVerify *m_UDPverify;
public:
	virtual bool Init();
	virtual void DeInit();
	virtual bool DealData(ULONG uIP, char *pszBuffer, int nLen);
public:
	bool ServerRes(ULONG uIP, char *pszBuffer, int nLen);
	bool RegisterRS(ULONG uIP, char *pszBuffer, int nLen);
	bool USER_ADD_RS(ULONG uIP, char *pszBuffer, int nLen);
	bool USER_ADD_RQ(ULONG uIP, char *pszBuffer, int nLen);
	bool Send_Msg_Rs(ULONG uIP, char *pszBuffer, int nLen);

signals:
	void RegisetrSignal(bool);
signals:
	void DealAddFrdRsSignal(char *,int);

signals:
	void DealAddFrdRqSignal(char*,int);

signals:
	void DealSendMsgRs(char*, int);

};