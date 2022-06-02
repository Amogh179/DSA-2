#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct bookdetail
{
          char name[20];
          char author[20];
          int isbn;

};
void sort(struct bookdetail v[],int n)
{
    struct bookdetail o[50];
    int i,j;
     for (i = 0; i < n; i++)
        {
            for (j = i + 1; j < n; j++)
            {
                if (v[i].isbn > v[j].isbn )
                {
                    o[i] =  v[i];
                    v[i] =  v[j];
                    v[j] = o[i];
                }
            }
        }
    for(i=0;i<n;i++)
    {
             printf("\nBook No.%d\n",i+1);
          printf("\t\tBook Name is=%s \n",v[i].name);
          printf("\t\tBook Author is=%s \n",v[i].author);
        printf("\t\tBook ISBN is=%d \n",v[i].isbn);
                   printf("\n");
    }
}
void search(struct bookdetail v[],int n)
{
    int i,value;
    char s[20];
    printf("enter the name of the book :\n");
    scanf("%s",s);
    for(i=0;i<n;i++)
    {
          value=strcmp(v[i].name,s);
                if(value==0)
                {
                     printf("\nBook No.%d\n",i+1);
                      printf("\t\tBook Name is=%s \n",v[i].name);
                      printf("\t\tBook Author is=%s \n",v[i].author);
                    printf("\t\tBook ISBN is=%d \n",v[i].isbn);
                   printf("\n");
                   exit(0);
                }
                 else
                printf("Search unsuccessful");
    }
}
void read(struct bookdetail b[],int n)
{
    int i;
     for(i=0;i<n;i++)
          {
                   printf("\tBook %d Detail:\n",i+1);

                   printf("\nEnter the Book Name:\n");
                   scanf("%s",b[i].name);

                   printf("Enter the Author of Book:\n");
                   scanf("%s",b[i].author);

                   printf("Enter the isbn no. Book:\n");
                   scanf("%d",&b[i].isbn);
          }
}
void display(struct bookdetail b[],int n)
{
    int i;
      for(i=0;i<n;i++)
          {
                   printf("\nBook No.%d\n",i+1);
                   printf("\t\tBook  Name is=%s \n",b[i].name);
                   printf("\t\tBook  Author is=%s \n",b[i].author);
                   printf("\t\tBook  ISBN is=%d \n",b[i].isbn);
                   printf("\n");
          }
}
void main()
{
          struct bookdetail b[50];
          int n,i;
          printf("Enter the Numbers of Books:");
          scanf("%d",&n);
          printf("\n");
          read(b,n);
          display(b,n);
          printf("\nAfter sorting:\n");
           sort(b,n);
           search(b,n);
}
