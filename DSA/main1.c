#include<stdio.h>
#include "mystring.h"
int main()
{
    int a;
    char s1[]="c programming",s2[]="cprogramming";
    printf("array1=%s array2=%s\n",s1,s2);
    a=strlen(s1);
    printf("Length of the string: %d\n", a);

    a=strcmp(s1,s2);
    if(a==0)
    printf("strings are not equal\n");
    else
        printf("strings are equal\n");

    printf("\nString after splitting is:\n");
    strsplit(s1);
}
