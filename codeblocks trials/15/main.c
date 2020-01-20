#include <stdio.h>
#include <stdlib.h>

#define SIZE    5

void reverseArray(int * arr,int size);
void swap(int*x,int*y);
void swapTwoArrays(int *a1,int *a2, int a_size,int b_size);

int main()
{
    int i=0;
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    int b[5]={11,12,13,14,15};
    swapTwoArrays(a,b,10,5);

    for(i=0;i<5;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
    for(i=0;i<5;i++)
    {
        printf("%d\t",b[i]);
    }
    return 0;
}

void swapTwoArrays(int *a1,int *a2, int a_size,int b_size)
{
    int i=0;
    for(i=0;i<b_size;i++)
    {
        swap(&a1[i],&a2[i]);
    }
}

void reverseArray(int * arr,int size)
{
    int i=0;
    for(i=0;i<size/2;i++)
    {
        swap(&arr[i],&arr[size-i-1]);
    }
}

void swap(int*x,int*y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
