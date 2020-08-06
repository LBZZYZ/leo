#include <pool.h>
int Thread_Add_Task(pool_t * pool,void*(*job)(void*),void *arg)
{
		pthread_mutex_lock(&pool->lock);
		//生产生阻塞于队列满
		while(pool->queue_size == pool->queue_max && pool->thread_shutdown==TRUE)
		{
				pthread_cond_wait(&pool->not_full,0);
		}
		if(pool->thread_shutdown == FALSE)
				pthread_exit(NULL);
		//被唤醒向任务队列添加一个任务,并且计算任务位置,当前任务数+1
		pool->queue_task[pool->queue_front].user = job;
		pool->queue_task[pool->queue_front].arg = arg;
		++(pool->queue_size);
		pool->queue_front = (pool->queue_front + 1 ) % pool->queue_max;
		pthread_mutex_unlock(&pool->lock);
		//添加任务后,唤醒任意一个消费者
		pthread_cond_signal(&pool->not_empty);
		return 0;
}
