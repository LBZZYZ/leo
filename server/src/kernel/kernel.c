#include "kernel.h"

#include "net.h"
#include <stdlib.h>
#include "mylist.h"
#include "err_sys.h"

#include "sql_api.h"



enum STRU_INIT
{
	E_STRU_INIT_REGISTER_RQ,
	E_STRU_INIT_REGISTER_RS,
	E_STRU_INIT_LOGIN_RQ,
	E_STRU_INIT_LOGIN_RS,
	E_STRU_INIT_SEARCH_USER_RQ,
	E_STRU_INIT_SEARCH_USER_RS

};

/*
	kernel utils
*/
KNL_RESULT knl_stru_init(void *stru, enum STRU_INIT args)
{
	switch (args)
	{
		case E_STRU_INIT_LOGIN_RS:
		{
			login_rs_t *st = (login_rs_t*)stru;
			st->packtype = PROTOCOL_LOGIN_RS;
			st->result = FAILED;
			break;
		}
		case E_STRU_INIT_REGISTER_RS:
		{
			/*构造回复包*/
			registe_rs_t *st = (registe_rs_t*)stru;
			st->packtype = PROTOCOL_REGISTER_RS;
			st->packnum = -1;
			st->result = FAILED;
			break;
		}
		default:
		{
			break;
		}
	}
	return KNL_OK;

}
KNL_RESULT knl_is_user_online(int fd,int ip,int port)
{
	if(ip <= 0 || fd <= 0 || port <= 0)
	{
		return KNL_INVALID;
	}

	heart_t heart;
	heart.packtype = PROTOCOL_HEART;

	struct sockaddr_in clientaddr;
	bzero(&clientaddr,sizeof(clientaddr));

	clientaddr.sin_family = AF_INET;
	clientaddr.sin_port = port;
	clientaddr.sin_addr.s_addr = ip;

	if(-1 != sendto(fd,(const char*)&heart,sizeof(heart),0,(const struct sockaddr*)&clientaddr,sizeof(clientaddr)))
	{
		return KNL_OK;
	}
	return KNL_ERROR;
}

/*
	Check if this user is exist?
*/
KNL_RESULT knl_is_user_exist(void *args)
{
	if(SQL_API_OK == sql_api_is_user_exist(args))
	{
		return KNL_OK;
	}
	return KNL_ERROR;
}


KNL_RESULT knl_insert_user_online(void *args)
{
	if(args == NULL)
	{
		return KNL_INVALID;	
	}

	if(SQL_API_OK == sql_api_insert_user_online(args))
	{
		return KNL_OK;
	}

	return KNL_ERROR;
}


KNL_RESULT knl_registe(void *clientdata)
{

	struct client_data *c_data = (struct client_data*)clientdata;
	c_data->w_length = sizeof(registe_rs_t);

	registe_rq_t *rq = (registe_rq_t *)(c_data->read_buf);

	registe_rs_t rs;
	knl_stru_init((void*)&rs,E_STRU_INIT_REGISTER_RS);

	rs.packnum = rq->packnum;

	if(knl_is_user_exist(c_data) != KNL_OK)
	{
		if(sql_api_add_user(c_data) == SQL_API_OK)
		{
			rs.result = SUCCEED;
		}
	}
	else 
	{
		rs.result = FAILED;
	}

	memmove(c_data->write_buf,&rs,sizeof(rs));

	c_data->dest_addr.sin_family = c_data->src_addr.sin_family;
	c_data->dest_addr.sin_port = c_data->src_addr.sin_port;
	c_data->dest_addr.sin_addr.s_addr = c_data->src_addr.sin_addr.s_addr;
	epoll_add_event(c_data->epollfd,c_data->fd);

	return KNL_OK;
}

KNL_RESULT knl_login(void *clientdata)
{
	struct client_data *c_data = (struct client_data*)clientdata;
	c_data->w_length = sizeof(login_rs_t);

	login_rs_t *c_rs = (login_rs_t*)c_data->write_buf;
	knl_stru_init((void*)&c_rs,E_STRU_INIT_LOGIN_RS);

	if(sql_api_is_user_exist(c_data) == SQL_API_OK)
	{
		if(sql_api_is_pwd_right(c_data) == SQL_API_OK)
		{
			c_rs->result = SUCCEED;
		}
	}
	else
	{
		rs.result = FAILED;
	}

	if(KNL_ERROR == knl_insert_user_online(c_data))
	{
		return KNL_ERROR;
	}

	epoll_add_event(c_data->epollfd,c_data->fd);

	return KNL_OK;
}

