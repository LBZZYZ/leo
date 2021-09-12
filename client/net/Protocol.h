#ifndef _PROTOCOL_H_
#define _PROTOCOL_H_

#include <list>
#include<QString>
#include <QPixmap>
#include <stdint.h>

using namespace std;
#define IP				"39.108.143.167"
#define TCP_PORT			 8000
#define UDP_PORT			 4567
//------------------------------------
#define NAME_SIZE             45
#define PASSWORD_SIZE         45
#define UDP_RECV_BUFFER_SIZE  548
#define MSG_BUFFER_SIZE		  480
#define FRIENDLIST_SIZE       
//------------------------------------
enum ResultType { FAILED, SUCCEED };							 //  回复的结果
enum MessageType { PRIVATEMSG, GROUPMSG ,PHOTOMSG ,FILEMSG };    //  消息类型
enum VerifyRes { UNVERIFIED, VERIFIED };						 //	 验证结果
//----------------验证结构体--------------------
typedef struct
{
	char *pszBuf;							//存放UDP协议包地址
	int nCount;								//超时重传计数
	int nPackNum;							//包编号
	int nSize;								//包大小
	VerifyRes vRes;							//验证结果
}STRU_Verify;

typedef struct
{
	int nPackNum;
	VerifyRes vRes;
}STRU_VerifyNum;

//===============================协议==============================================
#define PROTOCOL_BASE       10
//--------------------应答及心跳包-------------------
#define PROTOCOL_SERVER_RS				PROTOCOL_BASE+1		//服务器应答
#define PROTOCOL_CLIENT_RS				PROTOCOL_BASE+2		//客户端应答
#define PROTOCOL_ONLINE					PROTOCOL_BASE+3		//上线通知
#define PROTOCOL_HEART					PROTOCOL_BASE+4		//心跳包
//--------------------登录，注册---------------------
#define PROTOCOL_REGISTER_RQ			PROTOCOL_BASE+5		//注册
#define PROTOCOL_REGISTER_RS			PROTOCOL_BASE+6
#define PROTOCOL_LOGIN_RQ				PROTOCOL_BASE+7		//登录
#define PROTOCOL_LOGIN_RS				PROTOCOL_BASE+8
//--------------------搜索添加删除好友---------------
#define PROTOCOL_SEARCH_USER_RQ			PROTOCOL_BASE+9		//搜素好友
#define PROTOCOL_SEARCH_USER_RS			PROTOCOL_BASE+10
#define PROTOCOL_USER_ADD_RQ			PROTOCOL_BASE+11	//添加好友	
#define PROTOCOL_USER_ADD_RS			PROTOCOL_BASE+12
#define PROTOCOL_USER_DELETE_RQ			PROTOCOL_BASE+13	//删除好友	
#define PROTOCOL_USER_DELETE_RS			PROTOCOL_BASE+14
//--------------------建群进群------------------------
#define PROTOCOL_GROUP_REGISTER_RQ		PROTOCOL_BASE+15	//建群	
#define PROTOCOL_GROUP_REGISTER_RS		PROTOCOL_BASE+16
#define PROTOCOL_GROUP_ADD_RQ			PROTOCOL_BASE+17	//进群
#define PROTOCOL_GROUP_ADD_RS			PROTOCOL_BASE+18
//--------------------好友及聊天----------------------
#define PROTOCOL_SEND_MSG_RQ			PROTOCOL_BASE+19	//发送消息
#define PROTOCOL_SEND_MSG_RS			PROTOCOL_BASE+20
#define PROTOCOL_SEND_FILE_RQ			PROTOCOL_BASE+21	//发送文件
#define PROTOCOL_SEND_FILE_RS			PROTOCOL_BASE+22
#define PROTOCOL_RECV_FILE_RQ			PROTOCOL_BASE+23	//下载文件
#define PROTOCOL_RECV_FILE_RS			PROTOCOL_BASE+24
#define PROTOCOL_RECV_OFFLINE_MSG_RQ	PROTOCOL_BASE+25	//获取离线消息
#define PROTOCOL_RECV_OFFLINE_MSG_RS	PROTOCOL_BASE+26
#define PROTOCOL_GET_FRIENDLIST_RQ		PROTOCOL_BASE+27	//获取好友列表
#define PROTOCOL_GET_FRIENDLIST_RS		PROTOCOL_BASE+28	
//===============================协议==============================================


//===============================协议包==============================================
typedef char PackType;

