#include <pool.h>


void * Thread_Custom_Job(void * arg)
{
		pool_t * pool = (pool_t *)arg;
		task_t task;
		//消费者循环使用
		while(1){
				//如果队列为空阻塞
				pthread_mutex_lock(&pool->lock);
				while(pool->queue_size == 0 && pool->thread_shutdown == TRUE){
						pthread_cond_wait(&pool->not_empty,&pool->lock);
				}
				if(pool->thread_shutdown==FALSE){
						--pool->thread_alive;
						pthread_exit(NULL);
				}
				//被唤醒判断是否结束自身
				if(pool->thread_wait > 0)
				{
					--pool->thread_wait;
					--pool->thread_alive;
					pthread_mutex_unlock(&pool->lock);
					pthread_exit(NULL);
				}
				//任务队列拿取一个任务,调用执行,计算索引值,当前任务数--,
				task.user = pool->queue_task[pool->queue_rear].user;
				task.arg = pool->queue_task[pool->queue_rear].arg;
				--pool->queue_size;
				pool->queue_rear = (pool->queue_rear+ 1) % pool->queue_max;
				++pool->thread_busy;
				pthread_mutex_unlock(&pool->lock);
				//调用任务
				(*(task.user))(task.arg);
				pthread_mutex_lock(&pool->lock);
				--pool->thread_busy;
				pthread_mutex_unlock(&pool->lock);
				//保证队列非满,唤醒一个生产者继续生产
				pthread_cond_signal(&pool->not_full);
		}
}
