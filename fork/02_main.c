#include <stdio.h> 
#include <sys/types.h> 
#include <sys/wait.h>
#include <unistd.h>

void foo() {
    int x = 0;
    int pid = fork();
    // a partir de aqui comienza la ramificacion de la ejecucion
    // el proceso child (creado) tiene pid 0
    x = 1;
    if (pid == 0) { //hijo
        x = 2;
    } else { // padre
        // espera que el hijo termine de ejecutarse
        waitpid(pid, 0, 0);
        x = 3;
    }
    printf("x = %d\n", x);
}

int main() {
    foo();
    printf("Finaliza un proceso\n");
}