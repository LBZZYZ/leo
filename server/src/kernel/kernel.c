#include "kernel.h"
#include "net.h"
#include "CMySql.h"    /*注册、登录等使用的头文件*/
#include <stdlib.h>
#include "mylist.h"
#include "err_sys.h"
#include "sqlpool.h"
#include "mysql_api.h"

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

int insert_online_user(long long llv_Id,long long llv_Ip,long long llv_Port)
{
	if(llv_Id == 0 || llv_Ip == 0 || llv_Port == 0)return -1;	
	char lszv_Sql[BUFSIZE];
	bzero(lszv_Sql,sizeof(lszv_Sql));
	/*把id、ip、port写入usr_online表*/
	sprintf(lszv_Sql,"insert into usr_online value(%lld,%lld,%lld);",llv_Id,llv_Ip,llv_Port);

	/*数据库连接*/
	CMySql mysql;
	if(false == (mysql.ConnectMySql("localhost","root","libingzhi5241.","usrinfo")))
	{
		printf("CONNECTMYSQL\n");
		return -1;
	}

	if(false == mysql.UpdateMySql(lszv_Sql))
	{
		printf("UPDATEMYSQL");
		return -1;
	}
	return 0;
}


void* deal_data(void* clientdata)    /*key is equal to ip or socket*/
{
	//解析参数包
	struct client_data *c_data = (struct client_data*)clientdata;

	/*包协议与函数指针建立的协议包映射表*/
	protocol_map protocol_entry[] = 
	{
		{PROTOCOL_REGISTER_RQ,registe},
		{PROTOCOL_LOGIN_RQ,login},
		{PROTOCOL_SEARCH_USER_RQ,searchuser},
		{PROTOCOL_USER_ADD_RQ,adduser},
		{PROTOCOL_USER_ADD_RS,adduser_rs},
		{PROTOCOL_SEND_MSG_RQ,sendmsg},
		{PROTOCOL_GET_FRIEND_LIST_RQ,get_friend_list},
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
			printf("match success\n");
			printf("packtype:%d\n",*packtype);
			(ptmp->pfun)(clientdata);
			break;

		}
		else if(ptmp->packtype == 0 && ptmp->pfun == 0)
		{
			/*找不到对应的协议，可以向客户端发包告知错误*/
			printf("match fail\n");
			printf("packtype:%d\n",*packtype);
			break;
		}
		else
		{
			printf("++ptmp\n");
			++ptmp;
		}
	}
	return NULL;

}


/*注册*/
int registe(void *clientdata)
{
	printf("(1)注册\n");

	struct client_data *c_data = (struct client_data*)clientdata;
	c_data->w_length = sizeof(registe_rs_t);

	//获取注册请求包
	registe_rq_t *rq = (registe_rq_t *)(c_data->read_buf);
	//定义注册回复包
	registe_rs_t rs;
	//引入数据库连接池全局变量
	extern SQL_CONN_POOL *sql_conn_pool;
	//从数据库连接池拿取链接
	SQL_NODE *mysql_connect = get_db_connect(sql_conn_pool);
	//数据库插入语句
	char sql[MYSQLSIZE];
	bzero(sql,sizeof(sql));
	printf("BIRTH:%s\n",rq->birth);

	//解析select语句
	sprintf(sql,"select usr_number from usrinfos where usr_number = '%s'",rq->usrid);
	//向数据库查询
	list<char*> lst;
	mysql_select(mysql_connect->mysql_sock,sql,&lst);


	if(lst.empty() == true)
	{

		//解析insert语句
		sprintf(sql,"insert into usrinfos(usr_number,usr_name,usr_password,usr_age,usr_sex,usr_birth) values('%s','%s','%s',%d,'%c','%s');",
				rq->usrid,rq->usrname,rq->password,18,rq->sex,rq->birth);
		//使用新的数据库连接向数据库插入数据
		if(true == mysql_update(mysql_connect->mysql_sock,sql))rs.result = SUCCEED;
	}
	else
	{
		rs.result = FAILED;
	}
	//归还数据库连接
	release_node(sql_conn_pool,mysql_connect);



	/*构造回复包*/
	rs.packtype = PROTOCOL_REGISTER_RS;
	rs.packnum = rq->packnum;
	registe_rs_t *r_rs = (registe_rs_t*)c_data->write_buf;
	r_rs->packnum = rs.packnum;
	r_rs->result = rs.result;
	r_rs->packtype = rs.packtype;


	r_rs->result = SUCCEED;
	c_data->dest_addr.sin_family = c_data->src_addr.sin_family;
	c_data->dest_addr.sin_port = c_data->src_addr.sin_port;
	c_data->dest_addr.sin_addr.s_addr = c_data->src_addr.sin_addr.s_addr;
	epoll_add_event(c_data->epollfd,c_data->fd);

	return true;
}



