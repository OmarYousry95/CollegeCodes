/*
 ============================================================================
 Name        : PreProcessors_Ex5.c
 Author      : Mohamed Tarek
 Description : Understand the basic concept of #if #elif #else Preprocessors
 Date        : 31/3/2019
 ============================================================================
 */

#include <stdio.h>

#define NUM -5

int main(void)
{
	int x = 5;

#if(NUM > 0)
	x++;
	printf("x = %d\n",x);
#elif(NUM < 0)
	x--;
	printf("x = %d\n",x);
#else
	x = 0;
	printf("x = %d\n",x);
#endif

	return 0;
}
