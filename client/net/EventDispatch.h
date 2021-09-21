#pragma once
#include <map>

#include "INet.h"
#include "EventHandle.h"

class EventDispatch
{

public:

	void Init();
	void DeInit();
	bool LoginRS(const char *pszBuffer, const int nLen);

	bool StratEventLoop(char* pszBuffer, int nLen);

// @Singleton 
private:
	EventDispatch();
	virtual ~EventDispatch();

public:
	static EventDispatch* GetInstance();

private:
	static EventDispatch* dispatcher;
	EventHandle *handler;

public:
		INet * net;
	 
};