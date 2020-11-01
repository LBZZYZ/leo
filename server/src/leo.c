//#include "net.h"
#include "dlfcn.h"
#include "pool.h"
#include "sql_pool.h"
#include <stdio.h>
#include "./ccl-0.1.1/ccl/ccl.h"
       

int main()
{
        struct ccl_t config;
        const struct ccl_pair_t *iter;

        const char *mysql_ip;
        const char *mysql_db_name;
        const char *mysql_user;
        const char *mysql_user_pwd;
        int   _mysql_port;
        
        config.comment_char = '#';
        config.sep_char = '=';
        config.str_char = '"';
        
        ccl_parse(&config,"../leo.conf");

        mysql_ip = ccl_get(&config,"mysql_ip");
        mysql_db_name = ccl_get(&config,"mysql_db_name");
        mysql_user = ccl_get(&config,"mysql_user");
        mysql_user_pwd = ccl_get(&config,"mysql_user_pwd");
        _mysql_port = atoi(ccl_get(&config,"mysql_port"));

        //创建数据库连接池
        SQL_CONN_POOL *sql_conn_pool = sql_pool_create(POOL_MAX_NUMBER, \
                               mysql_ip, _mysql_port, mysql_db_name, mysql_user, mysql_user_pwd);
	printf("leo.c:%p\n",sql_conn_pool);
 
        if(sql_conn_pool != NULL)
        {
	    printf("[1]数据库连接池初始化成功\n");
        }

	else
        {
            printf("[1]数据库连接池初始化失败\n");
        }
        
	//创建线程池
	pool_t *pool = Thread_Create(20, 10, 10);

	//启动网络模块
	net_open(pool);
	
	return 0;
}