/*One of the utility bill payments company wants to build a mobile recharge application for end users. The application should support all the network providers available in the market. The flow is, the user sends SMS in predefined format and application should parse the message and do the recharge accordingly.

Now, the biggest challenge is the application gets a huge number of recharge requests during the peak hours and is not able to process each request, so the company is looking for some strategy where all the requests are parked when they come and processed one by one. Initially all the requests are parked together and then the prepaid and post-paid requests are separated. The company would like to know the total amount of money collected towards prepaid and post-paid mobile recharge. Apply Problem Solving Framework to simulate the above scenario.

Input Format

The first line contains N number of requests.

The next N lines indicate the requests containing phone number, recharge amount and recharge type.

Constraints

0

Recharge type: post-paid/prepaid

Output Format

The first line indicates about the type of recharge.

The next few lines indicate details of all the requests under that type.

The next line indicates the total amount of recharge.
The next line indicates the total amount of recharge.*/

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct recharge
{
    char type[10];
    long long int mobileno;
    int amt;
    struct recharge *next;
};
typedef struct recharge *node;

node getnode()
{
    node newn;
    newn = (node)malloc(sizeof(struct recharge));
    if (newn == NULL)
    {
        printf("Not created\n");
        exit(0);
    }
    newn->next = NULL;
    scanf("%lld %d %s",&newn->mobileno,&newn->amt,newn->type);
    return newn;
}

node insert_rear(node head)
{
    node newn=NULL,cur=NULL;
    newn=getnode();
    if(head==NULL)
    {
       return newn;
    }
   else
    {
        cur=head;
        while(cur->next!=NULL)
        {


        cur=cur->next;
        }
        cur->next=newn;
    }
    return head;
}

void recharg(node head)
{
    int a=0,b=0,flag1=0,flag2=0;
    node cur=NULL;
        cur=head;
        printf("Postpaid Requests\n");
        while(cur!=NULL)
        {
            if(strcmp(cur->type,"postpaid")==0)
            {
                a=a+cur->amt;
                flag1=1;
            }
            cur=cur->next;
        }
            if(flag1==1)
            {
                cur=head;
                 while(cur!=NULL)
                 {
                     if(strcmp(cur->type,"postpaid")==0)
                     {
                        printf("%lld %d %s\n",cur->mobileno,cur->amt,cur->type);
                     }cur=cur->next;
                  }
                printf("%d\n",a);
            }
            else
            {
                printf("Queue Empty\n0\n");
            }

         cur=head;
        printf("Prepaid Requests\n");

        while(cur!=NULL)
        {
            if(strcmp(cur->type,"prepaid")==0)
            {

                b=b+cur->amt;
                flag2=1;
            }
            cur=cur->next;
        }
        if(flag2==1)
        {
           cur=head;
           while(cur!=NULL)
           {
               if(strcmp("prepaid",cur->type)==0)
               {
                   printf("%lld %d %s\n",cur->mobileno,cur->amt,cur->type);
               }            cur=cur->next;
          }
           printf("%d\n",b);
        }
       else
      {
          printf("Queue Empty\n0\n");
      }
}

int main()
{
    node head=NULL;
    int i,N;
    scanf("%d",&N);
    if(N>0)
    {
        for(i=0;i<N;i++)
        {
            head=insert_rear(head);
        }
          recharg(head);
    }
    return 0;
}

