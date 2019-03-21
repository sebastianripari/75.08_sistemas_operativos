#define VGABUF ((volatile char *) 0xb8000)

#include "c99int.h"

static void
vga_write(const char *s, int8_t linea, uint8_t color) {
	volatile char *buf = VGABUF;
	buf += 160*linea;
	
	*buf++ = 79;
	*buf++ = 47;
	*buf++ = 75;
	*buf++ = 47;
}

void comienzo(void) {
    
 
    const char s = "Hola";
    vga_write(&s, 4, 47);

    while (1)
        asm("hlt");
}