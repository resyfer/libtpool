# libtpool

A C library for a thread pool. Pretty easy to use. For instructions on usage, please go [here](#usage).

For installation, please go [here](#installation). For documentation, please go [here](#documentation).

## Usage

### TL;DR

The shown below is a tl;dr version. Proper instructions are [here](#step-1)

```c
#include <libtpool/libtpool.h>
#include <stdio.h>

void* hello(void *args) {
	printf("%d\n", pthread_self());
}

int main() {
	struct tpool *pool = tpool_new(4);

	int n;
	scanf("%d", &n);

	for(int i = 0; i<n; i++) {
		tpool_push(pool, hello, NULL);
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
#include <libtpool/libtpool.h>
```

**NOTE**: Link the library and dependencies when compiling

```bash
$ gcc a.c -o a.o -ltpool -lpthread -lqueue
```

### Step 2

Create a dummy function to execute:

```c
// Dummy function of type `void* fun(void* args)`
void* hello(void* args) {
  printf("%d\n", pthread_self());
  // This just prints the ID of the thread
  // it is running in within the thread pool
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
struct tpool* tpool_new(u_int8_t size);
```

### Push Tasks to Thread Pool

```c
void tpool_push(struct tpool *pool,void* (*routine) (void*), void *args);
```

### Finish Thread Pool

```c
void tpool_finish(struct tpool *pool);
```
