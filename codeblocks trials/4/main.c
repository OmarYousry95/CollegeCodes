#include <stdio.h>
#include <stdlib.h>

unsigned char digitsCountInNum (int x);
int reverseNum (int x);

int main()
{
    int x= 12345678;
    int z=0;
    unsigned char y=digitsCountInNum(x);
    printf("count=%d",y);
    z=reverseNum(x);
    printf("\nz=%d",z);
    return 0;
}

int reverseNum (int x)
{
    int y=0;
    while(x/10 != 0)
    {
        y=(y*10)+(x%10);
        x=x/10;
    }
    y=(y*10)+(x%10);
    return y;
}

unsigned char digitsCountInNum (int x)
{
    int count=0;
    while(x/10 != 0)
    {
        count++;
        x=x/10;
    }
    return count+1;
}
