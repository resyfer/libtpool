#ifndef __LIBTPOOL_TASK_H
#define __LIBTPOOL_TASK_H

#include "tpool.h"

typedef struct {
	void* (*routine) (void*);
	void* args;
} task_t;

void *task_worker(void *args);

#endif