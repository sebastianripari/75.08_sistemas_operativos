#define VGABUF ((volatile char *) 0xb8000)

#include <stdint.h>

static void
vga_write(const char *s, int8_t linea, uint8_t color) {
	volatile char *buf = VGABUF;
	int cantidad_caracteres_linea = 160;
	int cantidad_lineas = 24;

	if(linea >= 0) 
		buf += cantidad_caracteres_linea * linea;
	else
		buf += cantidad_caracteres_linea * (cantidad_lineas + linea); 


	for(int i = 0; i <= sizeof(s); ++i) {
		*buf++ = (int) s[i];
		*buf++ = color;	
	}
}

void comienzo(void) {

    vga_write("OK\0", 0, 47);
    

    while(1) asm("hlt");
}