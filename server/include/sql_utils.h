#ifndef _SQL_UTILS_H_
#define _SQL_UTILS_H_

#include "sql.h"
#include "mylist.h"


/*
MYSQL utils
*/
SQL_RESULT mysql_insert(const char* sql);
SQL_RESULT mysql_delete(const char* sql);
SQL_RESULT mysql_update(const char* sql);
SQL_RESULT mysql_select(const char* sql,list_t *list);



#endif //_SQL_UTILS_H_