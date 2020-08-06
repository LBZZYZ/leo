
#include <pool.h>


int if_test_threadalive(pthread_t tid)
{
	if((pthread_kill(tid,0))==-1)
		if(errno == ESRCH)
			return FALSE;
	return TRUE;
}
