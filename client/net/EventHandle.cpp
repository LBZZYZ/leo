#include "EventHandle.h"
#include "Protocol.h"

EventHandle::EventHandle(/* args */)
{
}

EventHandle::~EventHandle()
{
}


// @Public API : It's used to register a event with its handle function who's wanted to be listened;

void EventHandle::RegisterEvent(int event, HandleFunc pfn)
{
	event_queue[event] = pfn;
}

// @Public API : Removes the event from the listening collection.

void EventHandle::CancelEvent(int event)
{
    //TBD
}



void EventHandle::LoginRS(const char *pszBuffer, const int nLen)
{
	STRU_LOGIN_RS *login_RS = (STRU_LOGIN_RS *)pszBuffer;

	if (login_RS->result == SUCCEED)
	{
		// emit IsLoginSucceed(true);
	}
	else
	{
		// emit IsLoginSucceed(false);
	}
}

// bool EventHandle::SearchRS(const char *pszBuffer, const int nLen)
// {

// 	emit SerchRsSiganl((STRU_SEARCH_USER_RS *)pszBuffer);
// 	return true;
// }
// bool EventHandle::DeleteRS(const char *pszBuffer, const int nLen)
// {
// 	STRU_SEARCH_DELETE_RS *rs = (STRU_SEARCH_DELETE_RS *)pszBuffer;
// 	if (rs->result)
// 		emit DeletefrRSsignal(true);
// 	else
// 		emit DeletefrRSsignal(false);
// 	return true;
// }

// bool EventDispatch::GetFriendListRS(const char *pszBuffer, const int nLen)
// {
// 	if (pszBuffer == NULL || nLen <= 0)
// 		return false;
// 	emit DealFriendListSignal(pszBuffer, nLen);
// 	return true;
// }



// void Mediator::DealSendMsgSlot(char* pszBuffer, int nLen)
// {
// 	if (NULL == pszBuffer || nLen <= 0)
// 	{
// 		qDebug() << "DealSendMsgSlot Error!";
// 		return;
// 	}

// 	/*将收到的消息写入文件*/
// 	STRU_SEND_MSG_RS *lpv_Msg = (STRU_SEND_MSG_RS*)pszBuffer;
// 	char FileName[12] = { 0 };
// 	itoa(lpv_Msg->llID, FileName, 10);
// 	QFile MsgFile(FileName);
// 	MsgFile.open(QFile::WriteOnly | QFile::Append);
// 	QTextStream writer(&MsgFile);
// 	writer << lpv_Msg->szText << endl;
// 	MsgFile.close();


// }



// /*********************************************
// 函数名       : DealFriendList
// 函数功能描述 : 处理服务端返回的好友列表
// 函数参数     : char * pszBuffer, int nLen
// 函数返回值   : void
// 函数作者     : 李柄志
// 函数创建日期 : 2019.07.23
// 函数修改日期 : *
// 修改人       : *
// 修改原因     : *
// 版本         : 1.0
// 历史版本     : 无
// *********************************************/
// void Mediator::DealFriendList(char * pszBuffer, int nLen)
// {
// 	if (pszBuffer == NULL || nLen <= 0)
// 		return;
// 	STRU_GET_FRIENDLIST_RS *lpv_Getfriendlistrs = (STRU_GET_FRIENDLIST_RS*)pszBuffer;
// 	UiInitMainWindow(lpv_Getfriendlistrs->pFriendList);
// }


// /*********************************************
// 函数名       : GetFriendList
// 函数功能描述 : 向服务端获取登录用户的好友列表
// 函数参数     : void
// 函数返回值   : void
// 函数作者     : 李柄志
// 函数创建日期 : 2019.07.23
// 函数修改日期 : *
// 修改人       : *
// 修改原因     : *
// 版本         : 1.0
// 历史版本     : 无
// *********************************************/
// void Mediator::GetFriendsList(void)
// {
// 	//1.构造获取好友列表请求包
// 	STRU_GET_FRIENDLIST_RQ lsv_Getfrinedlistrq;
// 	lsv_Getfrinedlistrq.packtype = PROTOCOL_GET_FRIENDLIST_RQ;
// 	lsv_Getfrinedlistrq.llUserID = userId;
// 	if (false == m_pTcpAgency->DealData((char*)&lsv_Getfrinedlistrq, sizeof(STRU_GET_FRIENDLIST_RQ)))
// 		return;

// }