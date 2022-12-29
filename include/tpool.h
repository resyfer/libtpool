#ifndef __LIBTPOOL_TPOOL_H
#define __LIBTPOOL_TPOOL_H

#include <sys/types.h>
#include <pthread.h>
#include <libqueue/queue.h>
#include <semaphore.h>

#include "tqueue.h"
#include "task.h"
#include "pool.h"
#include "global.h"

tpool_t* tpool_new(u_int8_t size);
void tpool_finish(tpool_t *pool);
void* tpool_stop(void* args);

#endif