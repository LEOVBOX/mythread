libmythread.a: create_stack.o mythread_create.o thread_startup.o mythread_join.o
	ar r ../libmythread.a create_stack.o mythread_create.o thread_startup.o mythread_join.o

create_stack.o: create_stack.c
	gcc -c create_stack.c -o create_stack.o

mythread_create.o: mythread_create.c 
	gcc -c mythread_create.c -o mythread_create.o

thread_startup.o: thread_startup.c
	gcc -c thread_startup.c -o thread_startup.o

mythread_join.o: mythread_join.c
	gcc -c mythread_join.c -o mythread_join.o

clean:
	rm *.o
