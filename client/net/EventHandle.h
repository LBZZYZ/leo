#ifndef _EVENT_HANDLE_H_
#define _EVENT_HANDLE_H_

#include <map>

class EventHandle;

typedef void (EventHandle::*HandleFunc)(const char *, const int);

class EventHandle
{

public:
    EventHandle();
    ~EventHandle();

    void RegisterEvent(int event, HandleFunc pfn);
    void CancelEvent(int event);

public:
    // @Handle Function Collection
    void EventHandle::LoginRS(const char *pszBuffer, const int nLen);

// signals:
//     void IsLoginSucceed(bool);

public:
    std::map<int, HandleFunc> event_queue;
};

#endif //_EVENT_HANDLE_H_