/**
 * @file task.h
 * @brief This contains all the elements required by a task.
 *
 * @author Saurav Pal (resyfer)
 * @bug No known bugs
 */

#ifndef __LIBTPOOL_TASK_H
#define __LIBTPOOL_TASK_H 1

/**
 * @brief A task, along with the routine, ie. the function, and
 * 		  the arguments.
 */
typedef struct {
	void* (*routine) (void*); /*!< Routine, ie. function,  of the task */
	void* args; /*!< Arguments of the routine */
} task_t;

#endif