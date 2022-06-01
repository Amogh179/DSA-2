#include<stdio.h>
#include<stdlib.h>
#include <stdio.h>
//#include <string.h>
#include <math.h>
#include <stdlib.h>
struct metro
{
    int price;
    char from[20];
    char to[20];
};

void read (struct metro *p,int n);
void display(struct metro *p,int n);
void displaystart(struct metro *p,int n);
void displayend(struct metro *p,int n);

void main()
{
    int n;
    printf("enter the number of tokens\n");
    scanf("%d",&n);
    struct metro *p;
    p=(struct metro *)malloc(n*sizeof(struct metro));
    int i;
    read(p,n);
    display(p,n);
    displaystart(p,n);
    displayend(p,n);
}
void read(struct metro *p,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("enter the price:\n");
        scanf("%d",&(p+i)->price);
        printf("enter the starting point:\n");
        scanf("%s",(p+i)->from);
        printf("enter the ending point:\n");
        scanf("%s",(p+i)->to);

    }
}
void display(struct metro *p,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("\n price:%d",(p+i)->price);
        printf("\n starting point:%s",(p+i)->from);
        printf("\n end point:%s",(p+i)->to);
        printf("\n");

    }
}
void displaystart(struct metro *p,int n)
{
     char start[25];
    printf("\nEnter the starting point : ");
    scanf(" %s", start);
    for(int i=0; i<n; i++)
    {
        if(!(strcmp(start,p[i].from)))
      {

            printf("\n price:%d",p[i].price);
            printf("\n starting point is:%s",p[i].from);
            printf("\n end point is:%s",p[i].to);
            printf("\n");
      }
}
}


void displayend(struct metro *p,int n)
{
    char end[25];
    printf("\nEnter the ending point : ");
    scanf(" %s", end);
    for(int i=0; i<n; i++)
    {
        if(!(strcmp(end,p[i].to)))
      {
          printf("\n price:%d",p[i].price);
            printf("\n starting point is:%s",p[i].from);
            printf("\n end point is:%s",p[i].to);
            printf("\n");


      }

   }
}


