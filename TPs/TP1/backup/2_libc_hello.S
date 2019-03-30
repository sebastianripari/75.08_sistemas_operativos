.globl main
main:
	push $msg
	call strlen

	push %eax
	push $msg
	push $1

	push $posicion_retorno
	jmp write

posicion_retorno:
	push $7
	call _exit

.data
msg:
	.ascii "Hello, world!\n"
