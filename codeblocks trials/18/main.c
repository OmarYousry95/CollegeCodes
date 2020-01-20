#include <stdio.h>
#include <stdlib.h>

void swapTwoPointers(int **x, int**y);

int main()
{
    int x=10,y=20;
    int *ptr_x=&x;
    int *ptr_y=&y;
    printf("Before SWAP:\tx=%d\ty=%d",*ptr_x,*ptr_y);
    swapTwoPointers(&ptr_x,&ptr_y);
    printf("\nAfter SWAP:\tx=%d\ty=%d",*ptr_x,*ptr_y);
    return 0;
}

void swapTwoPointers(int **x, int**y)
{
    int *temp=*x;
    *x=*y;
    *y=temp;
}
