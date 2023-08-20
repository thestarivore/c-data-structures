#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

/**
 * Given the reference to the head of the list and an int,
 * inserts a new node on the front of the list
 */
void push(struct Node** headRef, int newData){
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = *headRef;
    *headRef = newNode;
}

/**
 * Given the reference to the head of the list and an int,
 * appends a new node at the end
 */
void append(struct Node** headRef, int newData){
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL;

    //If linked list is empy, then make the new node as head
    if(*headRef == NULL){
        *headRef = newNode;
        return;
    }

    //Otherwise traverse the lsit until we reach the last node
    struct Node* last = *headRef;
    while (last->next != NULL)
        last = last->next;

    last->next = newNode;
}

/* Given a node prevNode, insert a new node after the given
   prevNode */
void insertAfter(struct Node* prevNode, int newData){
    if(prevNode == NULL){
        printf("The given previous node cannot be NULL!");
        return;
    }

    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

// This function prints contents of linked list starting from head
void printList(struct Node* node)
{
    while(node != NULL){
        printf(" %d ", node->data);
        node = node->next;
    }
    printf("\n");
}



void testSinglyLinkedLists(){
    /* Start with the empty list */
    struct Node* head = NULL;

    // Insert 6.  So linked list becomes 6->NULL
    append(&head, 6);
    printList(head);

    // Insert 7 at the beginning. So linked list becomes 7->6->NULL
    push(&head, 7);
    printList(head);

    // Insert 1 at the beginning. So linked list becomes 1->7->6->NULL
    push(&head, 1);
    printList(head);

    // Insert 4 at the end. So linked list becomes 1->7->6->4->NULL
    append(&head, 4);
    printList(head);

    // Insert 8, after 7. So linked list becomes 1->7->8->6->4->NULL
    insertAfter(head->next, 8);

    printf("\n Created Linked List is: ");
    printList(head);

    return 0;
}
