#define VGABUF ((volatile char *) 0xb8000)

#include "c99int.h"

static void
vga_write(const char *s, int8_t linea, uint8_t color) {
	volatile char *buf = VGABUF;
	int cantidad_caracteres_linea = 160;
	int cantidad_lineas = 24;

	if(linea >= 0) 
		buf += cantidad_caracteres_linea * linea;
	else
		buf += cantidad_caracteres_linea * (cantidad_lineas + linea); 

	while(*s != 0){
		*buf++ = *s++;
		*buf++ = color;
	}
	
}

void comienzo(void) {

    vga_write("OK\0", 0, 47);
    vga_write("HOLA\0", 1, 224);

    while(1) asm("hlt");
}