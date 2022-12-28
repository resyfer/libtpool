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