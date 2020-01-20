#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef unsigned char uint8;
uint8 linearSearch (int*arr,int size, int element);

int main()
{
    int arr[SIZE]={1,2,3,4,4,4,5,6,7,8};
    uint8 idx = linearSearch(arr,SIZE,4);
    printf("index=%d",idx);
    return 0;
}

uint8 linearSearch (int*arr,int size, int element)
{
    uint8 i=0;
    for(i=size;i>0;i--)
    {
        if(element==arr[i])
        {
            return i;
        }
    }
    return -1;
}
