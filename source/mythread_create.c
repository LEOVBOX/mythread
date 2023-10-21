//
// Created by Леонид Шайхутдинов on 18.10.2023.
//


#define _GNU_SOURCE
#include "../mythread.h"
#include <sched.h>


#define PAGE 4096
#define STACK_SIZE PAGE*4


int mythread_create(mythread_t *mytid, start_routine_t start_routine, void *arg)
{
	static int thread_num = 0;

	mythread_struct_t *thread;

	thread_num++;

	printf("mythread_create: creating thread %d\n", thread_num);

	void* child_stack = create_stack(STACK_SIZE, thread_num);
	mprotect(child_stack + PAGE, STACK_SIZE - PAGE, PROT_READ|PROT_WRITE);

	memset(child_stack + PAGE, 0x7f, STACK_SIZE - PAGE);

	thread = (mythread_struct_t*)(child_stack + STACK_SIZE - sizeof(mythread_struct_t));
	thread->mythread_id = thread_num;
	thread->start_routine = start_routine;
	thread->arg = arg;
	thread->retval = NULL;
	thread->exited = 0;
	thread->joined = 0;

	child_stack = (void*)thread;

	printf("child stack %p; mythread_struct %p; \n", child_stack, thread);

	int child_pid = clone(mythread_startup, child_stack, CLONE_VM | CLONE_FILES | CLONE_THREAD | CLONE_SIGHAND, thread);
	if (child_pid == -1)
	{
		return -1;
	}
	*mytid = thread;

	return 0;
}