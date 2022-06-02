
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
            printf("Card number should have at least 2 digits.");
    else
        valid(n,org);
    return 0;
}
int valid(int n,int org)
{
    int m1,m2,sum=0;
    while(n!=0)
    {
      m1=n%10;
      sum=sum+m1;
      n=n/10;
      m2=n%10;
      sum=sum+(m2*2);
      n=n/10;
    }

    n=org;
    if(sum%10==0)
    {
        printf("The card number %d is valid.",n);
    }
    else
        printf("The card number %d is invalid.",n);
    return 0;
}
