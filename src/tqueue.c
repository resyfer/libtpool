#include <stdlib.h>
#include <stdio.h>

#include <include/tqueue.h>

void
tpool_push(tpool_t *pool, routine_t routine, void *args)
{
	task_t *new_task = malloc(sizeof(task_t));
	new_task->routine = routine;
	new_task->args = args;

	pthread_mutex_lock(pool->tpool_lock);
	queue_push(&pool->queue, (void*) new_task);
	sem_post(&pool->empty);

	pthread_mutex_unlock(pool->tpool_lock);
}

/**
 * @brief Choosing a task from the thread pool.
 *
 * @param pool Thread pool instance
 * @return task_t* Task
 */
task_t*
tpool_pop(tpool_t *pool)
{
	// Waiting for atleast one task to be there
	sem_wait(&pool->empty);

	task_t *popped_task;

	pthread_mutex_lock(pool->tpool_lock);
	popped_task = queue_pop(&pool->queue);
	pthread_mutex_unlock(pool->tpool_lock);

	return popped_task;
}