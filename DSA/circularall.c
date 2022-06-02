#include <stdio.h>
#include <stdlib.h>

struct node {
char data[10];
struct node * next;
}*head;

void createList(int n)
{
    int i;
    char data[10];
    struct node *prevNode, *newNode;
    if(n >= 1)
    {

    head = (struct node *)malloc(sizeof(struct node));
    printf("Data of node 1 : ");
    scanf("%s", head->data );
    head->next = NULL;
    prevNode = head;

    for(i=2; i<=n; i++)
    {
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Data of node %d : ", i);
    scanf("%s",newNode->data);

    newNode->next = NULL;

    prevNode->next = newNode;
    prevNode = newNode;
    }

    prevNode->next = head;
    }
}

void displayList()
{
    struct node *current;
    int n = 1;
    if(head == NULL)
    {
    printf("List is empty.\n");
    }
    else
    {
    current = head;
    printf("The SINGLY CIRCULAR LINKED LIST IS : \n");
    do {
    printf("%s\t",current->data);
    current = current->next;
    n++;
    }while(current != head);
    }
}


void delete_given_position()
{
struct node * temp, *s;
temp=head;
if (head == NULL)
printf("\nThe List is empty");
else
{
    do
    {
        if(strcmp(temp->data,"o")==0)
        {
            temp=temp->next;
            free(temp);
        }
    }while(temp != head);
}
}

int main()
{
int n, data, choice=1;
head = NULL;
while(choice != 0)
{
printf("\n\n\t\tCIRCULAR LINKED LIST BASIC OPERATIONS\n\n");
printf("1. Create List\n");
printf("2. Delete o position\n");
printf("0. Exit\n");
printf("\n\n");
printf("Enter your choice : ");
scanf("%d", &choice);
switch(choice)
{
case 1:
printf("Enter the total number of nodes in list: ");
scanf("%d", &n);
createList(n);
displayList();
break;
case 2:
if(head == NULL)
{
printf("\nThe list is empty\n");
}
else
{
delete_given_position();
displayList();
}
break;

case 0:
break;
default:
printf("Error! Invalid choice.");
}
printf("\n");
}
return 0;
}
