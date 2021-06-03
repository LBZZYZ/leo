#pragma once
#include <iostream>
#include <list>
#include "Protocol/Protocol.h"
#include "Agency.h"
using namespace std;

class CUDPVerify
{
public:
	CUDPVerify(Agency *Agency);
	~CUDPVerify();
public:
	Agency *agency;
	list<STRU_Verify *> m_lstVerify;					//需验证链表
	list<STRU_VerifyNum *> m_lstVerifyNum;				//已接收验证包链表
	HANDLE m_hVerifyThread;								//验证线程
	HANDLE m_hEvent;									//线程等待有需验证包
	bool m_bThreadQuitFlag;
public:
	bool InitVerify();									//初始化
	bool AddVerify(char *szBuf,int nPack,int nSize);	//添加需验证包					
public:
	static unsigned int __stdcall VerifyProc(void *);	//验证线程
};
