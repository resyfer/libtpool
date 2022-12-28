#include "tpool.h"

#ifndef __LIBTPOOL_TASK_H
#define __LIBTPOOL_TASK_H

struct task {
	void* (*routine) (void*);
	void* args;
};

void *task_worker(void *args);

#endif