#include <stdio.h>
#include <stdlib.h>

#define SIZE    9

int summation(int numbers_size, int* numbers);

int main()
{
    int arr[SIZE]={1,2,3,4,5,6,7,8,9};
    int sum=summation(SIZE,arr);
    printf("Sum = %d",sum);
    return 0;
}

int summation(int numbers_size, int* numbers)
{
    unsigned char i=0;
    int sum=0;
    for(i=0;i<numbers_size;i++)
    {
        sum+=numbers[i];
    }
    return sum;
}
