#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *myptr;
	int newval = 0;
	int i;

	myptr = (int *)malloc(sizeof(int));

	*myptr = 5;

	for(i=0;i<*myptr;i++)
	{
		newval += *myptr;
	}
	printf("%d\n", newval);

	free(myptr);

	return 0;
}