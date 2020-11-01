#include "sql_utils.h"

SQL_RESULT mysql_insert(const char* sql)
{
	//从数据库连接池拿取链接
	SQL_NODE *mysql_connect = get_db_connect(sql_conn_pool);
	if(sql == NULL)
    {
		return SQL_ERR;
    }

	if(mysql_query(mysql_connect->mysql_sock,sql))
	{
		return SQL_ERR;
	}

	//归还数据库连接
	release_node(sql_conn_pool,mysql_connect);
	return SQL_OK;
}

SQL_RESULT mysql_delete(const char* sql)
{
	//从数据库连接池拿取链接
	SQL_NODE *mysql_connect = get_db_connect(sql_conn_pool);
	if(sql == NULL)
    {
		return SQL_ERR;
    }

	if(mysql_query(mysql_connect->mysql_sock,sql))
	{
		return SQL_ERR;
	}
	//归还数据库连接
	release_node(sql_conn_pool,mysql_connect);
	return SQL_OK;
}

SQL_RESULT mysql_update(const char* sql)
{	
	//从数据库连接池拿取链接
	SQL_NODE *mysql_connect = get_db_connect(sql_conn_pool);
	if(sql == NULL)
    {
		return SQL_ERR;
    }

	if(mysql_query(mysql_connect->mysql_sock,sql))
	{
		return SQL_ERR;
	}
	//归还数据库连接
	release_node(sql_conn_pool,mysql_connect);
	return SQL_OK;
}

SQL_RESULT mysql_select(const char* sql,list_t *lst)
{
	//从数据库连接池拿取链接
	SQL_NODE *mysql_connect = get_db_connect(sql_conn_pool);

	unsigned int num_fields;	//列数
	MYSQL_RES *results;		//结果集
	MYSQL_ROW record;

	if(mysql_query(mysql_connect->mysql_sock,sql)) 	/*成功返回0*/
	{
		return SQL_ERR;
	}

	/*MYSQL_RES *mysql_store_result(MYSQL *mysql)*/
	/*在mysql_query()之后必须调用它来产生一个结果集*/
	if(NULL == (results = mysql_store_result(mysql_connect->mysql_sock)))
	{
		return SQL_ERR;
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
			char *temp = (char*)malloc(sizeof(char)*(strlen(record[i])+1));
			strcpy(temp,record[i]);
			lst_push(lst,temp);
		}
	}
	//归还数据库连接
	release_node(sql_conn_pool,mysql_connect);
	return SQL_OK;
}




