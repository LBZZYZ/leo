#include <pool.h>

pool_t * Thread_Create(int max,int min,int quemax)
{
		int err;
		//初始化线程池阀值
		pool_t * pool;
		if((pool = (pool_t *)malloc(sizeof(pool_t)))==NULL){
				perror("Thread_Create Malloc Error");
				return NULL;
		}
		pool->thread_max = max;
		pool->thread_min = min;
		pool->queue_max = quemax;
		pool->thread_shutdown = TRUE;
		pool->thread_alive = 0;
		pool->thread_busy = 0;
		pool->queue_size = 0;
		pool->queue_front = 0;
		pool->queue_rear = 0;
		//线程id数组申请空间
		if((pool->tids = (pthread_t *)malloc(sizeof(pthread_t) * max))==NULL){
				perror("Thread_Create Malloc Thread tids Error");
				return NULL;
		}
		memset(pool->tids,0,sizeof(pthread_t)*max);
		//任务队列申请空间
		if((pool->queue_task = (task_t *)malloc(sizeof(task_t) * quemax))==NULL){
				perror("Thread_Create Malloc Queue Task Error");
				return NULL;
		}
		//初始化锁,环境变量
		if(pthread_mutex_init(&(pool->lock),NULL)!=0 || pthread_cond_init(&(pool->not_full),NULL)!=0 || pthread_cond_init(&(pool->not_empty),NULL)!=0){

				perror("Thread_Create Init mutex or cond Error");
				return NULL;
		}
		//循环创建消费者,按线程池最小线程数创建
		for(int i=0;i<min;i++){
				if((err = pthread_create(&(pool->tids[i]),NULL,Thread_Custom_Job,(void *)pool))>0){
						printf("Pthread_Create Custom Error:%s\n",strerror(err));
						return NULL;
				}
				/*每次创建存活线程数++*/
				++(pool->thread_alive);
		}
		//创建管理者线程
		if((err = pthread_create(&pool->managerid,NULL,Thread_Manager_Job,(void*)pool))>0){
				printf("Pthread_Create Manager Error:%s\n",strerror(err));
				return NULL;
		}
		return pool;
}
