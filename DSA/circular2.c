#include<stdio.h>
#include<stdlib.h>
struct node
{
    float data;
    struct node *next;
};
struct node *head;

void lastinsert()
{
    struct node *ptr,*temp;
    float item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if(ptr == NULL)
    {
        printf("\nOVERFLOW\n");
    }
    else
    {
        printf("\nEnter Data?");
        scanf("%f",&item);
        ptr->data = item;
        if(head == NULL)
        {
            head = ptr;
            ptr -> next = head;
        }
        else
        {
            temp = head;
            while(temp -> next != head)
            {
                temp = temp -> next;
            }
            temp -> next = ptr;
            ptr -> next = head;
        }
        printf("\nnode inserted\n");
    }

}

void display()
{
    struct node *ptr;
    ptr=head;
    if(head == NULL)
    {
        printf("\nnothing to print");
    }
    else
    {
        printf("\n printing values ... \n");

        while(ptr -> next != head)
        {

            printf("%.2f-> ", ptr -> data);
            ptr = ptr -> next;
        }
        printf("%.2f-> ", ptr -> data);
    }
}

void search()
{
    struct node *ptr;
    ptr=head;
    int count=0;

    if(head == NULL)
    {
        printf("\nnothing to print");
    }
    else
    {
        do
        {
            if(ptr->data>=9.0)
            {
               count++;
            }
              ptr = ptr -> next;
        }while(ptr->next != head);
        printf("\n no. of students with above 9.0 SGPA = %d \n",count);
    }

        do
        {
            if(ptr->data>=9.0)
            {
                printf("%.2f-> ", ptr -> data);
           }
              ptr = ptr -> next;
        } while(ptr->next != head);

}

void newnnode()
{
    struct node *ptr;
    ptr=head;
    if(head==NULL)
        printf("No nodes\n");
    else
    {
         do
        {
            if(ptr->data<=4.0)
            {
                printf("%.2f-> ", ptr -> data);
            }
              ptr = ptr -> next;
        }while(ptr != head);
    }
}

void main ()
{
    int choice=0;
    while(1)
    {
        printf("\n1Insert at last\n2.Show\n3.above 9\n4.sgpa below 4\n5.Exit\n");
        printf("\nEnter your choice?\n");
        scanf("\n%d",&choice);
        switch(choice)
        {
            case 1:
            lastinsert();
            break;
            case 2:
            display();
            break;
            case 3:
            search();
            break;
            case 4:
            newnnode();
            break;
            case 5:
            exit(0);
            break;
            default:
            printf("Please enter valid choice..");
        }
    }
}
