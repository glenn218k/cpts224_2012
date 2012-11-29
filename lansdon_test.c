/*
lansdon_test
by Lansdon page
Date: 11/15/2012

Objective: 
create a new test program named <username>_test that allocates data for some task, then releases 
it using the class_XXX functions(class_malloc/class_free/etc). Make this unique as if it looks 
like other students code you may not get points.

*/

#include "cma.h"
#define STR_LEN 8 
#define MSIZE 1024*16
unsigned char mem[MSIZE];
   
int main(int argc, char * argv[]) {
	int i;
	char *strings[STR_LEN];
     	class_memory(mem,MSIZE); // give it memory allocator
  
  	for (i = 0; i<STR_LEN; ++i) {
   		strings[i] = (char *)class_malloc(1024); //allocate from classmem library
	}

	*(strings[0]) = 'L';
	*(strings[1]) = 'A';
	*(strings[2]) = 'N'; 
	*(strings[3]) = 'S'; 
	*(strings[4]) = 'D'; 
	*(strings[5]) = 'O'; 
	*(strings[6]) = 'N'; 
	*(strings[7]) = '\n'; 
  	
	for (i = 0; i<STR_LEN; ++i) {
		printf("%c", (char) *strings[i]);
	}	

	for (i = STR_LEN-1; i>=0; --i) {
		class_free(strings[i]);
	}  
   	class_stats();
}

