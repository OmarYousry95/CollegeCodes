#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x=0xff000f00;
    int i=0,zeroCount=0,maxCount=0;;
    for(i=0;i<32;i++)
    {
        if(!((x<<i)&0x80000000))
        {
            zeroCount++;
            if(maxCount<zeroCount)
            {
                maxCount=zeroCount;
            }
        }
        else
        {
            zeroCount=0;
        }
    }
    printf("Longest 0's = %d",maxCount);
    return 0;
}
