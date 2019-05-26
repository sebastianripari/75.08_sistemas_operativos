#include <stdio.h> 
#include <sys/types.h> 
#include <sys/wait.h>
#include <unistd.h>

void foo() {
	int x = 0;
	int pid = fork();
	x = 1;
	if (pid == 0) { //hijo
		x = 2;
	} else { // padre
		x = 3;
	}
	printf("x = %d\n", x);
}

int main() {
	foo();
	printf("Finaliza un proceso\n");
}