#pragma once
#include "INet.h"
#include "Thread.h"

#include <QObject>

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
	virtual bool DealData(char* pszBuffer, int nLen) = 0;

protected:
	INet* net;
	NetThread* thread;
};