KNL_RESULT knl_search_user(void *clientdata)
{

	/*获取查找好友请求包*/
	struct client_data *c_data = (struct client_data*)clientdata;
	search_rq_t *s_rq = (search_rq_t*)c_data->read_buf;

	/*包异常检测*/
	if(s_rq->usrid == 0 || s_rq->searchid == 0)
	{
		return KNL_ERROR;
	}

	/*构造查找回复包*/
	search_rs_t *s_rs = (search_rs_t*)c_data->write_buf;
	c_data->w_length = sizeof(search_rs_t);
	s_rs->packtype = PROTOCOL_SEARCH_USER_RS;

	list_t *lst;
	list_init(&lst);
    
	if(SQL_API_OK == sql_api_select_user(c_data,&lst))
	{
		char *str = NULL;
		str = lst_pop(lst);
		strncpy(s_rs->s_name,str,strlen(str));
		str = lst_pop(lst);
		strncpy(s_rs->s_birth,str,strlen(str));
		str = lst_pop(lst);
		s_rs->s_sex = *str;
		epoll_add_event(c_data->epollfd,c_data->fd);
		return KNL_OK;
	}
	return KNL_ERROR;
}

KNL_RESULT GetClientIp(long long *llv_Id)
{
	if(llv_Id == NULL || llv_Id <= 0)
	{
		return KNL_INVALID; 
	}
	if(SQL_API_OK == sql_api_get_user_ip(llv_Id))
	{
		return KNL_OK;
	}
	return KNL_ERROR;
}

KNL_RESULT knl_add_user(void *clientdata)
{
	if(clientdata == NULL)
	{
		return KNL_INVALID;
	}

	struct client_data *lpv_Clientdata = (struct client_data*)clientdata;
	add_rq_t *lpv_Addrq = (add_rq_t*)lpv_Clientdata->read_buf;


	long long llv_Ip = 0;
	llv_Ip = GetClientIp(&lpv_Addrq->searchid);

	add_rq_t *p = (add_rq_t*)lpv_Clientdata->write_buf;
	p->usrid = lpv_Addrq->usrid;
	p->searchid = lpv_Addrq->searchid;
	p->packtype = lpv_Addrq->packtype;
	p->packnum = lpv_Addrq->packnum;

	lpv_Clientdata->w_length = lpv_Clientdata->r_length;
	lpv_Clientdata->dest_addr.sin_family = AF_INET;
	lpv_Clientdata->dest_addr.sin_addr.s_addr = llv_Ip;
	lpv_Clientdata->dest_addr.sin_port = htons(4567);
	epoll_add_event(lpv_Clientdata->epollfd,lpv_Clientdata->fd);


	return KNL_OK;
}

KNL_RESULT knl_add_user_rs(void *clientdata)
{
	if(NULL == clientdata)
	{
		return KNL_INVALID;
	};
	client_data *lpv_Clientdata = (client_data*)clientdata;
	add_rs_t *lpv_Addrs = (add_rs_t*)lpv_Clientdata->read_buf;

	//客户端在线
	if(knl_is_user_online(1,1,1) == KNL_OK)
	{
		add_rs_t *p = (add_rs_t*)lpv_Clientdata->write_buf;
		p->packtype = lpv_Addrs->packtype;
		p->packnum = lpv_Addrs->packnum;
		p->dest_id = lpv_Addrs->dest_id;
		p->src_id = lpv_Addrs->src_id;
		p->result = lpv_Addrs->result;
		lpv_Clientdata->w_length = lpv_Clientdata->r_length;
		lpv_Clientdata->dest_addr.sin_family = AF_INET;

		inet_pton(AF_INET,"172.20.10.5",&lpv_Clientdata->dest_addr.sin_addr.s_addr);
		char ip[16];
		bzero(ip,sizeof(ip));
		inet_ntop(AF_INET,&lpv_Clientdata->dest_addr.sin_addr.s_addr,ip,sizeof(ip));

		lpv_Clientdata->dest_addr.sin_port = htons(4567);
		epoll_add_event(lpv_Clientdata->epollfd,lpv_Clientdata->fd);

	}
	else
	{
		/* 客户端不在线，把请求缓存起来 */
	}
	


	/*解析包结果，同意则把好友关系插入到usr_friends表中*/


	return KNL_ERROR;
}

