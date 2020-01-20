#include <stdio.h>
#include <stdlib.h>

#define PRIME       0
#define NOT_PRIME   1
#define ARR_SIZE    10

typedef struct{
    int primeSum;
    int nonPrimeSum;
}array_sum;

unsigned char checkPrime (int x);
array_sum sumOfPrimeInArray(int *arr);


int main()
{
    /*
    int x;
    printf("Enter x:");
    scanf("%d",&x);
    if(checkPrime(x)== PRIME)
        printf("Prime\n");
    if(checkPrime(x)== NOT_PRIME)
        printf("Not Prime\n");
    */
    int arr[ARR_SIZE]={2,3,5,7,11,13,17,19,23,28};
    array_sum result=sumOfPrimeInArray(arr);
    printf("Prime sum = %d\nNon-Prime Sum=%d\n",result.primeSum,result.nonPrimeSum);
    return 0;
}

array_sum sumOfPrimeInArray(int *arr)
{
    int i=0;
    array_sum Sum={0,0};
    for(i=0;i<ARR_SIZE;i++)
    {
        if(checkPrime(arr[i])==PRIME)
        {
            Sum.primeSum+=arr[i];
        }
        else
        {
            Sum.nonPrimeSum+=arr[i];
        }
    }
    return Sum;
}

unsigned char checkPrime (int x)
{
    int i=0;
    if(x==0 || x==1)
    {
        return NOT_PRIME;
    }
    for(i=x-1;i>1;i--)
    {
        if(x%i == 0)
        {
            return NOT_PRIME;
        }
    }
    return PRIME;
}
