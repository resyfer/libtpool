/**
 * @file tpool.h
 * @brief This is the entry header for the library.
 *
 * @author Saurav Pal (resyfer)
 * @bug No known bugs
 */

#ifndef __LIBTPOOL_TPOOL_H
#define __LIBTPOOL_TPOOL_H 1

/**
 * @mainpage
 * This thread pool library creates a pool of threads for executing various tasks.
 * Since creation and detruction of a thread is costly, the thread pool creates
 * some amounts of threads on initialization, and runs tasks on them.
 *
 * As soon as a thread finishes executing a task, it takes the next waiting
 * task and begins executing it. This increases efficiency, as it is both better
 * than creating separate processes, as well as creating a thread for each
 * task and managing it's completion yourself.
*/

/* Header files */
#include "pool.h"
#include "task.h"
#include "global.h"
#include "tqueue.h"
#include "util.h"

/**
 * @brief Initialize a thread pool library
 *
 * @param pool Thread pool instance to initialize
 * @param size Number of threads the thread pool instance will have
 */
void tpool_new(tpool_t* pool, u_int8_t size);

/**
 * @brief Finish the thread pool execution.
 *
 * Once this is executed, the thread pool stops accepting tasks,
 * completes all of the waiting tasks, and then cleans up all of
 * the memory that it assigned internally for executions including
 * destroying all of the threads in the thread pool.
 *
 * @param pool Thread pool instance.
 */
void tpool_finish(tpool_t *pool);

#endif