#ifndef _PROTOCOL_H_
#define _PROTOCOL_H_
#include "pool.h"

//using namespace std;

/*边界值*/
#define NAMESIZE     45
#define PWSIZE       45
#define BIRTHSIZE    15
#define MSGSIZE      480
#define BUFSIZE      560
#define MYSQLSIZE	     300
#define USRIDSIZE    11

#define PROTOCOL_BASE 10

//------------------应答和心跳包--------------------------
#define PROTOCOL_SERVER_RS 	 			PROTOCOL_BASE + 1
#define PROTOCOL_CLIENT_RS 	 			PROTOCOL_BASE + 2
#define PROTOCOL_ONLINE		 			PROTOCOL_BASE + 3
#define PROTOCOL_HEART 		 			PROTOCOL_BASE + 4

//------------------注册、登录----------------------------
#define PROTOCOL_REGISTER_RQ 			PROTOCOL_BASE + 5
#define PROTOCOL_REGISTER_RS 			PROTOCOL_BASE + 6
#define PROTOCOL_LOGIN_RQ 	 			PROTOCOL_BASE + 7
#define PROTOCOL_LOGIN_RS 	 			PROTOCOL_BASE + 8

//------------------搜索、添加、删除好友------------------
#define PROTOCOL_SEARCH_USER_RQ			PROTOCOL_BASE + 9	//搜索好友
#define PROTOCOL_SEARCH_USER_RS			PROTOCOL_BASE + 10
#define PROTOCOL_USER_ADD_RQ			PROTOCOL_BASE + 11	//添加好友
#define PROTOCOL_USER_ADD_RS			PROTOCOL_BASE + 12
#define PROTOCOL_USER_DELETE_RQ			PROTOCOL_BASE + 13	//删除好友
#define PROTOCOL_USER_DELETE_RS			PROTOCOL_BASE + 14

//--------------------好友及聊天----------------------
#define PROTOCOL_SEND_MSG_RQ			PROTOCOL_BASE + 19	//发送消息
#define PROTOCOL_SEND_MSG_RS			PROTOCOL_BASE + 20
#define PROTOCOL_SEND_FILE_RQ			PROTOCOL_BASE + 21	//发送文件
#define PROTOCOL_SEND_FILE_RS			PROTOCOL_BASE + 22
#define PROTOCOL_RECV_FILE_RQ			PROTOCOL_BASE + 23	//下载文件
#define PROTOCOL_RECV_FILE_RS			PROTOCOL_BASE + 24
#define PROTOCOL_RECV_OFFLINE_MSG_RQ	PROTOCOL_BASE + 25	//获取离线消息
#define PROTOCOL_RECV_OFFLINE_MSG_RS	PROTOCOL_BASE + 26
#define PROTOCOL_GET_FRIEND_LIST_RQ     PROTOCOL_BASE + 27  //获取好友列表
#define PROTOCOL_GET_FRIEND_LIST_RS     PROTOCOL_BASE + 28

#define PROTOCOL_UDP         			PROTOCOL_BASE + 21
#define PROTOCOL_TCP         			PROTOCOL_BASE + 21

typedef enum 
{
	FAILED,
	SUCCEED
}result_t;

typedef enum
{
	PRIVATEMSG,
	GROUPMSG,
	PHOTOMSG,
	FILEMSG
}msgtype_t;
typedef char packtype_t;

/*UDP应答验证*/
typedef struct 
{
	packtype_t packtype;  
	int num;              
}server_rs_t;

typedef struct 
{
	packtype_t packtype;  
	int num;              
}client_rs_t;


typedef struct 
{
	packtype_t packtype;  
}heart_t;

typedef struct client_data //参数封装
{
	char 		read_buf[BUFSIZE];
	char 		write_buf[BUFSIZE];
	int  		r_length;
	int 		w_length;
	int 		epollfd;
	int 		fd;
	struct sockaddr_in src_addr;
	socklen_t 	src_addrlen;
	struct sockaddr_in dest_addr;
	socklen_t 	dest_addrlen;
}client_data;


/*注册请求包*/
typedef struct 				
{
	packtype_t  packtype;
	int 		packnum;
	char    	usrid[USRIDSIZE];
	char 		usrname[NAMESIZE];
	char 		password[PWSIZE];
	char 		birth[BIRTHSIZE];
	char 		sex;
}registe_rq_t;
/*注册回复包*/
typedef struct 
{
	packtype_t 	packtype;
	int 		packnum;
	result_t 	result;
}registe_rs_t;
/*登录请求包*/
typedef struct 
{
	packtype_t 	packtype;
	char  		usrid[USRIDSIZE];
	char 		password[PWSIZE];
}login_rq_t;


/*登录回复包*/
typedef struct 
{
	packtype_t 	packtype;
	result_t 	result;
}login_rs_t;

/*搜索请求包*/
typedef struct
{
	packtype_t  packtype;
	long long 	usrid;
	long long 	searchid;
}search_rq_t;

/*搜索回复包*/
typedef struct
{
	packtype_t packtype;
	char       s_name[NAMESIZE];
	char 	   s_birth[BIRTHSIZE];
	char 	   s_sex;
}search_rs_t;

/*好友添加请求包*/
typedef struct 
{
	packtype_t packtype;
	int        packnum;
	long long  usrid;
	long long  searchid;
}add_rq_t;

/*好友添加回复包*/
typedef struct
{
	packtype_t packtype;
	int        packnum;
	long long  src_id;
	long long  dest_id;
	result_t   result;
}add_rs_t;

/*好友删除请求包*/
typedef struct
{
	packtype_t packtype;
	long long  usrid;
	long long  searchid;
}delete_rq_t;

/*好友删除回复包*/
typedef struct
{
	packtype_t packtype;
	result_t   result;
}delete_rs_t;

/*聊天信息请求包*/
typedef struct
{
	packtype_t packtype;
	int        packnum;
	msgtype_t  msgtype;
	long long  senderid;
	long long  receiverid;
	char       text[MSGSIZE];

}msg_rq_t;

typedef struct
{
	long long id;
	char name[NAMESIZE];
	
}friendlistmsg_t;

typedef struct
{
	packtype_t packtype;
	long long senderid;
}getfriendlist_rq_t;

typedef struct 
{
	packtype_t 		packtype;
	unsigned char friendnum;
	friendlistmsg_t friendlistmsg[200];
}getfriendlist_rs_t;


#endif
