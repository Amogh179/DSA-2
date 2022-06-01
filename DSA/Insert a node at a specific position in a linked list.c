/*Given the pointer to the head node of a linked list and an integer to insert at a certain position, create a new node with the given integer as its  attribute, insert this node at the desired position and return the head node.

A position of 0 indicates head, a position of 1 indicates one node away from the head and so on. The head pointer given may be null meaning that the initial list is empty.

Example
 refers to the first node in the list


Insert a node at position  with . The new list is

Function Description Complete the function insertNodeAtPosition in the editor below. It must return a reference to the head node of your finished list.

insertNodeAtPosition has the following parameters:

head: a SinglyLinkedListNode pointer to the head of the list
data: an integer value to insert as data in your new node
position: an integer position to insert the new node, zero based indexing
Returns

SinglyLinkedListNode pointer: a reference to the head of the revised list*/

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {
    SinglyLinkedListNode* temp = (SinglyLinkedListNode*)malloc(sizeof(SinglyLinkedListNode));
    if(head == NULL) {
        head->data = data;
        head->next = NULL;
        return head;
    } else {
        if(position == 0) {
            temp->data = data;
            temp->next = head;
            return temp;
        } else {
            SinglyLinkedListNode* prev = head;
            temp->data = data;
            for(int i = 0; i < position-1; i++) {
                prev = prev->next;
            }
            temp->next = prev->next;
            prev->next = temp;
        }
    }
    return head;
}
