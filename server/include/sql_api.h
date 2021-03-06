#ifndef _SQL_API_H_
#define _SQL_API_H_

#include "sql.h"
#include "mylist.h"
/*
sql api for upper layer
*/
SQL_RESULT sql_api_add_user(void *args);
SQL_RESULT sql_api_delete_user(void *args);
SQL_RESULT sql_api_update_user_info(void *args);
SQL_RESULT sql_api_is_user_online(void *args);
SQL_RESULT sql_api_is_user_exist(const char *userid);
SQL_RESULT sql_api_is_pwd_right(void *args);
SQL_RESULT sql_api_insert_user_online(void *args);
SQL_RESULT sql_api_select_user(void *args,list_t **lst);
SQL_RESULT sql_api_get_user_list(void *args,list_t **lst);
SQL_RESULT sql_api_get_user_ip(long long *llv_Id);
#endif //_SQL_API_H_
