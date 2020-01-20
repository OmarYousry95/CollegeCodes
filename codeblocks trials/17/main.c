#include <stdio.h>
#include <stdlib.h>

typedef unsigned char uint8;
uint8 g_array[256]={0};

void PrintReverseEnclusive (uint8 lower, uint8 upper,uint8 *result_size);
void PrintReverseInclusive (uint8 lower, uint8 upper,uint8 *result_size);


int main(void) {
	int count;
    int n1 = 5,n2=10;
    int *ptr;
	int arr_size_used = 0;

	PrintReverseInclusive(n1,n2,&arr_size_used);

	printf("Output Array = ");

	/* start looping from 0 to the last used element in the array */
	for(count=0;count<arr_size_used;count++)
	{
		/* access the global array using the ptr */
		printf("%d ",g_array[count]);
	}
	printf("\nOutput Array Size = %d",arr_size_used);
	return 0;
}

void PrintReverseInclusive (uint8 lower, uint8 upper,uint8 *result_size)
{
    int i=0;
    *result_size=0;
    if(lower>=upper)
    {
        g_array[0]=0xff;
        g_array[1]=0xff;
        *result_size=2;
    }
    else
    {
        for(i=upper;i>=lower;i--)
        {
            g_array[*result_size]=i;
            (*result_size)++;
        }
    }
}


void PrintReverseEnclusive (uint8 lower, uint8 upper,uint8 *result_size)
{
    int i =0;
    *result_size=0;
    if(lower>=upper)
    {
        g_array[0]=0xff;
        g_array[1]=0xff;
        *result_size=2;
    }
    else
    {
        for(i=upper-1;i>lower;i--)
        {
            g_array[*result_size]=i;
            (*result_size)++;
        }

    }
}
