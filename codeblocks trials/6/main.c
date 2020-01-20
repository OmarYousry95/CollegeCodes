#include <stdio.h>
#include <stdlib.h>


int main()
{
    int x=0,i=0,j=0;
    printf("Enter x:");
    scanf("%d",&x);
    for(i=0;i<x;i++)
    {
        for(j=0;j<x;j++)
        {
            if(j==i || j==(x-i-1))
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    /*
    for(i=x;i>=1;i--)
    {
        for(j=i;j>1;j--)
        {
            printf(" ");
        }

        for(z=0;z<(((x-i)*2)+1);z++)
        {
            printf("*");
        }
        printf("\n");
    }
    */
    /*
    for(i=x;i>=1;i--)
    {
        for(j=i;j>=1;j--)
        {
            printf("*");
        }
        printf("\n");
    }
    */
    /*
    for(i=1;i<=x;i++)
    {
        for(j=0;j<i;j++)
        {
            printf("*");
        }
        printf("\n");
    }
    */
    return 0;
}
