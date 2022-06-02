#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct songs
{
    char name[20];
    char sname[20];
    char mname[20];
    float dur;
    struct songs *next;
    struct songs *prev;
};
typedef struct songs *node;

node insafter(node head);
node read(node head);
void display(node head);
node del(node head);
node getnode();

int main() {

    node head;
    int n,i;
    head=NULL;
    scanf("%d",&n);
    if(n>3)
    {
    for(i=0;i<n;i++)
    {
        head=read(head);
    }
        head=insafter(head);
        head=del(head);
        display(head);
    }
    else{printf("Meera cannot create playlist.");}
    return 0;
}



node getnode()
{
    node c=(node)malloc(sizeof(struct songs));
    scanf("%s%s%f%s",c->name,c->sname,&c->dur,c->mname);
    c->next=NULL;
    c->prev=NULL;
    return c;
}


node read(node head)
{
    node c,n;
    c=head;
    n=getnode();
    if(head==NULL)
    {return n;}
    while(c->next!=NULL)
    {
        c=c->next;
    }
    c->next=n;
    n->prev=c;
    return head;

}

node insafter(node head)
{
    node c;
    node n;
    node d;
    c=head;
    char s[20];
    scanf("%s",s);
    n=getnode();
    while(c->next!=NULL)
       {
       if(strcmp(c->name,s)==0)
       {
           break;
       }
       d=c;
       c=c->next;
       }
       d=c;
       c=c->next;
       if(c==NULL&&strcmp(d->name,s)==0)
       {
           d->next=n;
           n->prev=d;
       }
       else if(c!=NULL)
       {
           d->next=n;
           n->prev=d;
           n->next=c;
           c->prev=n;
       }
    return head;
}

node del(node head)
{
    node c;
    node d;
    node e;
    c=head;
    char s[20];
    scanf("%s",s);
    if(c->prev==NULL && strcmp(c->name,s)==0)
    {
            head=c->next;
            head->prev=NULL;
            free(c);
    }
    while(c!=NULL)
    {
        if(strcmp(c->name,s)==0)
        {
            d=c->prev;
            e=c->next;
            d->next=e;
            e->prev=d;
            free(c);
            break;
        }
        c=c->next;
    }
    return head;
}

void display(node head)
{
    node c;
    c=head;
    while(c!=NULL)
    {
        printf("%s %s %s %0.2f\n",c->name,c->sname,c->mname,c->dur);
        c=c->next;
    }

}

/*node insertbefore(node head)
{
    node ptr,cur=head,temp;
    char s[20];
    printf("Enter the song name brfore which u want to insert\n");
    scanf("%s",s);
    ptr=read();
    if(head==NULL)
        printf("empty");
    else if(strcmp(head->name,s)==0)
    {
        ptr->next=head;
        head->prev=ptr;
      //  ptr->prev=NULL;
        head=ptr;
    }
    else
    {
        while(cur->next!=NULL)
        {
            if(strcmp(cur->name,s)==0)
                break;
            temp=cur;
            cur=cur->next;
        }
        temp=cur;
        cur=cur->next;
        if(cur->next==NULL && strcmp(cur->name,s)==0)
        {

        }
    }
    return head;
}*/
