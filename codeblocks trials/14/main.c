#include <stdio.h>
#include <stdlib.h>

int stringLen (char * s);
void upperToLower(char *s);
int freqOfChar (char *s,char c);
void removeExceptAlphabet (char *s);
void reverseString(char *s);
void concString(char *s1, char *s2);

int main()
{
    char s1[30]="omar ";
    char s2[30]="yousry";
    concString(s1,s2);
    return 0;
}

void concString(char *s1, char *s2)
{
    int i=0;
    int len1=stringLen(s1);
    while(s2[i] != '\0')
    {
        s1[len1+i]=s2[i];
        i++;
    }
    s1[len1+i]='\0';
    printf("%s",s1);
}

void reverseString(char *s)
{
    int i=0;
    char temp;
    int j=stringLen(s)-1;
    while(i<j)
    {
        temp=s[i];
        s[i]=s[j];
        s[j]=temp;
        j--;
        i++;
    }
    printf("%s",s);
}

void removeExceptAlphabet (char *s)
{
    int i=0,j=0;
    for(i=0;s[i]!='\0';i++)
    {
        while((!((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z'))) && (s[i] != '\0'))
        {
            for(j=i;s[j]!='\0';j++)
            {
                s[j]=s[j+1];
            }
        }
    }
    printf("%s",s);
}

int freqOfChar (char *s,char c)
{
    int i=0,count=0;
    while(s[i] != '\0')
    {
        if(s[i]==c)
        {
            count++;
        }
        i++;
    }
    return count;
}

void upperToLower(char *s)
{
    int i=0;
    while(s[i] != '\0')
    {
        if(s[i]>='A' && s[i]<='Z')
        {
            s[i]+=32;
        }
        i++;
    }
    printf("%s",s);
}

int stringLen (char * s)
{
    int i=0,len=0;
    while(s[i] != '\0')
    {
        len++;
        i++;
    }
    return len;
}
