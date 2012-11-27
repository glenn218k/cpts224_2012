#include "cma.h"
#include <string.h>
#define SIZE1 256
#define LIMIT 52
#define SIZE2 SIZE1*LIMIT
unsigned char m[SIZE2];	// smallest size for each member

int main (int argc, char* argv[])
{	int i;
	char *alph[LIMIT];	// character array to allocate
	class_memory(m,SIZE2);	// pass char array of size SIZE2
									// to class_memory for allocation

	for (i = 0; i<LIMIT; i++)
		alph[i] = (int *)class_malloc(SIZE1);	// allocate using classmem lib
		
	for (i = 0; i<LIMIT; i++)
	{	alph[i] = i%26+'a';				// set member value
		printf("%c", (int) alph[i]);	// immediately print said value
	}
	puts("\n");	// end line
		
	for (i = LIMIT; i>0; i--) 
		class_free(alph[i]);	// release allocated memory used by alph array
	class_stats();	// pop stats up to see what's happened
}
