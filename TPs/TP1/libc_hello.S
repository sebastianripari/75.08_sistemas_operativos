#include <sys/syscall.h>  // SYS_write, SYS_exit

.globl main
main:
	push $msg
	call puts

	push $1
	push $2
	call sumador

sumador:
	mov %esp, %ebx
	add %esp, 4
	mov %esp, %ecx
	ret

.data
msg:
	.ascii "Hello, world!\n"

.set len, . - msg