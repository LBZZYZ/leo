#pragma once
#include "Agency/Agency.h"
#include "Protocol/Protocol.h"


class CTCPAgency;
typedef  bool (CTCPAgency:: *PTCPFUN)(SOCKET, char*, int);
struct STRU_ONLINE_MAP_TCP
{
	PackType packtype;
	PTCPFUN pfn;
};

#define PROTOCOL_BEGIN_TCP STRU_ONLINE_MAP_TCP OnLineTCPMap[] = {
#define PROTOCOL(ThePackType,TheFunAddr) {ThePackType,TheFunAddr},
#define PROTOCOL_END_TCP	{0,0}};

class CTCPAgency : public CAgency
{
	Q_OBJECT
public:
	CTCPAgency();
	virtual ~CTCPAgency();
public:
	virtual bool InitAgency();
	virtual void UnInitAgency();
	virtual bool DealTCPData(SOCKET socketClient, char *pszBuffer, int nLen);
public:
	bool LoginRS(SOCKET socket, char *pszBuffer, int nLen);
	bool SearchRS(SOCKET socket, char *pszBuffer, int nLen);
	bool DeleteRS(SOCKET socket, char *pszBuffer, int nLen);
	bool GetFriendListRS(SOCKET socket,char *pszBuffer, int nLen);

signals:
	void LoginRSSignal(bool);
	void SerchRsSiganl(STRU_SEARCH_USER_RS*);
	void DeletefrRSsignal(bool);
	void DealFriendListSignal(char *pszBuffer, int nLen);
};