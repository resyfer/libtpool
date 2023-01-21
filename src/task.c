/* Header files */
#include <include/tqueue.h>
#include <include/tpool.h>

extern void* tpool_stop(void* args);
extern task_t* tpool_pop(tpool_t *pool);

/**
 * @brief It executes task as and when available
 *
 * @param args Arguments
 * @return void*
 */
void *
task_worker(void *args)
{
	tpool_t *pool = args;

	while(1) {
		task_t *popped_task = tpool_pop(pool);
		// Task is popped only when atleast one is available

		if(popped_task->routine == tpool_stop) {
			break;
		}

		popped_task->routine(popped_task->args);
	}
}