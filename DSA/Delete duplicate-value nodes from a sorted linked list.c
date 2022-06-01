/*You are given the pointer to the head node of a sorted linked list, where the data in the nodes is in ascending order. Delete nodes and return a sorted list with each distinct value in the original list. The given head pointer may be null indicating that the list is empty.

Example

 refers to the first node in the list .

Remove 1 of the  data values and return  pointing to the revised list .

Function Description

Complete the removeDuplicates function in the editor below.

removeDuplicates has the following parameter:

SinglyLinkedListNode pointer head: a reference to the head of the list*/

SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* llist) {
    SinglyLinkedListNode* current,*temp;
    current=llist;
    temp=llist->next;
    while(temp!=NULL)
    {
        if(current->data==temp->data)
        {
            temp=temp->next;
            current->next=temp;
        }
        else{
            current=temp;
            temp=temp->next;
        }
    }
    return llist;

}
