/**
 * @file pool.h
 * @brief This contains all the elements of the thread pool.
 *
 * @author Saurav Pal (resyfer)
 * @bug No known bugs
 */

#ifndef __LIBTPOOL_POOL_H
#define __LIBTPOOL_POOL_H 1

#include <pthread.h>
#include <semaphore.h>
#include <libqueue/queue.h>

/**
 * @brief Thread pool instance
 */
typedef struct {
	u_int8_t size; /*!< Number of threads in the thread pool */
	pthread_t *threads; /*!< Array of threads */
	queue_t queue; /*!< Queue for the tasks */
	pthread_mutex_t *tpool_lock; /*!< Mutex for choosing a task */
	sem_t empty; /*!< Semaphore for tracking if queue for tasks is empty  */
} tpool_t;

#endif