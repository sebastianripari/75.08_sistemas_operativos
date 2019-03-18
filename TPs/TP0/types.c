#if defined(__x86_64__)
// 64 bit detected
typedef char int8_t;
typedef unsigned char uint8_t;
typedef short int16_t;
typedef unsigned short uint16_t;
typedef int int32_t;
typedef unsigned int uint32_t;
typedef long int64_t;
typedef unsigned long uint64_t;
#endif

#if defined(__i386__)
// 32 bit x86 detected 
#endif

#include <stdio.h>

int main() {
	printf("int8_t = %li\n", sizeof(int8_t) * 8);
	printf("uint8_t = %li\n", sizeof(uint8_t) * 8);
	printf("int16_t = %li\n", sizeof(int16_t) * 8);
	printf("uint16_t = %li\n", sizeof(uint16_t) * 8);
	printf("int32_t = %li\n", sizeof(int32_t) * 8);
	printf("uint32_t = %li\n", sizeof(uint32_t) * 8);
	printf("int64_t = %li\n", sizeof(int64_t) * 8);
	printf("uint64_t = %li\n", sizeof(uint64_t) * 8);
	return 0;
}