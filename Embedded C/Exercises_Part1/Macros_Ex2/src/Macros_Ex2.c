/*
 ============================================================================
 Name        : Macros_Ex2.c
 Author      : Mohamed Tarek
 Description : Example to understand the basic concept of Macros
 Date        : 31/3/2019
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define PI 3.1416

/* Macro to calculate the area of circle */
#define AREA_CIRCLE(R) (PI * (R) * (R))

int main(void)
{
	float r = 2.5;
	float res;
	res = AREA_CIRCLE(r);

	printf("res = %f \n",res);

	return 0;
}
