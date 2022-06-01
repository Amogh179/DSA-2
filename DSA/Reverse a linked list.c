/*Given the pointer to the head node of a linked list, change the next pointers of the nodes so that their order is reversed. The head pointer given may be null meaning that the initial list is empty.

Example
 references the list

Manipulate the  pointers of each node in place and return , now referencing the head of the list .

Function Description

Complete the reverse function in the editor below.

reverse has the following parameter:

SinglyLinkedListNode pointer head: a reference to the head of a list
Returns

SinglyLinkedListNode pointer: a reference to the head of the reversed list*/

SinglyLinkedListNode* reverse(SinglyLinkedListNode* llist)
{
    if((llist==NULL)||(llist->next==NULL)) return llist;
    else
    {
    SinglyLinkedListNode* temp1,*temp2;
    temp1=llist;
    temp2=llist->next;
    llist->next=NULL;
    while(temp2!=NULL)
    {
        SinglyLinkedListNode* temp3=temp2->next;
        temp2->next=temp1;
        temp1=temp2;
        temp2=temp3;
    }
        return temp1;
    }

}