/*登录*/
int login(void *clientdata)
{
	printf("(2)登陆\n");
	/*获取客户端数据*/
	struct client_data *c_data = (struct client_data*)clientdata;

	/*获取登录请求包*/
	login_rq_t *rq = (login_rq_t*)c_data->read_buf;


	/*构造登录回复包*/
	login_rs_t rs;
	rs.packtype = PROTOCOL_LOGIN_RS;
	rs.result = FAILED;

	/*向客户数据中写入回复包*/
	login_rs_t *c_rs = (login_rs_t*)c_data->write_buf;
	c_rs->packtype = rs.packtype;
	c_rs->result = rs.result;
	c_data->w_length = sizeof(login_rs_t);

	//构造select语句
	char sql[MYSQLSIZE];
	bzero(sql,sizeof(sql));
	snprintf(sql,sizeof(sql),"select usr_password from usrinfos where usrid = '%s'",rq->usrid);

	//引入数据库连接池全局变量
	extern SQL_CONN_POOL *sql_conn_pool;

	//从数据库连接池拿取链接
	SQL_NODE *mysql_connect = get_db_connect(sql_conn_pool);
	if(mysql_connect == NULL)printf("TAT\n");

	list<char*> lst;
	printf("QAQ\n");
	if(false == mysql_select(mysql_connect->mysql_sock,sql,&lst))rs.result = FAILED;
	if(lst.empty() == true)rs.result = FAILED;
	if(0 == strcmp(rq->password,lst.front()))
	{
		rs.result = SUCCEED;
		c_rs->result = rs.result;
		printf("success\n");
	}
	/*把上线用户插入usr_online表*/
	/*if(-1 == insert_online_user(rq->usrid,c_data->src_addr.sin_addr.s_addr,c_data->src_addr.sin_port))
	{
		printf("INSERT ONLINE USER\n");
	}*/

	epoll_add_event(c_data->epollfd,c_data->fd);

	return 0;

}

/*查找好友*/
int searchuser(void *clientdata)
{
	printf("查找好友\n");
	/*获取查找好友请求包*/
	struct client_data *c_data = (struct client_data*)clientdata;
	search_rq_t *s_rq = (search_rq_t*)c_data->read_buf;

	/*包异常检测*/
	if(s_rq->usrid == 0 || s_rq->searchid == 0)
	{
		return -1;
	}

	/*构造查找回复包*/
	search_rs_t *s_rs = (search_rs_t*)c_data->write_buf;
	c_data->w_length = sizeof(search_rs_t);
	s_rs->packtype = PROTOCOL_SEARCH_USER_RS;

	/*数据库查找匹配*/
	char mysql_statement[MYSQLSIZE];
	bzero(mysql_statement,sizeof(mysql_statement));
	snprintf(mysql_statement,sizeof(mysql_statement),"select usrname,birth,sex from usrinfos where usrid = %lld",s_rq->searchid);
	printf("ID:%lld\n",s_rq->searchid);

	CMySql mysql;
	if(false == (mysql.ConnectMySql("localhost","root","libingzhi5241.","usrinfo")))
	{

		printf("connectmysql\n");
		return -1;
	}
	list_t *list = NULL;
	list_init(&list);
	printf("添加好友QAQ\n");
	if(false == (mysql.SelectMySql(mysql_statement,list)))
	{
		printf("select failed\n");
		return -1;
	}
	char *str = NULL;
	printf("name\n");
	str = lst_pop(list);
	printf("name:%s\n",str);
	strncpy(s_rs->s_name,str,strlen(str));
	printf("name:%s\n",str);
	str = lst_pop(list);
	strncpy(s_rs->s_birth,str,strlen(str));
	printf("birth:%s\n",str);
	str = lst_pop(list);
	s_rs->s_sex = *str;
	epoll_add_event(c_data->epollfd,c_data->fd);


	return 0;
}

