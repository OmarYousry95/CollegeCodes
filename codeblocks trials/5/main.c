#include <stdio.h>
#include <stdlib.h>

long int numPower(int x,int y);
long int numPower_rec(int x,int y);

int main()
{
    long int x= numPower_rec(2,3);
    printf("%ld",x);
    return 0;
}

long int numPower_rec(int x,int y)
{
    if(y==0)
    {
        return 1;
    }
    if(y==1)
    {
        return x;
    }
    return x*numPower_rec(x,y-1);
}

long int numPower(int x,int y)
{
    int i=0;
    long int result=1;
    if(y==0)
    {
        return 1;
    }
    if(y==1)
    {
        return x;
    }
    for(i=y;i>0;i--)
    {
        result*=x;
    }
    return result;
}
