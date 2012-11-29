//This file created by Daniel Hanlen for purposes of CptS224 Git Lab
// Template of ma.c was used in this file's creation
#include "cma.h"

#define ARRAYNUM 20 // number of arrays of doubles we will have
#define ARRAYSIZE 1024 // size of one array in memory
#define MSIZE ARRAYSIZE*ARRAYNUM // how much memory is needed
unsigned char mymemory[MSIZE];

int main(int argc, char * argv[])
{
	int i;
	double *arrays[ARRAYNUM];
	class_memory(mymemory,MSIZE); // give it memory allocator

	for (i = 0; i<ARRAYNUM; i++)
		arrays[i] = (double *)class_malloc(ARRAYSIZE); //allocate from classmem library
	for (i = 0; i<ARRAYNUM; i++)
		arrays[i][0] = i;
	for (i = 0; i<ARRAYNUM; i++)
		printf("%0.2d",arrays[i][0]);//print out the first element
	for (i = ARRAYNUM-1; i>=0; i--) 
		class_free(arrays[i]);
	class_stats();
	return 0;
}

