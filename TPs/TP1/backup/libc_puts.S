#include <sys/syscall.h>  // SYS_write, SYS_exit

.globl main
main:
	#### Prologo ####
	push %ebp
	mov %esp, %ebp 
	#################
	push $msg
	call puts

	mov $7, %eax 
	#### Epilogo ####
	movl %ebp, %esp
    popl %ebp
	#################
	ret

.data
msg:
    .ascii "Hello, world!"

.set len, . - msg