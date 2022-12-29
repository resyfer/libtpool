#include <include/tqueue.h>

void *
task_worker(void *args)
{
	tpool_t *pool = args;

	while(1) {
		task_t *popped_task = tpool_pop(pool);

		if(popped_task->routine == tpool_stop) {
			break;
		}

		popped_task->routine(popped_task->args);
	}
}