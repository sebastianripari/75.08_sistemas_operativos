#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

void backtrace() {
	
	void* frame_address;
	int numfrm;

	frame_address = __builtin_frame_address(0);
	numfrm = 0;

	printf(
		"#%d [%p] ADDR ( %p %p %p )\n",
		numfrm,
		frame_address,
		*((int*)(frame_address + 8)),
		frame_address + 12,
		*((int*)(frame_address + 16)) );

	frame_address = __builtin_frame_address(1);
	numfrm = 1;

	printf(
		"#%d [%p] ADDR ( %p %p %p )\n",
		numfrm,
		frame_address,
		*((int*)(frame_address + 8)),
		frame_address + 12,
		*((int*)(frame_address + 16)) );

	frame_address = __builtin_frame_address(2);
	numfrm = 2;

	printf(
		"#%d [%p] ADDR ( %p %p %p )\n",
		numfrm,
		frame_address,
		*((int*)(frame_address + 8)),
		frame_address + 12,
		*((int*)(frame_address + 16)) );

	frame_address = __builtin_frame_address(3);
	numfrm = 3;

	printf(
		"#%d [%p] ADDR ( %p %p %p )\n",
		numfrm,
		frame_address,
		*((int*)(frame_address + 8)),
		frame_address + 12,
		*((int*)(frame_address + 16)) );

	frame_address = __builtin_frame_address(4);
	numfrm = 4;

	printf(
		"#%d [%p] ADDR ( %p %p %p )\n",
		numfrm,
		frame_address,
		*((int*)(frame_address + 8)),
		frame_address + 12,
		*((int*)(frame_address + 16)) );

	frame_address = __builtin_frame_address(5);
	numfrm = 5;

	printf(
		"#%d [%p] ADDR ( %p %p %p )\n",
		numfrm,
		frame_address,
		*((int*)(frame_address + 8)),
		frame_address + 12,
		*((int*)(frame_address + 16)) );

	frame_address = __builtin_frame_address(6);
	numfrm = 6;

	printf(
		"#%d [%p] ADDR ( %p %p %p )\n",
		numfrm,
		frame_address,
		*((int*)(frame_address + 8)),
		frame_address + 12,
		*((int*)(frame_address + 16)) );

	frame_address = __builtin_frame_address(7);
	numfrm = 7;

	printf(
		"#%d [%p] ADDR ( %p %p %p )\n",
		numfrm,
		frame_address,
		*((int*)(frame_address + 8)),
		frame_address + 12,
		*((int*)(frame_address + 16)) );

	frame_address = __builtin_frame_address(8);
	numfrm = 8;

	printf(
		"#%d [%p] ADDR ( %p %p %p )\n",
		numfrm,
		frame_address,
		*((int*)(frame_address + 8)),
		frame_address + 12,
		*((int*)(frame_address + 16)) );

	frame_address = __builtin_frame_address(9);
	numfrm = 9;

	printf(
		"#%d [%p] ADDR ( %p %p %p )\n\n",
		numfrm,
		frame_address,
		*((int*)(frame_address + 8)),
		frame_address + 12,
		*((int*)(frame_address + 16)) );
}

void my_write(int fd, const void *msg, size_t count) {
    backtrace();
    fprintf(stderr, "=> write(%d, %p, %zu)\n", fd, msg, count);
    write(fd, msg, count);
}

void recurse(int level) {
    if (level > 0)
        recurse(level - 1);
    else
        my_write(2, "Hello, world!\n", 15);
}

void start_call_tree() {
    recurse(5);
}

int main(void) {
    start_call_tree();
}