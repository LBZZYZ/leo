#pragma once
#include "Agency.h"
#include "Protocol/Protocol.h"


class CTCPAgency;
typedef  bool (CTCPAgency:: *PTCPFUN)(const char*, const int);



struct STRU_ONLINE_MAP_TCP
{
	PackType packtype;
	PTCPFUN pfn;
};

#define PROTOCOL_BEGIN_TCP STRU_ONLINE_MAP_TCP OnLineTCPMap[] = {
#define PROTOCOL(ThePackType,TheFunAddr) {ThePackType,TheFunAddr},
#define PROTOCOL_END_TCP	{0,0}};

class CTCPAgency : public Agency
{
	Q_OBJECT
private:
	CTCPAgency();
	virtual ~CTCPAgency();
public:
	bool Init();
	void DeInit();
	virtual bool DealData(char *pszBuffer, int nLen);
public:
	bool LoginRS(const char *pszBuffer, const int nLen);
	bool SearchRS(const char *pszBuffer, const int nLen);
	bool DeleteRS(const char *pszBuffer, const int nLen);
	bool GetFriendListRS(const char *pszBuffer, const int nLen);

signals:
	void LoginRSSignal(bool);
	void SerchRsSiganl(STRU_SEARCH_USER_RS*);
	void DeletefrRSsignal(bool);
	void DealFriendListSignal(char *pszBuffer, int nLen);

private:
	static CTCPAgency* agency;

public:
	static CTCPAgency* GetInstance();
};