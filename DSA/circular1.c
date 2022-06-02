#include<stdio.h>
#include<stdlib.h>

typedef struct Node

{
    char info[10];
    struct Node *next;
}node;

node *front=NULL,*rear=NULL,*temp;

void create()
{
    node *newnode;
    newnode=(node*)malloc(sizeof(node));
    printf("\nEnter the node value : ");
    scanf("%s",newnode->info);
    newnode->next=NULL;
    if(rear==NULL)
    front=rear=newnode;
    else
    {
    rear->next=newnode;
    rear=newnode;
    }
    rear->next=front;
}

void del()
{
    node *prev,*n;
    n=front;
    char a[20]={'o'};
    if(front==NULL)
    printf("\nEmpty");
    else
    {
        while(strcmp(n->info,a)!=0)
        {
        prev=n;
        n=n->next;
        }
        prev->next=n->next;
        n->next=NULL;
    }
}

void display()
{
    temp=front;
    if(front==NULL)
    printf("\nEmpty");
    else
    {
    printf("\n");
    for(;temp!=rear;temp=temp->next)
    printf("%s-> ",temp->info);
    printf("%s-> ",temp->info);
    }
}

int main()
{
int chc;
do
{
printf("\nMenu\n\t 1 to create  : ");
printf("\n\t 2 to delete  : ");
printf("\n\t 3 to display the queue : ");
printf("\n\t 4 to exit from main : ");
printf("\nEnter your choice : ");
scanf("%d",&chc);
switch(chc)
{
    case 1:
    create();
    break;
    case 2:
    del();
    break;
    case 3:
    display();
    break;
    case 4:
    return 1;
    default:
    printf("\nInvalid choice :");
}
}while(1);

return 0;
}
