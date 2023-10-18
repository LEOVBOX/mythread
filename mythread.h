//
// Created by Леонид Шайхутдинов on 18.10.2023.
//

#ifndef INC_1_7_MYTHREAD_H
#define INC_1_7_MYTHREAD_H

#include <stdio.h>
#include <sys/types.h>
#include <memory.h>
#include <sys/mman.h>
#include <sys/fcntl.h>
#include <unistd.h>

//           Pointer on function
typedef void *(*start_routine_t)(void*);

typedef struct _mythread{
	int mythread_id;
	start_routine_t start_routine;
	void* arg;
	void* retval;
	volatile int joined;
	volatile int exited;
} mythread_struct_t;

typedef mythread_struct_t* mythread_t;

void* create_stack(off_t size, int tread_num);
int mythread_startup(void* arg);
int mythread_create(mythread_t *mytid, start_routine_t start_routine, void *arg);
int mythread_join(mythread_t mytid, void** retval);

/* TODO close()
	TODO mythread_join()
 */

#endif //INC_1_7_MYTHREAD_H
