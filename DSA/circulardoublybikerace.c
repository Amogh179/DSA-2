#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct race
{
    char name[20],bike[20];
    int lap;
    struct race *next;
    struct race *prev;
}*node;

node getnode()
{
    node newn=(node)malloc(sizeof(struct race));
    scanf("%s%s%d",newn->name,newn->bike,&newn->lap);
    newn->prev=newn;
    newn->next=newn;
    return newn;
}

node insertend(node head)
{
    node newn=getnode(),cur=NULL;
    if(head==NULL)
        head=newn;
    else{
        cur=head->prev;
        cur->next=newn;
        newn->prev=cur;
        newn->next=head;
        head->prev=newn;
    }
    return head;
}

node delspecific(node head)
{
    node cur=head;
    char n[20];
    scanf("%s",n);
    if(strcmp(cur->name,n)==0)
    {
        head=cur->next;
        head->prev=cur->prev;
        cur->prev->next=head;
        free(cur);
    }
    do{
        if(strcmp(cur->name,n)==0)
        {
            break;
        }
        cur=cur->next;
    }while(cur!=head);

    if(cur->next==head && strcmp(cur->name,n)==0)
    {
        cur->prev->next=head;
        head->prev=cur->prev;
         free(cur);
    }
    else{
        cur->next->prev=cur->prev;
        cur->prev->next=cur->next;
        free(cur);
    }
    return head;
}

void display(node head)
{
    node cur=head;
    do
    {
        printf("%s  %s  %d         ",cur->name,cur->bike,cur->lap);
        cur=cur->next;
    }while(cur!=head);
    printf("\n");

    cur=head;
    do{
        cur->lap++;
        cur=cur->next;
    }while(cur!=head);

}

int main() {
    int n,i;
    node head=NULL;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        head=insertend(head);
    }
    display(head);
    head=delspecific(head);
    display(head);
    return 0;
}
