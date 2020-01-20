/*
 ============================================================================
 Name        : PreProcessors_Ex8.c
 Author      : Mohamed Tarek
 Description : Understand the basic concept of #ifndef Preprocessors
 Date        : 31/3/2019
 ============================================================================
 */

#include <stdio.h>

int main(void)
{
	int x = 5;

#ifndef NUM
	x++;
	printf("x = %d\n",x);
#else
	x--;
	printf("x = %d\n",x);
#endif

	return 0;
}
