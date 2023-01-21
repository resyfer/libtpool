/* libc */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

/* Personal libraries */
#include <libqueue/queue.h>

/* Header files */
#include <include/task.h>
#include <include/tpool.h>
#include <include/tqueue.h>
#include <include/util.h>

extern void *task_worker(void *args);

void
tpool_new(tpool_t* pool, u_int8_t size)
{
	pool->size = size;
	pool->threads = malloc(size * sizeof(pthread_t));

	queue_new(&pool->queue);

	pool->tpool_lock = malloc(sizeof(pthread_mutex_t));

	// pool->empty = malloc(sizeof(sem_t));
	// Not needed as sem_init has 0 for pshared, which ensures its visible by all threads

	if (sem_init(&pool->empty, 0, 0)) {
		error("Error Initializing Semaphore");
	}

	if (pthread_mutex_init(pool->tpool_lock, NULL)) {
		error("Error Initializing Mutex");
	}

	pthread_mutex_lock(pool->tpool_lock);
	for(u_int8_t i = 0; i<size; i++) {
		pthread_create(&pool->threads[i], NULL, task_worker, (void *) pool);
	}
	pthread_mutex_unlock(pool->tpool_lock);
}

/**
 * @brief A dummy function that, if any thread executes, stops
 * 		  the execution of the thread and destroys it.
 */
void*
tpool_stop(void* args)
{
	// Meant to be left empty
}

void
tpool_finish(tpool_t *pool)
{
	for(u_int8_t i = 0; i<pool->size; i++) {
		tpool_push(pool, tpool_stop, NULL);
	}

	for(u_int8_t i = 0; i<pool->size; i++) {
		pthread_join(pool->threads[i], NULL);
	}

	free(pool->threads);
	free(pool->tpool_lock);
	queue_free(&pool->queue);
}