#include<stdio.h>
typedef struct player
{
    char pname[20];
    int rank;
    int awards;
}plr;

void read(plr *ptr, int n)
{
    int i;
    printf("all the info\n");
    for(i=0;i<n;i++)
    {
      scanf("%s%d%d",ptr->pname,&ptr->rank,&ptr->awards);
      ptr++;
    }
}

void display(plr *ptr, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
      printf("NAME :%s\tRANK :%d\tAWARDS :%d\t\n",ptr->pname,ptr->rank,ptr->awards);
      ptr++;
    }

}
int main()
{
    plr t[11];
    int n;
    plr *p;
    scanf("%d",&n);
    p=&t[0];
    read(p,n);
    display(p,n);
    return 0;
}
