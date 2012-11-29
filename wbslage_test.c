/*
 * =====================================================================================
 *
 *       Filename:  wbslage_test.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/15/2012 07:29:33 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author: William Slage 
 *   Organization: cpts 224 
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int main()
{
	char *cstring = malloc( sizeof(*cstring) * 256 );
	printf("Please enter you name: " );
	fgets( cstring, 256, stdin );
	printf( "\n You typed: %s", cstring);
	free ( cstring );
	getchar();
}

