#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int valid(int n,int org);

int main()
{
    int n,org;
    scanf("%d",&n);
    org=n;
        if(n<10)
        {
            printf("Card number should have at least 2 digits.");
            exit(0);
        }
    else
        valid(n,org);
    return 0;
}
int valid(int n,int org)
{
    int m1,m2,o1,sum1=0,sum2=0,sum=0;
    while(n!=0)
    {
        m1=n%100;
        o1=m1/10;
        sum1=sum1+o1;
        n=n/100;
    }

    n=org;

     while(n!=0)
    {
        m2=n%10;
        sum2=sum2+m2;
        n=n/10;
    }
    n=org;
    sum=sum1+sum2;
    printf("%d",sum);
    if(sum%10==0)
    {
        printf("The card number %d is valid.",n);
    }
    else
        printf("The card number %d is not valid.",n);
    return 0;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
}

