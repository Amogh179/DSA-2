#include<stdio.h>
#include<stdlib.h>
#include <stdio.h>
//#include <string.h>
#include <math.h>
#include <stdlib.h>
struct odirank
{
    int rank;
    char p_name[15];
    char t_name[15];
};

void read (struct odirank *p,int n, FILE *);
void fun(struct odirank *p,int n,FILE *);
void sort(struct odirank *p,int n,FILE *);


void main()
{
    int n;
    printf("enter the number of players\n");
    scanf("%d",&n);
    struct odirank *p;// struct odirank
    p=(struct odirank *)malloc(n*sizeof(struct odirank));
    int i;
    FILE *fptr;
    read(p,n,fptr);
    fun(p,n,fptr);
    sort(p,n,fptr);
}
void read(struct odirank *p,int n,FILE *fptr)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("enter the rank:\n");
        scanf("%d",&(p+i)->rank);
        printf("enter the player name:\n");
        scanf("%s",(p+i)->p_name);
        printf("enter the team name:\n");
        scanf("%s",(p+i)->t_name);

    }
    //func(p,n,fptr);
}
void fun(struct odirank *p,int n,FILE *fptr)
{
    fptr=(fopen("odi.txt","w"));
    printf("to get details open the respective file\n");
    int i;
    for(i=0;i<n;i++)
    {
        fprintf(fptr,"\n rank is:%d",(p+i)->rank);
        fprintf(fptr,"\n player name is:%s",(p+i)->p_name);
        fprintf(fptr,"\n team name is:%s",(p+i)->t_name);
       // fprintf("\n");

    }
}
void sort(struct odirank *p,int n,FILE *fptr)
{

    int i,j;
struct odirank swap;

for(i=0;i<n-1;i++)
  {
    for(j=0;j<n-1-i;j++)
    {
      if((p+j)->rank > (p+j+1)->rank)
      {
        swap= *(p+j);
        *(p+j)=*(p+j+1);
        *(p+j+1)=swap;
      }
    }
  }
  printf("After sorting \n");
  fun(p,n,fptr);
}






