#include "CMySql.h"

/*构造函数*/
CMySql::CMySql(void)
{
    sock = new MYSQL;
    mysql_init(sock); /*初始化MYSQL结构体*/
    if(!mysql_set_character_set(sock,"utf8"))return;
}

/*析构函数*/
CMySql::~CMySql(void)
{
    if(sock)
    {
        delete sock;
        sock = NULL;
    }
    
}

/**/
void CMySql::DisConnect()
{
    mysql_close(sock); /*断开链接,释放MYSQL结构体*/
}


/*链接数据库*/
bool CMySql::ConnectMySql(const char *host,const char *user,const char *pass,const char *db,short nport)
{
   
	if (!mysql_real_connect(sock, host, user, pass, db, nport, NULL, CLIENT_MULTI_STATEMENTS))
	{
		return false;
	}
	
    return true;
}

bool CMySql::SelectMySql(const char* szSql,list_t *list)
{

	unsigned int num_fields;

     if(mysql_query(sock,szSql)) 	/*成功返回0*/
	 {
		 return false;
	 }

	/*MYSQL_RES *mysql_store_result(MYSQL *mysql)*/
	/*在mysql_query()之后必须调用它来产生一个结果集*/
	if(NULL == (results = mysql_store_result(sock)))
	{
		return false;
	}

	/*unsigned int mysql_num_fields(MYSQL_RES *result)*/
	/*返回结果集的列数*/
	num_fields = mysql_num_fields(results);
	cout << "num_fields:"<<num_fields << endl;
	/*MYSQL_ROW mysql_fetch_row(MYSQL_RES *result*/
	/*返回结果集的下一行*/
	while (NULL != (record = mysql_fetch_row(results)))    
	{
        
		 for(unsigned int i = 0;i < num_fields;i++)
         {
			if(!record[i])
				record[i] = (char*)"";

			lst_push(list,record[i]);
         }
    

	}

    return true;
}

bool  CMySql::UpdateMySql(const char* szSql)
 {
    if(!szSql)return false;

    if(mysql_query(sock,szSql))
	{
		cout << mysql_error(sock);
		return false;
	}

    return true;
 }