static long long GetClientIp(long long llv_Id)
{
	CMySql mysql;
	mysql.ConnectMySql("localhost","root","libingzhi5241.","usrinfo");
	list_t *lpv_List = NULL;
	list_init(&lpv_List);
	char lszv_Sql[BUFSIZE];
	bzero(lszv_Sql,sizeof(lszv_Sql));
	sprintf(lszv_Sql,"select ip from usr_online where id = %lld;",llv_Id);
	mysql.SelectMySql(lszv_Sql,lpv_List);
	return atoi(lst_pop(lpv_List));
}
int adduser(void *clientdata)
{
	printf("添加好友\n");


	if(clientdata == NULL)exit(EXIT_FAILURE);
	struct client_data *lpv_Clientdata = (struct client_data*)clientdata;
	add_rq_t *lpv_Addrq = (add_rq_t*)lpv_Clientdata->read_buf;
	/*获取想要添加的客户端IP*/
	long long llv_Ip = 0;
	llv_Ip = GetClientIp(lpv_Addrq->searchid);
	printf("lpv_Addrq->searchid:%lld\n",lpv_Addrq->searchid);

	/*if(-1 == test_is_alive(lpv_Clientdata->fd,llv_Ip,htons(8000)))
	  {
	//客户端离线
	//将代发送数据写入离线数据表
	printf("client offline\n");
	return 0;
	}
	else
	{*/
	//客户端在线
	add_rq_t *p = (add_rq_t*)lpv_Clientdata->write_buf;
	p->usrid = lpv_Addrq->usrid;
	p->searchid = lpv_Addrq->searchid;
	p->packtype = lpv_Addrq->packtype;
	p->packnum = lpv_Addrq->packnum;
	printf("src:%lld\tdest:%lld\n",p->usrid,p->searchid);
	lpv_Clientdata->w_length = lpv_Clientdata->r_length;
	lpv_Clientdata->dest_addr.sin_family = AF_INET;
	lpv_Clientdata->dest_addr.sin_addr.s_addr = llv_Ip;
	lpv_Clientdata->dest_addr.sin_port = htons(4567);
	epoll_add_event(lpv_Clientdata->epollfd,lpv_Clientdata->fd);
	printf("client online\n");

	/*}*/

	return 0;
}

int adduser_rs(void *clientdata)
{
	if(NULL == clientdata)return -1;
	client_data *lpv_Clientdata = (client_data*)clientdata;
	add_rs_t *lpv_Addrs = (add_rs_t*)lpv_Clientdata->read_buf;
	printf("dest_id:%lld\n",lpv_Addrs->dest_id);
	//long long llv_Ip = 0;
	//long long llv_Ip = GetClientIp(lpv_Addrs->dest_id);
	/*if(-1 == test_is_alive(lpv_Clientdata->fd,llv_Ip,htons(8000)))
	  {

	  }
	  else
	  {*/
	//客户端在线
	printf("服务器转发回复包\n");
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
	printf("IP:%s\n",ip);
	lpv_Clientdata->dest_addr.sin_port = htons(4567);
	epoll_add_event(lpv_Clientdata->epollfd,lpv_Clientdata->fd);

	/*解析包结果，同意则把好友关系插入到usr_friends表中*/


	return 0;
}

/*消息转发*/
int sendmsg(void* clientdata)
{
	printf("消息转发\n");
	if(NULL == clientdata)exit(EXIT_FAILURE);
	struct client_data *lpv_Clientdata = (struct client_data*)clientdata;
	msg_rq_t *lpv_Msg = (msg_rq_t*)lpv_Clientdata->read_buf;
	msg_rq_t *p = (msg_rq_t*)lpv_Clientdata->write_buf;
	long long llv_Receiverip = GetClientIp(lpv_Msg->receiverid);
	p->senderid = lpv_Msg->senderid;
	p->receiverid = lpv_Msg->receiverid;
	p->packtype = PROTOCOL_SEND_MSG_RS;
	p->packnum = lpv_Msg->packnum;
	strncpy(p->text,lpv_Msg->text,strlen(lpv_Msg->text));
	printf("Msg Context:%s\n",p->text);
	printf("src:%lld\tdest:%lld\n",p->senderid,p->receiverid);
	lpv_Clientdata->w_length = lpv_Clientdata->r_length;
	lpv_Clientdata->dest_addr.sin_family = AF_INET;
	lpv_Clientdata->dest_addr.sin_addr.s_addr = llv_Receiverip;
	lpv_Clientdata->dest_addr.sin_port = htons(4567);
	epoll_add_event(lpv_Clientdata->epollfd,lpv_Clientdata->fd);
	printf("发送完成\n");

	return 0;
}


