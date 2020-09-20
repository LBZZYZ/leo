#include "mysql_api.h"
#include <cstring>

//select
bool mysql_select(MYSQL *sock,const char* sql,list_t *lst)
{

	unsigned int num_fields;	//列数
	MYSQL_RES *results;		//结果集
	MYSQL_ROW record;

	if(mysql_query(sock,sql)) 	/*成功返回0*/
	{
		return false;
	}

	/*MYSQL_RES *mysql_store_result(MYSQL *mysql)*/
	/*在mysql_query()之后必须调用它来产生一个结果集*/
	if(NULL == (results = mysql_store_result(sock)))
	{
		return false;
	}

	/*返回结果集的列数*/
	/*unsigned int mysql_num_fields(MYSQL_RES *result)*/
	num_fields = mysql_num_fields(results);

	/*返回结果集的下一行*/
	/*MYSQL_ROW mysql_fetch_row(MYSQL_RES *result*/
	while (NULL != (record = mysql_fetch_row(results)))    
	{

		for(unsigned int i = 0;i < num_fields;i++)
		{
			if(record[i] == NULL)record[i] = (char*)"";
			char *temp = new char[strlen(record[i])+1];
			strcpy(temp,record[i]);
			lst_push(lst,temp);
		}
	}

	return true;
}

//update
bool  mysql_update(MYSQL *sock,const char* sql)
{
	if(sql == NULL)return false;

	if(mysql_query(sock,sql))
	{
		cout << mysql_error(sock);
		return false;
	}

	return true;
}


