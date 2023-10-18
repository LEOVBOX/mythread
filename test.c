#include "mythread.h"

void* mythread_func(void* arg)
{
    printf("hello from child! pid = %d, ppid = %d, tid = %d\n", getpid(), getppid(), gettid());
	sleep(1);
    return "goodbye";
}

int main() 
{
    mythread_t mytid;
    void *retval;
    int err;

    printf("hello from main! pid = %d, ppid = %d ,tid = %d\n", getpid(), getppid(), gettid());
	
    err = mythread_create(&mytid, mythread_func, retval);
    if(err != 0)
    {
        printf("thread create error\n");
        return -1;
    }

    mythread_join(mytid, &retval);
    
    return 0;
}