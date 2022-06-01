/*Given a doubly-linked list, a position p, and an integer x. The task is to add a new node with value x at the position just after pth node in the doubly linked list.

Input Format

Explanation: p = 2, and x = 6. So, 6 is inserted after p, i.e, at position 3 (0-based indexing). Explanation: p = 0, and x = 44 . So, 44 is inserted after p, i.e, at position 1 (0-based indexing).

Constraints

1 <= N <= 104 0 <= p < N

Output Format

The task is to complete the function addNode() which head reference, position and data to be inserted as the arguments, with no return type.*/

#include<stdio.h>
#include<stdlib.h>
struct node
{

    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node * NODE;

NODE getNode();
NODE Insert_front(NODE);
void Display(NODE);
NODE Insert_end(NODE );
NODE insert_pos(NODE);

NODE Delete_ele(NODE head);
int main()
{
      NODE head = NULL;
    int i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    head=Insert_end(head);
    head=insert_pos(head);
     Display(head);
}

NODE getNode()
{
    NODE Newnode=malloc(sizeof(struct node));
    int element;
    if(Newnode==NULL)
    {
        exit(0);
    }
    scanf("%d",&element);
    Newnode->data=element;
    Newnode->next=NULL;
    Newnode->prev=NULL;
    return Newnode;
}
NODE insert_pos(NODE head)
{

    NODE newnode;
    int pos1,pos;
    scanf("%d",&pos1);
    pos=pos1+1;
    if(head==NULL&&pos>1)
    {
        return head;
    }
    if(pos==1)
    {

       head=Insert_front(head);

       return head;
    }
    else
    {
         newnode=getNode();
        int i=1;
        NODE cur=head,p=NULL;

        while(cur->next!=NULL && i!=pos)
        {
            p=cur;
            cur=cur->next;
            i++;
        }

       if(pos==i+1)
        {
            cur->next=newnode;
            newnode->prev=cur;
            return head;
        }
        else if(pos>i+1)
        {
            return head;
        }
        else
        {
            p->next=newnode;
            newnode->prev=p;
            newnode->next=cur;
            cur->prev=newnode;
            return head;
        }


    }
}
NODE Insert_front(NODE head)
{
    NODE Newnode=getNode();
    if(head==NULL)
    {
        head=Newnode;
        return head;
    }
    else
    {
        Newnode->next=head;
        head->prev=Newnode;
        head=Newnode;

        return head;
    }
}

NODE Insert_end(NODE head)
{
    NODE newnode=getNode();
    if(head==NULL)
    {
        head=newnode;
        return head;
    }
    else
    {
        NODE cur=head;
        while(cur->next!=NULL)
        {
            cur=cur->next;
        }
        cur->next=newnode;
        newnode->prev=cur;
        return head;
    }
}


void Display(NODE head)
{
    if(head==NULL)
    {
      //  printf("List is empty\n");
    }
    else
    {
        NODE cur=head;
        while(cur!=NULL)
        {
            printf("%d ",cur->data);
            cur=cur->next;
        }
    }
}
