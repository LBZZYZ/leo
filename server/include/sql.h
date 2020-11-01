#ifndef _SQL_H_
#define _SQL_H_

#include </usr/include/mysql/mysql.h>

/*
RETURN VALUE macro define
*/
#define SQL_OK        0
#define SQL_ERR      -1
#define SQL_INVALID   1 


/*
API RETURN VALUE macro define
*/
#define SQL_API_OK        0
#define SQL_API_ERR      -1
#define SQL_API_INVALID   1 


/*RETURN VALUE data type*/
tpyedef int SQL_RESULT;

/*
user info define
*/
#define USER_INFO_BASE 10
#define USER_INFO_PHONE USER_INFO_BASE + 1
#define USER_INFO_PWD   USER_INFO_BASE + 2
#define USER_INFO_NAME  USER_INFO_BASE + 3
#define USER_INFO_SEX   USER_INFO_BASE + 4
#define USER_INFO_SIGNATURE USER_INFO_BASE + 5
#define USER_INFO_BIRTH USER_INFO_BASE + 6

#endif //_SQL_H_