/*
 ============================================================================
 Name        : PreProcessors_Ex1.c
 Author      : Mohamed Tarek
 Description : Understand the basic concept of #if Preprocessor
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
#endif

	x--;
	printf("x = %d\n",x);

	return 0;
}
