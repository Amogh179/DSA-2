#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max 100000

void fillrandom(int a[max], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        a[i]=rand()%1000;
    }
}//function to fill random values in the array a

void bubblesortasc(int a[max],int n)
{
    int i,j;
    long long int count=0;
     for(i=0;i<n;i++)
     {
         for(j=0;j<n;j++)
         {
             if(a[j]>a[j+1])
              {
                 swap(&a[j],&a[j+1]);
                 count++;
              }
         }
     }
     printf("Number of swaps for %d inputs = %lld\n",n,count);
}//function to sort in ascending order

void bubblesortdesc(int a[],int n)
{
    int i,j;
    long long int count=0;
     for(i=0;i<n;i++)
     {
         for(j=0;j<n;j++)
         {
             if(a[j]<a[j+1])
             {
                 swap(&a[j],&a[j+1]);
                 count++;
             }

         }
     }
     printf("Number of swaps for %d inputs = %lld\n",n,count);
}//function to sort in descending order

int swap(int *a,int *b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}//function to swap elements

int main()
{
    int n,a[max];
    clock_t t;
    printf("size of array?\n");//number of inputs
    scanf("%d",&n);

    fillrandom(a,n);

    //to calculate time taken
    t=clock();
    bubblesortasc(a,n);
    t=clock()-t;
    double time_taken=((double)t)/CLOCKS_PER_SEC;
    printf("time taken for ascending =%lf\n",time_taken);

    t=clock();
    bubblesortdesc(a,n);
    t=clock()-t;
    time_taken=((double)t)/CLOCKS_PER_SEC;
    printf("time taken for descending =%lf\n",time_taken);

    t=clock();
    bubblesortasc(a,n);
    t=clock()-t;
    time_taken=((double)t)/CLOCKS_PER_SEC;
    printf("time taken for ascending for the second time =%lf\n",time_taken);
}
