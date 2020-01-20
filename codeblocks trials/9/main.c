#include <stdio.h>
#include <stdlib.h>


#define TRUE 1
#define FALSE 0
typedef unsigned char bool;

bool stringCheck (char * str);

int main()
{
    char str[30]="   ";
    bool ret = stringCheck(str);
    if(ret == TRUE)
    {
        printf("True");
    }
    if(ret == FALSE)
    {
        printf("FALSE");
    }
    return 0;
}

bool stringCheck (char * str)
{
    unsigned char i=0,j=0;
    while(str[i] != '\0')
    {
        j=i+1;
        while(str[j] != '\0')
        {
            if(str[i]==str[j])
            {
                return FALSE;
            }
            j++;
        }
        i++;
    }
    return TRUE;
}
