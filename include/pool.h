#ifndef __LIBTPOOL_POOL_H
#define __LIBTPOOL_POOL_H

typedef struct {
	u_int8_t size;
	pthread_t *threads;
	queue_t *queue;
	pthread_mutex_t *tpool_lock;
	sem_t full;
} tpool_t;

#endif