#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"



// Head, Tail, first & temp Node
struct Node* head = NULL;
struct Node* first = NULL;
struct Node* temp = NULL;
struct Node* tail = NULL;
int numNodes = 0;

// Function to add a node in the
// Doubly Linked List
void addNode(int k)
{
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = k;

    //If no Head, this node is the new head
    if(head == NULL){
        head = newNode;
        tail = newNode;
        head->next = NULL;
        head->prev = NULL;
        tail->next = NULL;
        tail->prev = NULL;
    }
    //Else add at the back of the list
    else{
        temp = tail;
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = NULL;
        tail = newNode;
    }

    //Increase count of number of nodes in the list
    numNodes++;
}

// Function to traverse the Doubly
// Linked List
void traverse()
{
    temp = head;
    while(temp != NULL){
       printf("%d ", temp->data);
       temp = temp->next;
    }
    printf("\n");
}

// Function to insert a node at the
// beginning of the linked list
void insertAtBegin(int k)
{
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = k;

    // If head is NULL
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        head->next = NULL;
        head->prev = NULL;
    }
    // Else insert at the end
    else {
        newNode->next = head;
        newNode->prev = NULL;
        head = newNode;
    }

    //Increase count of number of nodes in the list
    numNodes++;
}

// Function to insert Node at end
void insertAtEnd(int k)
{
    addNode(k);
}

// Function to insert Node at any
// position pos
void insertAtPos(int k, int pos)
{
    if(pos > numNodes){
        printf("No Node at position! \n");
        return;
    }

    //find position
    struct Node * ptr = head;
    for(int i = 0; i < pos; i++){
        if(ptr != NULL)
            ptr = ptr->next;
    }

    //Insert new node
    struct Node** prev = &(ptr->prev);
    struct Node** next = &(ptr);
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = k;
    newNode->next = (*next);
    newNode->prev = (*prev);
    (*prev)->next = newNode;
    (*next)->prev = newNode;

    //Increase count of number of nodes in the list
    numNodes++;
}

// Function to delete node at the
// beginning of the list
void delAtBegin()
{
    if(head == NULL){
        printf("No Nodes! \n");
        return;
    }

    temp = head;
    head = temp->next;
    head->prev = NULL;
    free(temp);
    temp = NULL;

    //Decrease count of number of nodes in the list
    numNodes--;
}

// Function to delete at the end
// of the list
void delAtEnd()
{
    if(head == NULL){
        printf("No Nodes! \n");
        return;
    }

    temp = tail;
    tail = temp->prev;
    tail->next = NULL;
    free(temp);
    temp = NULL;

    //Decrease count of number of nodes in the list
    numNodes--;
}

// Function to delete the node at
// a given position pos
void delAtPos(int pos)
{
    if(pos > numNodes){
        printf("No Node at position! \n");
        return;
    }

    //find position
    temp = head;
    for(int i = 0; i < pos; i++){
        if(temp != NULL)
            temp = temp->next;
    }

    //Delete node
    struct Node** prev = &(temp->prev);
    struct Node** next = &(temp->next);
    (*prev)->next = *next;
    (*next)->prev = *prev;
    free(temp);
    temp = NULL;

    //Decrease count of number of nodes in the list
    numNodes--;
}


void testDoublyLinkedLists(){
    // Adding node to the linked List
    //2,4,9,1,21,22
    addNode(2);
    addNode(4);
    addNode(9);
    addNode(1);
    addNode(21);
    addNode(22);

    // To print the linked List
    printf("Linked List: ");
    traverse();

    printf("\n");

    // To insert node at the beginning
    //1,2,4,9,1,21,22
    insertAtBegin(1);
    printf("Linked List after"
           " inserting 1 "
           "at beginning: ");
    traverse();

    // To insert at the end
    //1,2,4,9,1,21,22,0
    insertAtEnd(0);
    printf("Linked List after "
           "inserting 0 at end: ");
    traverse();

    // To insert Node with
    // value 44 after 3rd Node
    //1,2,4,44,9,1,21,22,0
    insertAtPos(44, 3);
    printf("Linked List after "
           "inserting 44 "
           "after 3rd Node: ");
    traverse();

    printf("\n");

    // To delete node at the beginning
    //2,4,44,9,1,21,22,0
    delAtBegin();
    printf("Linked List after "
           "deleting node "
           "at beginning: ");
    traverse();

    // To delete at the end
    //2,4,44,9,1,21,22
    delAtEnd();
    printf("Linked List after "
           "deleting node at end: ");
    traverse();

    // To delete Node at position 5
    //2,4,44,9,1,22
    printf("Linked List after "
           "deleting node "
           "at position 5: ");
    delAtPos(5);
    traverse();

    return 0;
}
