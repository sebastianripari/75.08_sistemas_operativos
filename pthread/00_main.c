#include <pthread.h>
#include <stdio.h>

#define ERROR -1

void* increment_x(void* x) {

	int *counter = (int *) x;
	
	*counter = *counter + 1;

	return NULL;
}

int main() {
	int x = 0;

	pthread_t thread;

	if(pthread_create(&thread, NULL, increment_x, &x)) return ERROR;

	if(pthread_join(thread, NULL)) return ERROR;

	printf("x vale %d\n", x);

	return 0;
}