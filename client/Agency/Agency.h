#pragma once
#include "Net\INet.h"
#include "qthread.h"
#include <QObject>

class CAgency :public QObject
{
	Q_OBJECT
public:

	INet *m_pNet;
	
public:
	CAgency(){ m_pNet = 0;

	}
	virtual ~CAgency(){}
public:
	virtual bool InitAgency() = 0;
	virtual void UnInitAgency() = 0;
	virtual bool DealTCPData(SOCKET socketClient, char *pszBuffer, int nLen) { return false; }
	virtual bool DealUDPData(ULONG uIP, char *pszBuffer, int nLen){ return false; }
public:
	INet* GetNet()
	{
		return m_pNet;
	}
	
	
};
