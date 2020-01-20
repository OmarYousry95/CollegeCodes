#include <stdio.h>
#include <stdlib.h>

long int factorial_loop(int x);
long int factorial_rec(int x);

int main()
{
    int num;
    long int fact=0;
    printf("Enter x:");
    scanf("%d",&num);
    fact=factorial_rec(num);
    printf("%d!=%ld",num,fact);
    return 0;
}

long int factorial_rec(int x)
{
    if(x==0 || x==1)
    {
        return 1;
    }
    return x*(factorial_rec(x-1));
}

long int factorial_loop(int x)
{
    unsigned char i=0;
    long int result=x;
    if(x==0 || x==1)
    {
        return 1;
    }
    if(x<0)
    {
        return -1;
    }
    for(i=x-1;i>0;i--)
    {
        result=result*i;
    }
    return result;
}
