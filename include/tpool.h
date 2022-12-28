#include <sys/types.h>
#include <pthread.h>
#include <libqueue/libqueue.h>
#include <semaphore.h>

#ifndef __LIBTPOOL_TPOOL_H
#define __LIBTPOOL_TPOOL_H

struct tpool {
	u_int8_t size;
	pthread_t *threads;
	struct queue *queue;
	pthread_mutex_t *tpool_lock;
	sem_t full;
};

struct tpool* tpool_new(u_int8_t size);
void tpool_finish(struct tpool *pool);
void* tpool_stop(void* args);

#endif