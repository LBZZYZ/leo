#pragma once
#include <iostream>
#include <mysql.h>
#include <list>
#include <string>
#include <strings.h>
#include "mylist.h"

using namespace std;

class CMySql
{
	public:
		CMySql(void);
		~CMySql(void);
	public:
		bool  ConnectMySql(const char *host,const char *user,const char *pass,const char *db,short nport = 3306);
		void  DisConnect();
		bool  SelectMySql(const char* szSql,list_t *list);
		bool  UpdateMySql(const char* szSql);

	private:
		MYSQL *sock;   
		MYSQL_RES *results;   
		MYSQL_ROW record; 		/*typedef char** MYSQL_ROW*/

};

