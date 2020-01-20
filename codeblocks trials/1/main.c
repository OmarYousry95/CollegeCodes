#include <stdio.h>
#include <stdlib.h>

long sumOfFirst100Elements (void);

int main()
{
    long sum=sumOfFirst100Elements();
    printf("%d",sum);
    return 0;
}

long sumOfFirst100Elements (void)
{
    long sum=0;
    unsigned char i=0;
    for(i=0;i<=100;i++)
    {
        sum=sum+i;
    }
    return sum;
}
