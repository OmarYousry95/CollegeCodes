/*
 ============================================================================
 Name        : Macros_Ex4.c
 Author      : Mohamed Tarek
 Description : Example to understand the basic concept of Macros
 Date        : 31/3/2019
 ============================================================================
 */

#include <stdio.h>

/* Description :
 * Swap Marco to swap the values of two numbers
 */
#define SWAP(X,Y)\
{\
	/* we can declare variables inside the macro normally as temp variable \
	 * is local to the block(Block Scope) */ \
	int temp;\
	temp = X;\
    X = Y;\
    Y = temp;\
}

int main()
{
    int a=10,b=5;

    printf("Values before swapping : a=%d\t b=%d\n",a,b);

    /* Swap the two numbers */
    SWAP(a,b);

    printf("Values after swapping  : a=%d\t b=%d\n",a,b);

    return 0;
}
