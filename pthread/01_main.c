#include <pthread.h>
#include <stdio.h>

#define ERROR -1

typedef struct _args_t {
	char* nombre;
	char* apellido;
} args_t;

void* saludador(void* args) {
	printf("Hola:\n");
	printf("Nombre: %s\n", ((args_t*) (args))->nombre);
	printf("Apellido: %s\n", ((args_t*) (args))->apellido);
}

int main() {
	pthread_t thread;

	args_t args;

	args.nombre = "Sebastian";
	args.apellido = "Ripari"; 

	if(pthread_create(&thread, NULL, saludador, &args)) return ERROR;
	if(pthread_join(thread, NULL)) return ERROR;

	return 0;
}