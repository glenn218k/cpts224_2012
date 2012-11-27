#include "cma.h"

#define memsize 1024*100
unsigned char mem[memsize];

int main(int argc, char * argv[]) {
	int i;
	int *symb[130];
	class_memory(mem,memsize); // give it memory allocator

	for (i = 30; i<130; i++)
		symb[i] = (int *)class_malloc(1024); //allocate from classmem library
		
	for (i = 30; i<130; ++i)
			symb[i] = i;
			
	for (i = 30; i<130; ++i) 
		printf("%c", (int) symb[i]);
		
	for (i = 130; i>30; i--) 
		class_free(symb[i]);
	class_stats();
}
