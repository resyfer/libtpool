#include <include/task.h>
#include <include/tqueue.h>
#include <stdio.h>

void *
task_worker(void *args)
{
	struct tpool *pool = args;

	while(1) {
		struct task *popped_task = tpool_pop(pool);

		if(popped_task->routine == tpool_stop) {
			break;
		}

		popped_task->routine(popped_task->args);
	}
}