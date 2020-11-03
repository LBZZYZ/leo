#pragma once

#include <list>
#include <stdlib.h>
typedef struct cMyMSG {
	int message;
	char* WParam;
}MyMSG;
typedef struct sMSGQueue
{
	int size;
	int read_ops;
	int write_ops;
}MSGQueue;
 static  volatile MSGQueue* msgqueue;
 static   MyMSG** Message;
static	void initQueues()
	{
		msgqueue = (MSGQueue*)malloc(sizeof(MSGQueue));
		msgqueue->size = 20;
		msgqueue-> read_ops = 0;
		msgqueue-> write_ops = 0;

		Message = (MyMSG**)malloc(sizeof(MyMSG*) * 20);
		memset(Message, 0, sizeof(MyMSG*)*20);

	}
static	void push_que( char*rs, int msgtype)
	{

	if ((msgqueue->read_ops + 1) % msgqueue->size != msgqueue->write_ops)return;
   
		Message[msgqueue->write_ops]->message = msgtype;
		Message[msgqueue->write_ops]->WParam = rs;
		msgqueue->write_ops++;

	}

static	MyMSG* pop_que()
	{

		while ((msgqueue->read_ops != msgqueue->write_ops));
		MyMSG * msg = NULL;
		memcpy(msg, Message[msgqueue->read_ops], sizeof(MyMSG));
		Message[msgqueue->read_ops]->message = 0;
		Message[msgqueue->read_ops]->WParam = 0;
		msgqueue->read_ops++;

		return msg;
	}