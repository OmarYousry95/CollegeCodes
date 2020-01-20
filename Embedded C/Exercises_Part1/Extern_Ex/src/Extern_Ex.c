/*
 ============================================================================
 Name        : Extern_Ex.c
 Author      : Mohamed Tarek
 Description : Example for the Extern Keyword
 Date        : 31/3/2019
 ============================================================================
 */

#include <stdio.h>

/* use the same num variable exist in the Module.c file */
extern int num;

extern void Print_Num(void);

int main(void)
{
	Print_Num(); /* Print the num value */

	num = 20; /* Change the num value */

	Print_Num(); /* Print the num value */

	return 0;
}
