#include <stdio.h> 
#include <sys/types.h> 
#include <sys/wait.h>
#include <unistd.h>

void foo() {
    int pid = fork();
   
    if (pid == 0) {
        // hijo
        printf("pid = %d\n", pid);
    } else {
        // padre
        waitpid(pid, 0, 0);
        printf("pid = %d\n", pid);
    }
}

int main() {
    foo();
    printf("Finaliza un proceso\n");
}