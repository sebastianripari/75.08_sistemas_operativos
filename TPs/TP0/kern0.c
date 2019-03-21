#define VGABUF ((volatile char *) 0xb8000)

#include "c99int.h"


static void
vga_write(const char *s, int8_t linea, uint8_t color) {
	volatile char *buf = VGABUF;
	uint8_t size_line = 160;
	buf += size_line * linea;
	for(int8_t i = 0; i < sizeof(s); ++i) {
		*buf++ = (uint8_t) s[i];
		*buf++ = color;	
	}
}

void comienzo(void) {
	char s[] = "hola";
    vga_write(s, 4, 47);

    while (1)
        asm("hlt");
}