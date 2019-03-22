
kern0:     file format elf32-i386


Disassembly of section .text:

00100000 <multiboot>:
  100000:	02 b0 ad 1b 00 00    	add    0x1bad(%eax),%dh
  100006:	00 00                	add    %al,(%eax)
  100008:	fe 4f 52             	decb   0x52(%edi)
  10000b:	e4                   	.byte 0xe4

0010000c <vga_write>:
#define VGABUF ((volatile char *) 0xb8000)

#include <stdint.h>

static void
vga_write(const char *s, int8_t linea, uint8_t color) {
  10000c:	56                   	push   %esi
  10000d:	53                   	push   %ebx
  10000e:	89 ce                	mov    %ecx,%esi
	volatile char *buf = VGABUF;
	int cantidad_caracteres_linea = 160;
	int cantidad_lineas = 24;

	if(linea >= 0) 
  100010:	84 d2                	test   %dl,%dl
  100012:	78 2d                	js     100041 <vga_write+0x35>
		buf += cantidad_caracteres_linea * linea;
  100014:	0f be d2             	movsbl %dl,%edx
  100017:	69 d2 a0 00 00 00    	imul   $0xa0,%edx,%edx
  10001d:	81 c2 00 80 0b 00    	add    $0xb8000,%edx
vga_write(const char *s, int8_t linea, uint8_t color) {
  100023:	bb 00 00 00 00       	mov    $0x0,%ebx
	else
		buf += cantidad_caracteres_linea * (cantidad_lineas + linea); 


	for(int i = 0; i < sizeof(s); ++i) {
		*buf++ = (int) s[i];
  100028:	0f b6 0c 18          	movzbl (%eax,%ebx,1),%ecx
  10002c:	88 0a                	mov    %cl,(%edx)
		*buf++ = color;	
  10002e:	89 f1                	mov    %esi,%ecx
  100030:	88 4a 01             	mov    %cl,0x1(%edx)
	for(int i = 0; i < sizeof(s); ++i) {
  100033:	83 c3 01             	add    $0x1,%ebx
		*buf++ = color;	
  100036:	8d 52 02             	lea    0x2(%edx),%edx
	for(int i = 0; i < sizeof(s); ++i) {
  100039:	83 fb 04             	cmp    $0x4,%ebx
  10003c:	75 ea                	jne    100028 <vga_write+0x1c>
	}
}
  10003e:	5b                   	pop    %ebx
  10003f:	5e                   	pop    %esi
  100040:	c3                   	ret    
		buf += cantidad_caracteres_linea * (cantidad_lineas + linea); 
  100041:	0f be d2             	movsbl %dl,%edx
  100044:	83 c2 18             	add    $0x18,%edx
  100047:	69 d2 a0 00 00 00    	imul   $0xa0,%edx,%edx
  10004d:	81 c2 00 80 0b 00    	add    $0xb8000,%edx
  100053:	eb ce                	jmp    100023 <vga_write+0x17>

00100055 <comienzo>:

void comienzo(void) {
  100055:	53                   	push   %ebx
  100056:	e8 33 00 00 00       	call   10008e <__x86.get_pc_thunk.bx>
  10005b:	81 c3 a5 1f 00 00    	add    $0x1fa5,%ebx

    vga_write("OK\0", 0, 47);
  100061:	b9 2f 00 00 00       	mov    $0x2f,%ecx
  100066:	ba 00 00 00 00       	mov    $0x0,%edx
  10006b:	8d 83 92 e0 ff ff    	lea    -0x1f6e(%ebx),%eax
  100071:	e8 96 ff ff ff       	call   10000c <vga_write>
    vga_write("HOLA\0", 1, 224);
  100076:	b9 e0 00 00 00       	mov    $0xe0,%ecx
  10007b:	ba 01 00 00 00       	mov    $0x1,%edx
  100080:	8d 83 96 e0 ff ff    	lea    -0x1f6a(%ebx),%eax
  100086:	e8 81 ff ff ff       	call   10000c <vga_write>

    while(1) asm("hlt");
  10008b:	f4                   	hlt    
  10008c:	eb fd                	jmp    10008b <comienzo+0x36>

0010008e <__x86.get_pc_thunk.bx>:
  10008e:	8b 1c 24             	mov    (%esp),%ebx
  100091:	c3                   	ret    
