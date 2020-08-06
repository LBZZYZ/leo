#ifndef _POOL_H_
#define _POOL_H_
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>


#define	TRUE	1
#define	FALSE	0
#define	TIMEOUT	1
#define MAXPOOLSIZE 100
#define MINPOOLSIZE 50
#define MAXQUESIZE 100

//任务队列
typedef struct
{
		void*(*user)(void*);
		void * arg;
}task_t;

typedef struct
{
		int thread_shutdown;
		int thread_max;
		int thread_min;
		int thread_alive;
		int thread_busy;
		int thread_wait;
		int queue_max;
		int queue_size;
		int queue_front;
		int queue_rear;
		pthread_t * tids;
		task_t * queue_task;
		pthread_mutex_t lock;
		pthread_cond_t not_full;
		pthread_cond_t not_empty;
		pthread_t managerid;

}pool_t;


/*任务函数参数结构体*/
typedef struct 
{
	int sockfd;
	unsigned long ip;
	const char *buf;
	size_t len;

}task_arg_t;

void errstr(const char *);
void * Thread_Custom_Job(void * );
void * Thread_Manager_Job(void *);
void * Thread_User_Job(void *);
int Thread_Destroy(pool_t *);
int Thread_Add_Task(pool_t * ,void *(*)(void*),void *);
//int Thread_Add_Task(pool_t * pool,int(*job)(int,unsigned long,const char *,size_t),void *arg);
pool_t * Thread_Create(int,int,int);
int if_test_threadalive(pthread_t);
int socket_init(int,int,int,int,int,int);
#endif
