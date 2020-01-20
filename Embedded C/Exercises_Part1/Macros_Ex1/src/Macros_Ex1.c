/*
 ============================================================================
 Name        : Macros_Ex1.c
 Author      : Mohamed Tarek
 Description : Example to understand the basic concept of Macros
 Date        : 31/3/2019
 ============================================================================
 */

#include <stdio.h>

#define MUL(X,Y) (X*Y)

#define MUL_MODIFIED(X,Y) ((X) * (Y))

int main()
{
    int a = 3,b = 2;
    int c;

    c = MUL(a,b);
    printf("c=%d\n",c);

    c = MUL(a+2,b+3);
    /* error in macro because there is no ( ) around each argument */
    printf("c=%d\n",c);

    c = MUL_MODIFIED(a+2,b+3);
    printf("c=%d\n",c);

    return 0;
}
