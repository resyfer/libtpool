#ifndef __LIBTPOOL_TQUEUE_H
#define __LIBTPOOL_TQUEUE_H

#include <libqueue/queue.h>

#include "task.h"
#include "pool.h"

typedef void* (*routine_t) (void*);

void tpool_push(tpool_t *pool, routine_t routine, void *args);
task_t* tpool_pop(tpool_t *pool);

#endif