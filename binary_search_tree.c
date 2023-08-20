#include <stdio.h>
#include <stdlib.h>
#include "binary_search_tree.h"
#include "stdbool.h"


// A utility function to create a new BST Node
struct Node* newNode(int item)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = item;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/* A utility function to insert a new Node with
   given key in BST */
struct Node* insert(struct Node* node, int data)
{
    /* If the tree is empty, return a new Node */
    if (node == NULL)
        return newNode(data);

    if(data <= node->data)
        node->left = insert(node->left, data);
    else
        node->right = insert(node->right, data);

    /* return the (unchanged) Node pointer */
    return node;
}

// Function to check the given key exist or not
bool iterativeSearch(struct Node* root, int key){
    if(root != NULL){
        if(key < root->data)
            return iterativeSearch(root->left, key);
        else if(key > root->data)
            return iterativeSearch(root->right, key);
        else if(root->data == key)
            return true;
    }
    else
        return false;
}

void testBinarySearchTree(){
    /* Let us create following BST
              50
            /    \
          30      70
         /  \    /  \
       20   40  60   80 */
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    if (iterativeSearch(root, 60))
        printf("Yes");
    else
        printf("No");
    return 0;
}
