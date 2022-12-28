#include <stdlib.h>
#include <stdio.h>

#include <include/tqueue.h>

void
tpool_push(struct tpool *pool,void* (*routine) (void*), void *args)
{
	struct task *new_task = malloc(sizeof(struct task));
	new_task->routine = routine;
	new_task->args = args;

	pthread_mutex_lock(pool->tpool_lock);
	queue_push(pool->queue, (void*) new_task);
	sem_post(&pool->full);
	pthread_mutex_unlock(pool->tpool_lock);
}

struct task*
tpool_pop(struct tpool *pool)
{
	sem_wait(&pool->full);

	struct task *popped_task;

	pthread_mutex_lock(pool->tpool_lock);
	popped_task = queue_pop(pool->queue);
	pthread_mutex_unlock(pool->tpool_lock);

	return popped_task;
}