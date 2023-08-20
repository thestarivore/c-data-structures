#include <stdio.h>
#include <stdlib.h>
#include "circular_linked_list.h"

/**
 * Given the reference to the head of the list and an int,
 * inserts a new node on the front of the list
 */
void push(struct Node** headRef, int newData){
    //Create a new Node and push it to the front
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = newData;

    //Link new Node to the old head
    newNode->next = *headRef;

    //If the head is not null
    if(*headRef != NULL){
        //Find the last Node and link it to our new node instead of the old head
        struct Node* last = *headRef;
        while (last->next != *headRef)
            last = last->next;
        last->next = newNode;
    }
    //If head is null, the only node will be our new node and it will link to itself
    else
        newNode->next = newNode;

    //The new head is our new Node
    *headRef = newNode;
}

/**
 * Given the reference to the head of the list and an int,
 * appends a new node at the end
 */
void append(struct Node** headRef, int newData){
    //Create new Node
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = *headRef;

    //If linked list is empy, then make the new node as head
    if(*headRef == NULL){
        *headRef = newNode;
        newNode->next = newNode;
        return;
    }

    //Otherwise traverse the list until we reach the last node
    struct Node* last = *headRef;
    while (last->next != *headRef)
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
void printList(struct Node* head)
{
    struct Node* node = head;

    do{
        printf(" %d ", node->data);
        node = node->next;
    } while (node != head);
    printf("\n");
}


// Function to delete a given node
// from the list
void deleteNode(struct Node** headRef, int key)
{
    if(*headRef == NULL)
        return;

    //If we have to delete the head and it's the only node
    if((*headRef)->data == key && (*headRef)->next == *headRef){
        free(*headRef);
        *headRef = NULL;
        return;
    }

    //If we have to delete the head
    if((*headRef)->data == key){
        struct Node* last = *headRef;
        while (last->next != *headRef)
            last = last->next;
        last->next = (*headRef)->next;
        free(*headRef);
        *headRef = last->next;
        return;
    }

    //Find the node with the key, or the end of the list
    struct Node* n = *headRef;
    while (n->next != *headRef && n->next->data != key)
        n = n->next;

    if(n->next->data == key){
        struct Node* nextNext = n->next->next;
        free(n->next);
        n->next = nextNext;
    }
    else
        printf("Node not found!");
    return;
}


void testCircularLinkedLists(){
    /* Start with the empty list */
    struct Node* head = NULL;

    // Created linked list will be
    // 10->8->7->5->3->1
    push(&head, 3);
    push(&head, 5);
    push(&head, 7);
    push(&head, 8);
    push(&head, 10);
    append(&head, 1);


    printf("List Before Deletion: ");
    printList(head);

    deleteNode(&head, 7);

    printf("List After Deletion: ");
    printList(head);

    insertAfter(head, 9);
    printf("List After InsertAfter: ");
    printList(head);

    return 0;
}
