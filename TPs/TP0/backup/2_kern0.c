static volatile char * const VGABUF = (volatile char *) 0xb8000;

#include <stdint.h>

void comienzo() {
    volatile unsigned *p = VGABUF;

    /*
    79 -> 4F
    47 -> 2F
    75 -> 4B
    47 -> 2F
    */

    uint32_t i = 0x2F4B2F4F;

    *p = i;
    
    while(1) asm("hlt");
}
