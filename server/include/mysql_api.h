#pragma once

#include </usr/include/mysql/mysql.h>
#include "mylist.h"

bool mysql_select(MYSQL *sock,const char* sql,list_t *list);
bool  mysql_update(MYSQL *sock,const char* sql);
