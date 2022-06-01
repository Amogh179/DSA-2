/*You are given a sorted doubly linked list of size N, consisting of positive integers, and also provided a number K. Your task is to find out whether there exists a pair in the doubly linked list with sum K or not. If there exists a pair then you can return TRUE else return FALSE. Explanation for sample output 1 (i) For the first doubly linked list [1,2,3,4,9] there exists a pair (1,3) with a sum equal to 4. (ii) For the second doubly linked list, there is no pair with a sum equal to 10. (iii) For the third doubly linked list there exists a pair (3,4) with a sum equal to 7. Explanation for sample output 2 (i) For the first doubly linked list, there is no pair with a sum equal to 20. (ii) For the second doubly linked list there exists a pair (1,1) with a sum equal to 2. (iii) For the third doubly linked list, there is no pair with a sum equal to 5.

Input Format

The first line of input contains a single integer T, representing the number of test cases. Then the T test cases follow.

The first line of every test case contains the elements of the doubly linked list separated by a single space and terminated by -1. Hence, -1 would never be a list element.

Constraints

1<= T <=100 2 <= N <= 10^4 0 <= data <= 10^3 1 <= K <= 10^4

Time limit: 1 second

Output Format

For each test case Return “YES” if there exists a pair with a sum equal to K else Return “NO”.

The output of every test case will be printed in a separate line.*/

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

int pairSum(NODE head, int x)

{

    NODE left = head;

    NODE right = head;

    int flag = 0;

    while(right->next!=NULL)

        right = right->next;

    while(right->next!=left && left!=right)

    {

        printf("%d %d\n", left->data, right->data);

        if((left->data + right->data)==x)

        {

            flag = 1;

            left = left->next;

            right = right->prev;

        }

        else

        {

            if((left->data+right->data)<x)

                left = left->next;

            else

                right = right->prev;

        }

    }

    return flag;

}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    NODE head[50] = {NULL};

    int t, k[50], x;

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

        x = pairSum(head[i],k[i]);

        if(x == 1)

            printf("Yes\n");

        else

            printf("No\n");

    }

    return 0;

}



