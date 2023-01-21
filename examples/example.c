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
	tpool_t pool;
	tpool_new(&pool, 4);

	int n;
	scanf("%d", &n);

	for(int i = 0; i<n; i++) {
		int *j = malloc(sizeof(int));
		*j = i;
		tpool_push(&pool, hello, (void*) j);
	}

	tpool_finish(&pool);
	return 0;
}