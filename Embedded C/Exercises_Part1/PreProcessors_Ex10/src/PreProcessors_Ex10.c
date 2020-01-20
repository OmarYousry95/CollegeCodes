/*
 ============================================================================
 Name        : PreProcessors_Ex10.c
 Author      : Mohamed Tarek
 Description : Understand the basic concept of Preprocessors
 Date        : 31/3/2019
 ============================================================================
 */

#include <stdio.h>

#define PRINT_REVERSE
#define ARR_SIZE 5

int main(void)
{
	int arr[ARR_SIZE] = {1,2,3,4,5};
	int i;

	for(i=0;i<ARR_SIZE;i++)
	{
#ifdef PRINT_REVERSE
		printf("arr[%d] = %d\n",ARR_SIZE - i - 1,arr[ARR_SIZE - i - 1]);
#else
		printf("arr[%d] = %d\n",i,arr[i]);
#endif
	}

	return 0;
}
