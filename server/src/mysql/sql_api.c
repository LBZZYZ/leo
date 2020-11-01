#include "sql_api.h"
#include "sql_utils.h"

SQL_RESULT sql_api_add_user(void *args)
{
	//数据库插入语句
	char sql[MYSQLSIZE];
	bzero(sql,sizeof(sql));
	//解析insert语句
	sprintf(sql,"insert into usrinfos(usr_number,usr_name,usr_password,\
                    usr_age,usr_sex,usr_birth) values('%s','%s','%s',%d,'%c','%s');",\
				    1, 1, 1, 18, 1, 1);

    /*把添加新用户的逻辑写到这里*/
    if(SQL_OK == mysql_insert(sql))
    {
        return SQL_API_OK;
    }
    return SQL_API_ERR;
}

SQL_RESULT sql_api_delete_user(void *args)
{


}

SQL_RESULT sql_api_update_user_info(void *args)
{

}

SQL_RESULT sql_api_is_user_online(void *args)
{

}

SQL_RESULT sql_api_is_user_exist(void *args)
{
    list_t *lst;
	list_init(&lst);

	//数据库插入语句
	char sql[MYSQLSIZE];
	bzero(sql,sizeof(sql));

    sprintf(sql, "select usrid from usrinfos \
                    where usrid = '%s'", 1);
    if(SQL_OK == mysql_select(sql,lst))
    {
        return SQL_API_OK;
    }
    else
    {
        return SQL_API_ERR;
    }
    

}

SQL_RESULT sql_api_is_pwd_right(void *args)
{	
	char sql[MYSQLSIZE];
	bzero(sql,sizeof(sql));
	snprintf(sql,sizeof(sql),"select usr_password from usrinfos where usrid = '280761575'");

    list_t *lst;
    list_init(&lst);
    if(SQL_OK == mysql_select(sql,&lst))
    {
        return SQL_API_OK;
    }
    return SQL_API_ERR;
}

SQL_RESULT sql_api_insert_user_online(void *args)
{
   	if(args == NULL)
    {
        return SQL_API_INVALID;	
    }

	char lszv_Sql[BUFSIZE];
	bzero(lszv_Sql,sizeof(lszv_Sql));

	/*把id、ip、port写入usr_online表*/
	sprintf(lszv_Sql, "insert into usr_online \
                           value(%lld,%lld,%lld);", 1, 1, 1);


	if(SQL_OK == mysql_insert(lszv_Sql))
	{
		return SQL_API_OK;
	}

	return SQL_API_ERR; 
}


SQL_RESULT sql_api_select_user(void *args,list_t **lst)
{
    if(args == NULL | lst == NULL)
    {
        return SQL_API_INVALID;
    }

	char sql[MYSQLSIZE];
	bzero(sql,sizeof(sql));

	snprintf(sql,sizeof(sql),"select usrname,birth,sex from usrinfos where usrid = %lld", 1);
	
    if(SQL_OK == mysql_select(sql,lst))
    {
        return SQL_API_OK;
    }

    return SQL_API_ERR;

}

SQL_RESULT sql_api_get_user_list(void *args,list_t **lst)
{
    //usr_friends & userinfos两张表
    if(args == NULL)
    {
        return SQL_API_INVALID;
    }

	char id_statement[MYSQLSIZE] = {0};
	char name_statement[MYSQLSIZE] = {0};
	snprintf(id_statement,MYSQLSIZE,"select friend_id from usr_friends where user_id = %lld union all select user_id from usr_friends where friend_id = %lld;", 1, 1);
	
	list_t *lpv_Idlist = NULL;
	list_t *lpv_Namelist = NULL;
	list_init(&lpv_Idlist);
	list_init(&lpv_Namelist);
	
	if(SQL_OK == mysql_select(id_statement,lpv_Idlist))
    {
        if(lpv_Idlist != NULL)
        {
            long long lsv_Id = 0;
            char * str = NULL;
            char * lsv_Name = NULL;
            int i = 0;
            while((str = lst_pop(lpv_Idlist)) != NULL/*&& (lsv_Name = lst_pop(lpv_Namelist) != NULL)*/)
            {
                lsv_Id = atoll(str);
                //rs.friendlistmsg[i].id = lsv_Id;
                
                snprintf(name_statement,MYSQLSIZE,"select usrname from usrinfos where usrid = %lld;",lsv_Id);
                if(SQL_OK == mysql_select(name_statement,lpv_Namelist))
                {
                    lsv_Name = lst_pop(lpv_Namelist);
                    //strncpy(rs.friendlistmsg[i].name,lsv_Name,45);
                    ++i;

                }
            }
        }
    }

	return SQL_API_ERR;
}


SQL_RESULT sql_api_get_user_ip(long long *llv_Id)
{
	list_t *lpv_List = NULL;
	list_init(&lpv_List);
	
	char lszv_Sql[BUFSIZE];
	bzero(lszv_Sql,sizeof(lszv_Sql));

	sprintf(lszv_Sql,"select ip from usr_online where id = %lld;",llv_Id);

	if(SQL_OK == mysql_select(lszv_Sql,lpv_List))
	{
		*llv_Id = atoi(lst_pop(lpv_List));
		return SQL_API_OK;
	}
	return SQL_API_ERR;
	
}
