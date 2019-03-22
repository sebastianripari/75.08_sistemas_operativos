static volatile char * const VGABUF = (volatile char *) 0xb8000;

void comienzo() {
    volatile char *buf = VGABUF;
    *buf++ = 79;
    *buf++ = 47;
    
    while(1) asm("hlt");
}
