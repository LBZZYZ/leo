#ifndef _SQL_UTILS_H_
#define _SQL_UTILS_H_

#include "sql.h"
#include "sql_pool.h"
#include "mylist.h"


/*
MYSQL utils
*/
SQL_RESULT mysql_insert(const char* sql);
SQL_RESULT mysql_delete(const char* sql);
SQL_RESULT mysql_update(const char* sql);
SQL_RESULT mysql_select(const char* sql,list_t *list);

extern SQL_CONN_POOL *sql_conn_pool;


#endif //_SQL_UTILS_H_
