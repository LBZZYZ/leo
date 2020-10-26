#ifndef _KERNEL_H_
#define _KERNEL_H_

#include "protocol.h"    
#include "mylist.h"
#include "sqlpool.h"

SQL_CONN_POOL *sql_conn_pool = NULL;

void* deal_data(void*);    /*key is equal to ip or socket*/
int registe(void*);
int login(void*);
int searchuser(void*);
int adduser(void*);
int adduser_rs(void*);
int test_is_alive(int,int,int);
int send_msg(void*);
int get_friend_list(void*);
typedef int (*ptrfun_t) (void *);    /*任务函数指针*/

/*协议包映射结构*/
typedef struct protocol_map
{
	packtype_t packtype;    /*包类型*/
	ptrfun_t pfun;   		/*函数指针*/

}protocol_map;

#endif
