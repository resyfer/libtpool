#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <libqueue/libqueue.h>

#include <include/tpool.h>
#include <include/task.h>
#include <include/tqueue.h>

struct tpool*
tpool_new(u_int8_t size)
{
	struct tpool *new_pool = malloc(sizeof(struct tpool));
	new_pool->size = size;
	new_pool->threads = malloc(size * sizeof(pthread_t));
	new_pool->queue = queue_new();
	new_pool->tpool_lock = malloc(sizeof(pthread_mutex_t));

	// new_pool->full = malloc(sizeof(sem_t));
	// Not needed as sem_init has 0 for pshared, which ensures its visible by all threads

	if (sem_init(&new_pool->full, 0, 0)) {
		printf("\nError Initializing Semaphore\n");
		exit(1);
	}

	if (pthread_mutex_init(new_pool->tpool_lock, NULL)) {
		printf("\nError Initializing Mutex\n");
		exit(1);
	}

	pthread_mutex_lock(new_pool->tpool_lock);
	for(u_int8_t i = 0; i<size; i++) {
		pthread_create(&new_pool->threads[i], NULL, task_worker, (void *) new_pool);
	}
	pthread_mutex_unlock(new_pool->tpool_lock);

	return new_pool;
}

void*
tpool_stop(void* args)
{
	// Meant to be left empty
}

void
tpool_finish(struct tpool *pool)
{
	for(u_int8_t i = 0; i<pool->size; i++) {
		tpool_push(pool, tpool_stop, NULL);
	}

	for(u_int8_t i = 0; i<pool->size; i++) {
		pthread_join(pool->threads[i], NULL);
	}
}