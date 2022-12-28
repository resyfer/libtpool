#include <libqueue/libqueue.h>

#include "task.h"
#include "tpool.h"

#ifndef __LIBTPOOL_TQUEUE_H
#define __LIBTPOOL_TQUEUE_H

void tpool_push(struct tpool *pool,void* (*routine) (void*), void *args);
struct task* tpool_pop(struct tpool *pool);

#endif