//
// Created by Леонид Шайхутдинов on 18.10.2023.
//

#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <stdio.h>
#include <sys/types.h>
#include <memory.h>
#include <sys/mman.h>
#include <sys/fcntl.h>
#include <unistd.h>
#include <ucontext.h>

//           Pointer on function
typedef void *(*start_routine_t)(void*);

typedef struct _mythread{
	int mythread_id;
	start_routine_t start_routine;
	void* arg;
	void* retval;
	volatile int joined;
	volatile int exited;

	ucontext_t before_start_routine;
	volatile int canceled;
} mythread_struct_t;

typedef mythread_struct_t* mythread_t;

int mythread_startup(void* arg);
int mythread_create(mythread_t *mytid, start_routine_t start_routine, void *arg);
int mythread_join(mythread_t mytid, void** retval);
void mythread_cancel(mythread_t mytid);
void mythread_testcancel();

/* TODO close()
	TODO mythread_join()
 */

#endif //MYTHREAD_H
