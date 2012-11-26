#include "cma.h"
//pretty much copied from ma.c since I don't see a better way to do it.
#define MSIZE 1024*16
unsigned char mem[MSIZE];

int main(int argc, char * argv[]) {
	int i;
	char *strings[20];
	class_memory(mem,MSIZE); // give it memory allocator

	for (i = 0; i<20; i++)
		strings[i] = (char *)class_malloc(1024); //allocate from classmem library
	for (i = 19; i>=0; i--) 
		class_free(strings[i]);
	class_stats();
}