typedef struct
{
	PackType packtype;				//  协议
	long long llID;					//	ID
	MessageType msgtype;			//	消息类型
	char szText[MSG_BUFFER_SIZE];	//	消息内容
	char szMsgTime[30];				//	消息时间
}OFFLINEMSG;


typedef struct
{
	long long userid;					
	QPixmap avatar;
	QString name;
	QString remark;
	QString signature;

}FRINENDLISTMSG;
//--------------------应答验证及心跳-----------------
struct STRU_SERVER_RS				//	UDP
{
	PackType packtype;				//  协议
	int nPackNum;					//  包编号
};

struct STRU_CLIENT_RS				//	UDP
{
	PackType packtype;				//  协议
	int nPackNum;					//  包编号
};

struct STRU_HEART					//	UDP
{
	PackType packtype;				//  协议
	long long llUserID;				//  用户ID 
};
//--------------------登录，注册---------------------
struct STRU_REGISTER_RQ				//	UDP*
{
	PackType packtype;				//  协议
	int nPackNum;					//  包编号
	long long llUserID;				//  用户ID 
	char szUserName[NAME_SIZE];		//	昵称
	char szPassWord[PASSWORD_SIZE];	//	密码
	char szBirth[15];				//	生日
	char szSex;						//	性别（男：m女：f）
};

struct STRU_REGISTER_RS				//	UDP
{
	PackType packtype;				//  协议
	int nPackNum;					//  包编号
	ResultType result;				//  回复
};

struct STRU_LOGIN_RQ				//	TCP*
{
	PackType packtype;				//  协议
	long long llUserID;				//  用户ID 
	char szPassWord[PASSWORD_SIZE]; //	密码
};

struct STRU_LOGIN_RS				//	TCP
{
	PackType packtype;				//  协议
	ResultType result;				//  回复
};
//--------------------搜索添加删除好友---------------

struct STRU_SEARCH_FRIENDS_REQUEST
{
	PackType packtype;
	char search_type;
	char friend_id[NAME_SIZE];
};

struct STRU_SEARCH_USER_RS			//	TCP
{
	PackType packtype;				//  协议
	char szUserName[NAME_SIZE];		//	昵称
	char szBirth[15];				//	生日
	char szSex;						//	性别（男：m女：f）
};

struct STRU_USER_ADD_RQ				//	UDP
{
	PackType packtype;												
	const char* llSearchID;			
};

struct STRU_USER_ADD_RS				//	UDP
{
	PackType packtype;				//  协议
	int nPackNum;					//  包编号
	long long llSenderID;			//  发送者ID
	long long llReceiverID;			//  接受者ID
	ResultType result;				//  回复
};

struct STRU_USER_DELETE_RQ			//	TCP
{
	PackType packtype;				//  协议
	long long llUserID;				//  用户ID
	long long llSearchID;			//	搜索ID
};

struct STRU_SEARCH_DELETE_RS		//	TCP
{
	PackType packtype;				//  协议
	ResultType result;				//  回复
};


//------------------获取好友列表---------------------
struct STRU_GET_FRIENDLIST_RQ
{
	PackType packtype;
	long long llUserID;
};


struct STRU_GET_FRIENDLIST_RS
{
	PackType packtype;
	list<FRINENDLISTMSG> *pFriendList;			//好友列表指针
};

//------------------好友及群聊天---------------------
typedef struct STRU_SEND_MSG_RQ		//	UDP
{
	PackType packtype;				//  协议
	int nPackNum;					//  包编号
	MessageType msgtype;			//	消息类型（群/好友）
	long long llUserID;				//  用户ID 
	long long llID;					//	好友ID/群ID
	char szText[MSG_BUFFER_SIZE];	//	消息内容
}STRU_SEND_MSG_RS;

struct STRU_RECV_OFFLINE_MSG_RQ		//	TCP
{
	PackType packtype;				//  协议
	list<OFFLINEMSG*> lstOFFlineMsg;//	离线消息链表
};
static  void  Qstringtochar(char arr[], QString qstr, int nlength)
{
	QByteArray qbyte;
	qbyte.append(qstr);
	memcpy(arr, qbyte.data(), nlength);
}
static  void  ChartoQstring(char arr[], QString &qstr, int nlength)
{
	QByteArray qbyte;
	qbyte.append(arr, nlength);
	qstr.prepend(qbyte);

}
static int packId = 0;
extern long long userId;
static  QString userName;
//===============================协议包==============================================

#endif //_PROTOCOL_H_