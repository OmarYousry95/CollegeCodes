/*
 ============================================================================
 Name        : Macros_Ex3.c
 Author      : Mohamed Tarek
 Description : Example to understand the basic concept of Macros
 Date        : 31/3/2019
 ============================================================================
 */

#include <stdio.h>

/* Description :
 * MAX Marco to print the maximum value of two numbers
 */
#define MAX(X,Y){\
    if(X>Y)\
    {\
        printf("The Greater Number Is : %d\n",X);\
    }\
    else\
    {\
        printf("The Greater Number Is : %d\n",Y);\
    }\
}

int main()
{
    int a=10,b=5;

    /* Print the maximum number */
    MAX(a,b);

    return 0;
}
