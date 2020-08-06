#pragma once
#include <iostream>
#include <mysql.h>
#include <list>

using namespace std;

bool mysql_select(MYSQL *sock,const char* sql,list<char*> *list);
bool  mysql_update(MYSQL *sock,const char* sql);

