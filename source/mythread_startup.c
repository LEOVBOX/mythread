#include "mythread.h"

int mythread_startup(void* arg)
{
    mythread_t thread = (mythread_t)arg;

	void* retval;

	printf("mythread_startup: starting a thread func for the thread %d\n", thread->mythread_id);
    
    retval = thread->start_routine(thread->arg);

	thread->retval = retval;
    thread->exited = 1;

	printf("mythread_startup: waiting for join %d\n", thread->mythread_id);
    // wait until join
    while(thread->joined)
        sleep(1);

    printf("mythread_startup: thread func finished for the thread %d\n", thread->mythread_id);

    return 0;    
}