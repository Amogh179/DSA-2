/*On the release date of the movie Venom 2, there is a huge line at the ticket counter at INOX and price of each ticket is 300Rs. To manage the huge number of ticket buyers, the INOX staff named Vikram requests the people to form new line formed in such a way that maximum K number of people who have age between 18 to 25, are allowed. Display the content of new line. One of the person standing in new line wants to know his/her position and requests INOX staff to tell his/her position. After approving the request of the person, INOX staff displays the current position. Help INOX staff to display total amount collected in both lines. The people in line are recognized by Name and Age.

Input Format

Number of people in the line is N and K is number of people who are allowed to enter in new line.

Enter N and K in first line separated by space.

Next N line indicates the information of N people.

Next line indicates the name of the person who request for the position.

Constraints

1 ≤ N ≤ 100

0≤ K ≤N/2

15 ≤ Age of person ≤ 99

1 ≤ Position of person ≤N/2

Output Format

Display the information of people standing in new line.

Each record is displayed on separate line.

In next line shows the position of Karan, If Karan is not there in new line, display position as 0.

In next two lines display total amount collected in both the lines.*/


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node
{
   char name[20];
   int age;
   struct node *next;
};

typedef struct node *NODE;

NODE getnode();
NODE enqueue(NODE);
void display(NODE,int);

int main()
{
    NODE head=NULL;
    int n,i=0,k;
    scanf("%d",&n);
    scanf("%d",&k);
    if(n<1 || n>100)
    {
        printf("N should be greater than 0\n");
        exit(0);
    }
    while(i<n)
    {
        head=enqueue(head);
        i++;
    }
    display(head,n);
    return 0;
}

NODE getnode()
{
    NODE NEWNODE;
    NEWNODE=malloc(sizeof(struct node));
    if(NEWNODE==NULL)
    {
        printf("Memory is not allocated\n");
    }
    scanf("%s%d",NEWNODE->name,&NEWNODE->age);
    NEWNODE->next=NULL;
    return NEWNODE;
}

NODE enqueue(NODE head)
{
    NODE newnode=getnode();
    NODE cur=head;
    if(head==NULL)
    {
        head=newnode;
        return head;
    }
    else
    {
        while(cur->next!=NULL)
        {
            cur=cur->next;
        }
        cur->next=newnode;
        return head;
    }
}

void display(NODE head, int n)
{
    NODE temp=head;
    char person[20];
    scanf("%s",person);
    int count=0,position=0,cost1,cost2;
     while(temp!=NULL)
     {
         if(temp->age>=18 && temp->age<=25)
         {
             count++;
             printf("%s %d\n",temp->name,temp->age);
         }
         temp=temp->next;
     }
     NODE cur=head;
     while(cur!=NULL)
     {
         if(cur->age>=18 && cur->age<=25)
         {
             position++;
             if(strcmp(cur->name,person)==0)
             {
                 printf("%d\n",position);
             }
         }
         else
         {
            if(strcmp(cur->name,person)==0)
             {
                 printf("0\n");
             }
         }
         cur=cur->next;
     }
     cost1=(n-count)*300;
     cost2=count*300;
     printf("%d\n",cost1);
     printf("%d",cost2);
}
