#include "../mythread_internal.h"

void* create_stack(off_t size, int thread_num)
{
	int stack_fd;
	void *stack;
	char stack_file[128];

	snprintf(stack_file, sizeof(stack_file), "stack-%d", thread_num);
	

	// 0660 mode - only owner and owners group can read and write.
	stack_fd = open(stack_file, O_RDWR | O_CREAT, 0660);

	// Change stack file size
	ftruncate(stack_fd, size);


	stack = mmap(NULL, size, PROT_NONE, MAP_SHARED, stack_fd, 0);
	close(stack_fd);

	// Filling stack with 0x7f
	//memset(stack, 0x7f, size);

	return stack;
}