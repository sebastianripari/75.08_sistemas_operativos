#include <sys/syscall.h>  // SYS_write, SYS_exit

.globl main
main:
	mov $SYS_write, %eax   // %eax == syscall number
	mov $1, %ebx           // %ebx == first argument (fd)
	mov $msg, %ecx         // %ecx == second argument (buf)
	mov $len, %edx         // %edx == third argument (count)
	int $0x80

	mov $1, %eax 
	ret

.data
msg:
        .ascii "Hello, world!\n"

.set len, . - msg