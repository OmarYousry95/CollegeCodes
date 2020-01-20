#include <stdio.h>
#include <stdlib.h>

int fibb_loop(int n);
int fibb_rec(int n);

int main()
{
    int n=fibb_loop(9);
    printf("%d",n);
    return 0;
}

int fibb_rec(int n)
{
    if(n==0 || n==1)
    {
        return n;
    }
    return fibb_rec(n-1)+fibb_rec(n-2);
}

int fibb_loop(int n)
{
    int i=0;
    int arr[100]={1,1};
    for(i=2;i<n;i++)
    {
        arr[i]=arr[i-1]+arr[i-2];
    }
    return arr[n-1];
}
