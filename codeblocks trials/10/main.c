#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

void bubbleSort(int * arr,int size);
void selectionSort(int *arr, int size);
void swap(int*x,int*y);

int main()
{
    int arr[SIZE]={10,50,40,-1,0,-2,4,5};
    selectionSort(arr,SIZE);
    int i=0;
    for(i=0;i<SIZE;i++)
    {
        printf("%d\t",arr[i]);
    }
    return 0;
}

void selectionSort(int *arr, int size)
{
    unsigned char i,j,min_idx;
    for(i=0;i<size-1;i++)
    {
        min_idx=i;
        for(j=i+1;j<size;j++)
        {
            if(arr[j]<arr[min_idx])
            {
                min_idx=j;
            }
        }
        swap(&arr[min_idx],&arr[i]);
    }
}

void bubbleSort(int * arr,int size)
{
    unsigned char i,j;
    for(i=0;i<size-1;i++)
    {
        for(j=0;j<size-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}

void swap(int*x,int*y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
