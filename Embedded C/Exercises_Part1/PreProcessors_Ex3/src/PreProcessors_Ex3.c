/*
 ============================================================================
 Name        : PreProcessors_Ex3.c
 Author      : Mohamed Tarek
 Description : Understand the basic concept of #if #else Preprocessors
 Date        : 31/3/2019
 ============================================================================
 */

#include <stdio.h>

#define NUM 10

int main(void)
{
	int x = 5;

#if(NUM > 0)
	x++;
	printf("x = %d\n",x);
#else
	x--;
	printf("x = %d\n",x);
#endif

	return 0;
}