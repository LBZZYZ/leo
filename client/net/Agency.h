#pragma once
#include "INet.h"



class Agency;
typedef bool (Agency::* CallBack_DealData)(char*, int);
bool (Agency:: *CallBack)(char*, int) = Agency::DealData;

class Agency :public QObject
{
	Q_OBJECT

public:
	Agency()
	{ 
		net = nullptr;
		thread = nullptr;
	}
	virtual ~Agency(){}

public:
	virtual bool Init() = 0;
	virtual void DeInit() = 0;
	static bool DealData(char* pszBuffer, int nLen){}

protected:
	INet* net;
	NetThread* thread;
};
