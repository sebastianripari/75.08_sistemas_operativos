#define VGABUF ((volatile char *) 0xb8000)

#include "c99int.h"

static void
vga_write(const char *s, int8_t linea, uint8_t color) {
	volatile char *buf = VGABUF;
	uint8_t cantidad_caracteres_linea = 160;
	uint8_t cantidad_lineas = 24;

	if(linea >= 0) 
		buf += cantidad_caracteres_linea * linea;
	else
		buf += cantidad_caracteres_linea * (cantidad_lineas + linea); 

	
	for(int8_t i = 0; i < sizeof(s); ++i) {
		*buf++ = (uint8_t) s[i];
		*buf++ = color;	
	}
}

void comienzo(void) {
	char s[] = "hola";
    vga_write(s, -3, 47);

    while(1) asm("hlt");
}