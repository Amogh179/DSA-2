#include<stdio.h>
#include<stdlib.h>
struct book_details
{
    int ISBN;
    char name[20];
    char author[20];
};
typedef struct book_details bd;

void read (bd *p,int n);
void display(bd *p,int n);
void search(bd *p,int n);
void sort(bd *p,int n);

void main()
{
    int n;
    printf("enter the number of books\n");
    scanf("%d",&n);
    bd *p;
    p=(bd *)malloc(n*sizeof(bd));
    int i;
    read(p,n);
    display(p,n);
    search(p,n);
    sort(p,n);
}
void read(bd *p,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("enter the ISBN:\n");
        scanf("%d",&(p+i)->ISBN);
        printf("enter the book name:\n");
        scanf("%s",(p+i)->name);
        printf("enter the name of the author:\n");
        scanf("%s",(p+i)->author);

    }
}
void display(bd *p,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("\n ISBN:%d",(p+i)->ISBN);
        printf("\n book name:%s",(p+i)->name);
        printf("\n name of the author:%s",(p+i)->author);
        printf("\n");

    }
}
void search(bd *p,int n)
{
    int i,key,num=0;
    printf("\n\nEnter the ISBN number to search:");
    scanf("%d",&key);
    for(i=0;i<n;i++)
    {
      if(key==(p+i)->ISBN)
      {
          num=1;
          break;
      }

    }
    if(num=1)
    {
            printf("\n ISBN:%d",(p+i)->ISBN);
            printf("\n book name:%s",(p+i)->name);
            printf("\n name of the author:%s",(p+i)->author);
            printf("\n");

    }
    else
        printf("Not found");
}
void sort (bd *p,int n)
{
int i,j;
bd swap;

for(i=0;i<n-1;i++)
  {
    for(j=0;j<n-1-i;j++)
    {
      if((p+j)->ISBN > (p+j+1)->ISBN)
      {
        swap= *(p+j);
        *(p+j)=*(p+j+1);
        *(p+j+1)=swap;
      }
    }
  }
  printf("After sorting \n");
  display(p,n);
}

