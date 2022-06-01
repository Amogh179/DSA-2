/*You will be given n strings.You have to create a doubly linked list and then insert the given strings into it. After Insertion, You have to perform 'Q' queries. In each query, you will be provided with a string, your task is to delete the given string from the doubly linked list. After performing all the queries, your task is print the final Doubly linked list.

Input Format

First line will contain an integer n. Each of the Next n lines will contain a string S. Next line will contain an integer Q, denoting the number of Queries. Each of the next Q lines, contains a string to be deleted from the string.

Constraints

1 <= N <= 10^3 1 <= Q <= N 1 <= |S| <= 10^3

Output Format

Print the Final content of the Doubly Linked List separated by space.*/


#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
}*NODE;


NODE getNode(int d)
{
    NODE n = (NODE)malloc(sizeof(struct node));
    if(n==NULL)
        exit(0);
    //printf("Enter a number : ");
    n->data = d;
    n->next = NULL;
    n->prev = NULL;
    return n;
}

NODE insert_end(NODE head, int d)
{
    NODE temp = getNode(d);
    if(head==NULL)
        return temp;
    NODE cur = head;
    while(cur->next!=NULL)
        cur = cur->next;
    cur->next = temp;
    temp->prev = cur;
    return head;
}

NODE addNode(NODE head, int pos, int data)
{
    int flag = 0, i=0;
    NODE temp = getNode(data);
    if(head==NULL)
        return head;
    NODE cur = head;
    while(cur->next!=NULL)
    {
        if(i==pos+1)
        {
            flag = 1;
            break;
        }
        cur = cur->next;
        i++;
    }
    i++;
    if(i==pos+1)
    {
        cur->next = temp;
        temp->prev = cur;
    }
    if(flag)
    {
        temp->next = cur;
        temp->prev = cur->prev;
        cur->prev->next = temp;
        cur->prev = temp;
    }
    return head;
}

void display(NODE head)
{
    if(head==NULL)
        printf("Linked list is empty.\n");
    else
    {
        NODE cur = head;
        while(cur!=NULL)
        {
            printf("%d ", cur->data);
            cur = cur->next;
        }
    }
}

int main()
{
    int n, x, p;
    scanf("%d", &n);
    NODE head = NULL;
    for(int i=0; i<n; i++)
    {
        scanf("%d", &x);
        head = insert_end(head, x);
    }
    scanf("%d %d", &p, &x);
    head = addNode(head,p,x);
    display(head);
    return 0;
}

