#include <stdio.h>
#include <assert.h>
#include <libtpool/tpool.h>
#include <unistd.h>

typedef struct {
	int start;
	int end;
} args_t;

void*
hello(void* args)
{
	args_t args_hello = *((args_t*) args);
	int start = args_hello.start,
		end = args_hello.end;
	for(int i = start; i<end; i++);
	printf("Done -> %d to %d\n", start, end);
}

void
test()
{
	printf("\n!!--CRUD Test--!!\n");

	printf("Thread Pool Initialization...");
	tpool_t p;
	tpool_new(&p, 2);
	assert(p.size == 2);
	assert(p.threads != NULL);
	printf("OK ✅\n");

	printf("Thread Pool Push...\n");
	args_t args1 = {13, 304309},
			args2 = {3453, 4459482},
			args3 = {0, 348398249};
	tpool_push(&p, hello, &args1);
	tpool_push(&p, hello, &args2);
	tpool_push(&p, hello, &args3);
	sleep(1);
	printf("OK ✅\n");

	printf("Thread Pool Free...");
	tpool_finish(&p);
	printf("OK ✅\n");
}

int
main()
{
	test();
	return 0;
}