#include <stdio.h> 
#include <sys/types.h> 
#include <sys/wait.h>
#include <unistd.h>

void foo() {
	int x = 0;
	int pid = fork();
	x = 42;
	if (pid == 0) {
		x = 10;
	} else {
		waitpid(pid, 0, 0);
	}
	printf("x = %d\n", x);
}

int main() {
	foo();
	printf("Finaliza un proceso\n");
}