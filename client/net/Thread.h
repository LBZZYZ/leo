#ifndef _NET_THREAD_H_
#define _NET_THREAD_H_

#include <Qthread>
#include "TCPAgency.h"

class NetThread : public QThread
{

public:
    NetThread() {}
    ~NetThread() {}

public:
    virtual void Init();
    virtual void DeInit();
    virtual void Start();
    virtual void Stop();
};

#endif //_NET_THREAD_H_