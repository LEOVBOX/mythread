

#ifndef MYTHREAD_INTERNAL_H
#define MYTHREAD_INTERNAL_H

#include "mythread.h"

int thread_startup(void* arg);
void* create_stack(off_t size, int thread_num);

#endif //MYTHREAD_INTERNAL_H

