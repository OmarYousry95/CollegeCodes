#include <stdio.h>
#include <stdlib.h>

#define SIZE 14

int longestConsecutiveOccurrance (int * a,int size);

int main()
{
    int a[SIZE]={1,2,2,3,3,3,3,3,4,4,4,4,4,4};
    int result = longestConsecutiveOccurrance(a,SIZE);
    printf("%d",result);
    return 0;
}

int longestConsecutiveOccurrance (int * a,int size)
{
    int i=0,count=1,maxCount=1;
    for(i=0;i<size;i++)
    {
        if(a[i]==a[i+1])
        {
            count++;
            if(count>maxCount)
            {
                maxCount=count;
            }
        }
        else
        {
            count=1;
        }
    }
    return maxCount;
}
