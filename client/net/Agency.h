#pragma once
#include "INet.h"

//
// typedef bool (Agency::* CallBack_DealData)(char*, int);

class Agency
{
public:
	Agency(){}
	virtual ~Agency(){}

public:
	virtual bool Init() = 0;
	virtual void DeInit() = 0;


	virtual void CancelEvent() = 0;
	virtual bool StratEventLoop(char* pszBuffer, int nLen) = 0;

public:
	INet *net;
};
