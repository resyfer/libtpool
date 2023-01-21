/**
 * @file tqueue.h
 * @brief This header file contains the various functionality of the
 * 		  queue-wrapper that the thread pool uses for queueing up
 * 		  waiting tasks and well as choosing a task for execution.
 *
 * @author Saurav Pal (resyfer)
 * @bug No known bugs
 */

#ifndef __LIBTPOOL_TQUEUE_H
#define __LIBTPOOL_TQUEUE_H 1

/* Personal Libraries */
#include <libqueue/queue.h>

/* Header files */
#include "task.h"
#include "pool.h"

/**
 * @brief Type of a routine, ie. a task, which is
 * pushed to the thread pool for execution.
 */
typedef void* (*routine_t) (void*);

/**
 * @brief Push a routine, ie. task,  to the thread pool
 * 		  for execution.
 *
 * @param pool Thread pool instance
 * @param routine Task
 * @param args Arguments for the task
 */
void tpool_push(tpool_t *pool, routine_t routine, void *args);

#endif