/*********************************************
  函数名       : get_friend_list
  函数功能描述 : 向客户端发送好友列表
  函数参数     : void*
  函数返回值   : int
  函数作者     : 李柄志
  函数创建日期 : 2019.07.24
  函数修改日期 : *
  修改人       : *
  修改原因     : *
  版本         : 1.0
  历史版本     : 无
 *********************************************/
int get_friend_list(void* clientdata)
{
	printf("获取好友列表...\n");
	if(NULL == clientdata)return -1;
	struct client_data *lpv_Clientdata = (struct client_data*)clientdata;
	getfriendlist_rq_t *p = (getfriendlist_rq_t*)lpv_Clientdata->read_buf;
	long long llv_Senderid = p->senderid;
	printf("Sender id :%lld\n",llv_Senderid);
	getfriendlist_rs_t rs;
	bzero(&rs,sizeof(rs));
	rs.packtype = PROTOCOL_GET_FRIEND_LIST_RS;

	/*数据库连接*/
	CMySql mysql;
	if(false == (mysql.ConnectMySql("localhost","root","libingzhi5241.","usrinfo")))
	{
		printf("CONNECTMYSQL\n");
		return -1;
	}
	char id_statement[MYSQLSIZE] = {0};
	char name_statement[MYSQLSIZE] = {0};
	snprintf(id_statement,MYSQLSIZE,"select friend_id from usr_friends where user_id = %lld union all select user_id from usr_friends where friend_id = %lld;",llv_Senderid,llv_Senderid);
	list_t *lpv_Idlist = NULL;
	list_t *lpv_Namelist = NULL;
	list_init(&lpv_Idlist);
	list_init(&lpv_Namelist);
	mysql.SelectMySql(id_statement,lpv_Idlist);
	if(lpv_Idlist == NULL)
	{
		printf("list empty\n");
		return -1;
	}
	long long lsv_Id = 0;
	char * str = NULL;
	char * lsv_Name = NULL;
	int i = 0;
	printf("0\n");
	while((str = lst_pop(lpv_Idlist)) != NULL/*&& (lsv_Name = lst_pop(lpv_Namelist) != NULL)*/)
	{
		printf("QAQ\n");
		lsv_Id = atoll(str);
		rs.friendlistmsg[i].id = lsv_Id;
		/*通过ID查询用户名*/
		snprintf(name_statement,MYSQLSIZE,"select usrname from usrinfos where usrid = %lld;",lsv_Id);
		mysql.SelectMySql(name_statement,lpv_Namelist);
		lsv_Name = lst_pop(lpv_Namelist);
		strncpy(rs.friendlistmsg[i].name,lsv_Name,45);
		printf("%s\n",rs.friendlistmsg[i-1].name);
		++i;

	}


	printf("i:%d\n",i);
	rs.friendnum = i;
	memcpy(lpv_Clientdata->write_buf,(char*)&rs,8+i*sizeof(friendlistmsg_t));
	lpv_Clientdata->w_length = 8+ i*sizeof(friendlistmsg_t);
	epoll_add_event(lpv_Clientdata->epollfd,lpv_Clientdata->fd);

	return 0;
}

int test_is_alive(int fd,int ip,int port)
{
	if(ip == 0)return -1;
	heart_t heart;
	heart.packtype = PROTOCOL_HEART;
	sockaddr_in clientaddr;
	bzero(&clientaddr,sizeof(clientaddr));
	clientaddr.sin_family = AF_INET;
	clientaddr.sin_port = port;
	clientaddr.sin_addr.s_addr = ip;
	if(-1 == sendto(fd,(const char*)&heart,sizeof(heart),0,(const struct sockaddr*)&clientaddr,sizeof(clientaddr)))
	{
		//发送失败，代表客户端不在线
		return -1;
	}
	printf("QAQ\tQAQ\n");

	return 0;
}
