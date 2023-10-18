#include "mythread.h"

int mythread_join(mythread_t mytid, void** retval)
{
    mythread_t thread = mytid;

	printf("mythread_join: waiting for the thread %d to finish\n", thread->mythread_id);

    // wait until thread ends
    while (!thread->exited)
        usleep(1);
	
	printf("mythread_join: thread %d finished\n", thread->mythread_id);

    *retval = thread->retval;    
    thread->joined = 1;
    return 0;
}
