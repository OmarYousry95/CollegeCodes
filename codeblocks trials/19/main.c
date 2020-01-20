#include <stdio.h>
#include <stdlib.h>



int main()
{
    int x=0xffffaaaa;
    int y=0;
    short *ptr_x=(short*)&x;
    short *ptr_y=(short*)&y;
    ptr_y[0]=ptr_x[1];
    ptr_y[1]=ptr_x[0];
    printf("%x",y);
    return 0;
}
