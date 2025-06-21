#include <stdio.h>
#include <stdlib.h>
#include "../include/singly_linked_list.h"

void initList(Node *node) {
    node->nextNodePointer = NULL;
    return;
}

void addToTail(Node *node, int input) {
    Node *newNode = (Node*) malloc(sizeof(*newNode));
    if (newNode == NULL) {
        printf("Not able to allocate for new node.\n");
        return;
    }

    Data *newData = (Data*) malloc(sizeof(*newData));
    if (newData == NULL) {
        printf("Not able to allocate for new data.\n");
        return;
    }
    
    newData->data = input;
}