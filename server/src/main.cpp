#include "net.h"
#include "dlfcn.h"
#include "pool.h"
#include "sqlpool.h"


//创建数据库连接池
SQL_CONN_POOL *sql_conn_pool = sql_pool_create(POOL_MAX_NUMBER,"localhost",3306,"im","root","C019cf99c24e");
int main()
{
	if(sql_conn_pool != NULL)
		printf("[1]数据库连接池初始化成功\n");
	else
		printf("[1]数据库连接池初始化失败\n");
	//创建线程池
	pool_t *pool = Thread_Create(20,10,10);
	//启动网络模块
	net_open(pool);
	
	//SQL_NODE *new_connect = get_db_connect(sql_conn_pool);
	//mysql_query(new_connect->mysql_sock,"insert into usrinfos(usr_number,usr_name,usr_password,usr_age,usr_sex,usr_birth) values('280761575','LBZ','libingzhi5241.',22,'m',19990104);");
	
	return 0;
}
