# libtpool

A C library for a thread pool. Pretty easy to use. For instructions on usage, please go [here](#usage).

For installation, please go [here](#installation). For documentation, please go [here](#documentation).

## Usage

### TL;DR

The shown below is a tl;dr version. Proper instructions are [here](#step-1)

```c
#include <libtpool/tpool.h>
#include <stdio.h>
#include <stdlib.h>

void* hello(void *args) {
	int *k = args;
	int i;
	for(i = 0; i<100000; i++);
	printf("%d %d\n", *k, i);
	free(k);
	return NULL;
}

int main() {
	tpool_t *pool = tpool_new(4);

	int n;
	scanf("%d", &n);

	for(int i = 0; i<n; i++) {
		int *j = malloc(sizeof(int));
		*j = i;
		tpool_push(pool, hello, (void*) j);
	}

	tpool_finish(pool);
	return 0;
}
```

Compile and run:

```bash
$ gcc test.c -o test.o -lfetch -lcol -lhmap
$ ./test.o
```

### Step 1

Import the library:

```c
#include <libtpool/tpool.h>
```

**NOTE**: Link the library and dependencies when compiling

```bash
$ gcc a.c -o a.o -ltpool -lpthread -lqueue
```

### Step 2

Create a computationaly heavy dummy function of type `routine_t` to execute:

```c
// Dummy function of type `void* fun(void* args)`
void* hello(void *args) {
	int *k = args;
	int i;
	for(i = 0; i<100000; i++);
	printf("%d %d\n", *k, i);
	free(k);
	return NULL;
}
```

### Step 3

Push tasks (functions) to queue for being executed:

```c
tpool_push(pool, hello, NULL);
```

You can use a for loop to emulate multiple execution requests.

### Step 4

Finish the thread pool (important step for all pending tasks to get over before exiting main):

```c
tpool_finish(pool);
```

## Installation

Make sure to have [make](https://www.gnu.org/software/make/), [gcc](https://www.gnu.org/software/gcc/) and [git](https://git-scm.com/) installed.

Install all the the dependencies before moving on the next step (preferably in the same order as given below):

- [libqueue](https://github.com/resyfer/libqueue.git)

**NOTE**: Their installation instructions will be provided in their documentation as well.

After installing dependencies, installation of library:

```bash
git clone https://github.com/resyfer/libtpool.git
cd libtpool
make install
cd ..
rm -rf libtpool
```

Provide the password when prompted.

## Documentation

### Intialization

```c
tpool_t* tpool_new(u_int8_t size);
```

### Push Tasks to Thread Pool

```c
void tpool_push(tpool_t *pool, routine_t routine, void *args);
```

`routine_t` is of type:
```c
typedef void* (*routine_t) (void*);
// ie. a function which looks like:
// void* hello(void* args) {
//
// }
```

### Finish Thread Pool

```c
void tpool_finish(tpool_t *pool);
```