/*消息转发*/
int send_msg(void* clientdata)
{
	if(NULL == clientdata)exit(EXIT_FAILURE);
	struct client_data *lpv_Clientdata = (struct client_data*)clientdata;
	msg_rq_t *lpv_Msg = (msg_rq_t*)lpv_Clientdata->read_buf;
	msg_rq_t *p = (msg_rq_t*)lpv_Clientdata->write_buf;
	long long llv_Receiverip = GetClientIp(&lpv_Msg->receiverid);
	p->senderid = lpv_Msg->senderid;
	p->receiverid = lpv_Msg->receiverid;
	p->packtype = PROTOCOL_SEND_MSG_RS;
	p->packnum = lpv_Msg->packnum;
	strncpy(p->text,lpv_Msg->text,strlen(lpv_Msg->text));

	lpv_Clientdata->w_length = lpv_Clientdata->r_length;
	lpv_Clientdata->dest_addr.sin_family = AF_INET;
	lpv_Clientdata->dest_addr.sin_addr.s_addr = llv_Receiverip;
	lpv_Clientdata->dest_addr.sin_port = htons(4567);
	epoll_add_event(lpv_Clientdata->epollfd,lpv_Clientdata->fd);

	return 0;
}

KNL_RESULT knl_get_friend_list(void* clientdata)
{
	if(NULL == clientdata)
	{
		return KNL_INVALID;
	}

	struct client_data *lpv_Clientdata = (struct client_data*)clientdata;
	//getfriendlist_rq_t *p = (getfriendlist_rq_t*)lpv_Clientdata->read_buf;

	//long long llv_Senderid = p->senderid;
	getfriendlist_rs_t rs;
	bzero(&rs,sizeof(rs));
	rs.packtype = PROTOCOL_GET_FRIEND_LIST_RS;
    
	list_t *lpv_Idlist = NULL;
	list_t *lpv_Namelist = NULL;
	list_init(&lpv_Idlist);
	list_init(&lpv_Namelist);
	
	if(SQL_API_OK == sql_api_get_user_list(lpv_Clientdata))
	{
		rs.friendnum = 1;
		memcpy(lpv_Clientdata->write_buf,(char*)&rs,8+1*sizeof(friendlistmsg_t));
		lpv_Clientdata->w_length = 8+ 1*sizeof(friendlistmsg_t);
	}

	epoll_add_event(lpv_Clientdata->epollfd,lpv_Clientdata->fd);

	return KNL_ERROR;
}


/*添加epoll监听事件*/
static void epoll_add_event(int epollfd,int fd)
{
	struct epoll_event event;
	event.events = EPOLLIN | EPOLLOUT;
	event.data.fd = fd;
	if(-1 == (epoll_ctl(epollfd,EPOLL_CTL_MOD,fd,&event)))
	{
		err_sys("EPOLL_CTL_IN",EXIT_FAILURE);
	}
}

void* deal_data(void* clientdata)    /*key is equal to ip or socket*/
{
	//解析参数包
	struct client_data *c_data = (struct client_data*)clientdata;

	/*包协议与函数指针建立的协议包映射表*/
	protocol_map protocol_entry[] = 
	{
		{PROTOCOL_REGISTER_RQ,knl_registe},
		{PROTOCOL_LOGIN_RQ,knl_login},
		{PROTOCOL_SEARCH_USER_RQ,knl_search_user},
		{PROTOCOL_USER_ADD_RQ,knl_add_user},
		{PROTOCOL_USER_ADD_RS,knl_add_user_rs},
		{PROTOCOL_SEND_MSG_RQ,knl_send_msg},
		{PROTOCOL_GET_FRIEND_LIST_RQ,knl_get_friend_list},
		{0,0}
	};

	/*定义一个指向协议映射表的指针*/
	protocol_map *ptmp = protocol_entry;	

	/*获取包类型*/
	packtype_t *packtype = (packtype_t *)c_data;

	while(1)
	{
		if(ptmp->packtype == *packtype)
		{
			/*协议包匹配成功,执行相应的处理函数*/
			(ptmp->pfun)(clientdata);
			break;

		}
		else if(ptmp->packtype == 0 && ptmp->pfun == 0)
		{
			/*找不到对应的协议，可以向客户端发包告知错误*/
			break;
		}
		else
		{
			++ptmp;
		}
	}
	return NULL;

}
