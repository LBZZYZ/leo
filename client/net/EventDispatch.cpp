#include "EventDispatch.h"
#include "TCPNet.h"
#include "Protocol.h"

EventDispatch *EventDispatch::dispatcher = nullptr;

EventDispatch::EventDispatch()
{
	this->Init();

	handler->RegisterEvent(PROTOCOL_GET_FRIENDLIST_RQ, &EventHandle::LoginRS);
}

void EventDispatch::Init()
{
	const char *ip = "39.108.143.167";
	const int port = 39999;

	net = new TCPNet(ip, port);

	handler = new EventHandle;
}

EventDispatch::~EventDispatch()
{
	this->DeInit();
}

EventDispatch *EventDispatch::GetInstance()
{
	if (dispatcher == nullptr)
	{
		dispatcher = new EventDispatch;
	}
	return dispatcher;
}

void EventDispatch::DeInit()
{
	this->net->DisConnect();
	net = nullptr;
}

bool EventDispatch::StratEventLoop(char *pszBuffer, int nLen)
{
	while (1)
	{
		int len = 40;
		char *recv_buf = new char[len];
		memset(recv_buf, 0, len);

		net->RecvData(&recv_buf, &len);

		PackType package_type = (PackType)recv_buf;
		switch (package_type)
		{
		case PROTOCOL_LOGIN_RS:
		{
			// call event handle function
			HandleFunc h = handler->event_queue[PROTOCOL_LOGIN_RS];

			break;
		}
		}
	}

	return true;
}
