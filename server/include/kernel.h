#ifndef _KERNEL_H_
#define _KERNEL_H_

#include "protocol.h"    

#define KNL_ERROR  -1
#define KNL_OK      0
#define KNL_INVALID 1

typedef int KNL_RESULT;
typedef int (*ptrfun_t) (void *);    /*任务函数指针*/

void*      knl_deal_data(void*);
KNL_RESULT knl_registe(void*);
KNL_RESULT knl_login(void*);
KNL_RESULT knl_search_user(void*);
KNL_RESULT knl_add_user(void*);
KNL_RESULT knl_add_user_rs(void*);
KNL_RESULT knl_is_user_online(int,int,int);
KNL_RESULT knl_send_msg(void*);
KNL_RESULT knl_get_friend_list(void*);

/*协议包映射结构*/
typedef struct protocol_map
{
	packtype_t packtype;    
	ptrfun_t pfun;

}protocol_map;

#endif //_KERNEL_H_
