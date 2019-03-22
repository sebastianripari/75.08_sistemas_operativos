static volatile char * const VGABUF = (volatile char *) 0xb8000;

#include <stdint.h>

void comienzo() {
	/*
	H -> 48
	O -> 4F
	L -> 4C 
	A -> 41
	Little Endian (HOLA) = 41 4C 4F 48
	Con color: E0 41 E0 4C E0 4F E0 48 
	Finalmente: 0xE041E04CE04FE048
	*/
	volatile uint64_t *p = VGABUF;
	p += 160;
	uint64_t i = 0xE041E04CE04FE048;
	*p = i;

    while(1) asm("hlt");
}
