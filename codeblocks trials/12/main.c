#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int getNthTermArithSeries (int n,int firstElement, int d);
int getNthTermGeoSeries(int n,int firstElement, int d);

int main()
{
    int firstElement = 1;
    int n1=100,n2=10;
    int element=getNthTermArithSeries(n1,firstElement,2);
    printf("%dth element = %d",n1,element);
    int element2=getNthTermGeoSeries(n2,firstElement,3);
    printf("\n%dth element = %d",n2,element2);
    return 0;
}

int getNthTermArithSeries (int n,int firstElement, int d)
{
    return firstElement+(n-1)*2;
}

int getNthTermGeoSeries(int n,int firstElement, int d)
{
    return firstElement*(pow(d,n-1));
}
