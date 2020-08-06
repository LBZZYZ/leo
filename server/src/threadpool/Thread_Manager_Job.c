#include <pool.h>
void * Thread_Manager_Job(void *arg)
{
		int alive,busy,size;
		pool_t * pool = (pool_t*)arg;
		//接收线程池阀值
		while(pool->thread_shutdown)
		{
				int i,add;
				pthread_mutex_lock(&pool->lock);
				alive = pool->thread_alive;
				busy = pool->thread_busy;
				size = pool->queue_size;
				pthread_mutex_unlock(&pool->lock);
				//扩容线程
				if((size > (alive - busy) || ((float)busy/alive)*(float)100 >= (float)70) && alive < pool->thread_max)
				{
						//创建线程时使用tids数组,如果对应位为0,直接使用,如果对应位>0,测试该线程是否存活,存活忽略使用,否则覆盖
						for(i=0,add=0;i<pool->thread_max,add<pool->thread_min,pool->thread_alive < pool->thread_max;i++){
								if(pool->tids[i]==0 || !if_test_threadalive(pool->tids[i])){
										pthread_create(&pool->tids[i],NULL,Thread_Custom_Job,(void*)pool);
										++add;

										pthread_mutex_lock(&pool->lock);
										++pool->thread_alive;
										pthread_mutex_unlock(&pool->lock);
								}
						}
				}
				//缩减线程
				if(busy * 2 < (alive - busy && pool->thread_alive > pool->thread_min)){
						//修改回收数
						pthread_mutex_lock(&pool->lock);
						pool->thread_wait = pool->thread_min;
						pthread_mutex_unlock(&pool->lock);
						for(int i=0;i<pool->thread_min,pool->thread_alive > pool->thread_min;i++)
								pthread_cond_signal(&pool->not_empty);
				}
				sleep(TIMEOUT);
		}
		pthread_exit(NULL);
}
