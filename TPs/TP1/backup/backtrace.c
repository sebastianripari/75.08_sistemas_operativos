#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

void backtrace() {
	void* frame_address = __builtin_frame_address(0);
	int numfrm = 0;
	do {
		printf(
			"#%d [%p] ADDR ( %p %p %p )\n",
			numfrm++,
			*((int*)(frame_address + 4)),
			*((int*)(frame_address + 8)),
			*((int*)(frame_address + 12)),
			*((int*)(frame_address + 16)) );
	} while(frame_address = *((int*)frame_address));
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