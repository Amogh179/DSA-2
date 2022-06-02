#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 10

typedef struct CAR
{
   char car_num[30];
   struct CAR *next;

}*NODE;

int c=0;
NODE read(NODE temp)
{
    printf("Enter the car number\n");
    scanf("%s",temp->car_num);
    return temp;
}
NODE getnode()
{
    NODE newnode;
    newnode = (NODE)malloc(sizeof(struct CAR));
    newnode=read(newnode);
    newnode->next=NULL;
    return newnode;

}

NODE insert_front(NODE head,NODE temp)
{

    if(c==SIZE)
    {
        printf("NO SPACE\n");
        return head;
    }
    c++;
    temp->next = head;
    head = temp;
    return head;
}

 NODE delete_front(NODE head)
 {
    if(c==0)
    {
        printf("GARAGE IS EMPTY\n");
        return head;
    }
    NODE temp =head;
    printf("The car number taken out %s\n",temp->car_num);
    head=head->next;

    free(temp);
    c--;
    return head;

 }
void display(NODE head)
{
    int i;
    NODE cur=head;
      while(cur!=NULL)
      {
          printf("%s\n",cur->car_num);
          cur=cur->next;
      }
}
 NODE depart(NODE head, char car[])
 {
   NODE cur = head,head1=NULL,temp1, temp2=NULL,temp3 ,temp=head,X;
    int f=0;
    // if the first car is to be  departed
    if(strcmp(cur->car_num,car) == 0)
    {
        head=delete_front(head);
        return head;
    }
 // if the car is somewhere in the list
    while(cur->next!=NULL)
    {
       if(strcmp(cur->car_num,car)==0)
       {  f=1;

           while(temp!=cur)
           {     temp1=(NODE)malloc(sizeof(struct CAR));
                 temp1->next=NULL;

                 strcpy(temp1->car_num,temp->car_num);
                 head1=insert_front(head1,temp1);
                 head =  delete_front(head);
                 temp=temp->next;
           }

           head = cur->next;
           X=cur;
           free(X);
           display(head);
           NODE T;

           temp3=head1;
           while(temp3->next!= NULL)
           {
                T=(NODE)malloc(sizeof(struct CAR));
                T->next=NULL;

               strcpy(T->car_num,temp3->car_num);

               head=insert_front(head,T);
               head1=delete_front(head1);
               temp3=head1;
           }
            T=(NODE)malloc(sizeof(struct CAR));
                T->next=NULL;
           strcpy(T->car_num,temp3->car_num);
           head =insert_front(head,T);
           head1=delete_front(head1);

            printf("AFTER DEPARTURE\n");
             display(head);
       //     return head;
              break;

       }

       else
        cur=cur->next;
   }
   // logic to handle if the car is at the end of the list
    temp=head;
   if(strcmp(cur->car_num,car)==0)
   {
       f=1;

           while(temp!=cur)
           {     temp1=(NODE)malloc(sizeof(struct CAR));
                 temp1->next=NULL;

                 strcpy(temp1->car_num,temp->car_num);
                 head1=insert_front(head1,temp1);
                // display(head1);
                 head =  delete_front(head);
                 temp=temp->next;
           }
           head=NULL;
           free(temp);
           temp3=head1;
           NODE T;
           while(temp3->next!= NULL)
           {
                T=(NODE)malloc(sizeof(struct CAR));
                T->next=NULL;
                strcpy(T->car_num,temp3->car_num);
                head=insert_front(head,T);
                head1=delete_front(head1);
                temp3=head1;
           }
            T=(NODE)malloc(sizeof(struct CAR));
            T->next=NULL;
            strcpy(T->car_num,temp3->car_num);
            head =insert_front(head,T);
            head1=delete_front(head1);

            printf("AFTER DEPARTURE\n");
             display(head);
   }
   if(f==0)
         printf("NOT FOUND\n");
   return head;


 }

int main()
{
    NODE head=NULL,temp;
    int Q,i;
    char car[15];
    int type;
    while(1)
    {
        printf("Enter the type\n");
        scanf("%d",&type);
        switch(type)
        {
            case 1: temp=getnode();
                      head =insert_front(head,temp);
                      break;
            case 2: printf("Enter the car number\n");
                       scanf("%s",car);
                       head = depart(head,car);
                       break;
             case 3:display(head);
                       break;
             default: printf("invalid");
                       exit(0);

        }

    }

}
