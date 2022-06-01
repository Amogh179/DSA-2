/*You are given a doubly-linked list with 'N' nodes, rotate the linked list counter-clockwise by 'K' nodes. 'K' is a positive integer and is smaller than the number of nodes in the linked list, that is 'N'.

Input Format

The first line of input contains an integer ‘T’ denoting the number of test cases.

The first line of each test case contains 'N' space-separated integers representing the value of each node. -1 at the end denotes NULL pointer. The second line of each test case contains a single positive integer 'K'. Explanation Of The Sample Input 1: For the first test case: The given linked list is : 4 <-> 3 <-> 9 <-> 1 <-> 7 <-> 8 <-> NULL

And K = 4 therefore we have to rotate the linked list by 4 nodes. So after the rotation, list will become
7 <-> 8 <-> 4 <-> 3 <-> 9 <-> 1 <-> NULL

For the second test case: The given linked list is 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> NULL
And K = 2 therefore we have to rotate the linked list by 2 nodes. So after the rotation, list will become
3 <-> 4 <-> 5 <-> 1 <-> 2 <-> NULL

Constraints

1 <= T <= 5 1 <= N <= 3000 1 <= K < N -10 ^ 7 <= data <= 10 ^ 7

where ‘T’ is the total number of test cases, 'N' is the total number of nodes in the linked list and ‘data’ is the value of any node of the linked list.

Output Format

For each test case, in a separate line, print the final rotated linked list.*/


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

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

NODE rotate(NODE head)
{
    if(head==NULL || head->next==NULL)
        return head;
    NODE cur = head;
    while(cur->next!=NULL)
        cur = cur->next;
    cur->next = head;
    head->prev = cur;
    head = head->next;
    head->prev->next = NULL;
    head->prev = NULL;
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
        printf("\n");
    }
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    NODE head[50] = {NULL};
    int t, k[50];
    signed int d;
    scanf("%d", &t);
    for(int i=0; i<t; i++)
    {
        while(1)
        {
             scanf("%d", &d);
             if(d==-1)
                break;
             head[i] = insert_end(head[i], d);
        }
        scanf("%d", &k[i]);
    }
    for(int i=0; i<t; i++)
    {
        for(int j=0; j<k[i]; j++)
            head[i] = rotate(head[i]);
        display(head[i]);
    }
    return 0;
}

