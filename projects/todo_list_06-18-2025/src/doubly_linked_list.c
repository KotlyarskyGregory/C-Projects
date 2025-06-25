#include <stdio.h>
#include <stdlib.h>
#include "../include/doubly_linked_list.h"

void initList(List *myList) {
    myList->head = NULL;
    myList->tail = NULL;
    myList->counterVar = 0;    
    
    return;
}

void addToTail(List *myList, const Data *data) { // TODO: add function pointer typedefs
    Data *newData = (Data*) malloc(sizeof(Data));
    Node *newNode = (Node*) malloc(sizeof(Node));

    if (!newData || !newNode) {
        printf("Memory allocation to new node/data failed.\n");
        return;
    }

    newData = data; // TODO: replace with deep copy later
    newNode->data = newData;
    newNode->pointerPrevNode = NULL;
    newNode->pointerNextNode = NULL;

    if (myList->head == NULL) {
        myList->head = newNode;
        myList->tail = newNode;
    } else {
        newNode->pointerPrevNode = myList->tail;
        myList->tail->pointerNextNode = newNode;
        myList->tail = newNode;        
    }

    myList->counterVar++;

    return;
}

void removeNode(List *myList, Node *removeNode) { // TODO: add function pointer typedefs
    Node *tempNode = removeNode;
    
    if (!myList->head || !myList->tail) {
        printf("The list is empty, nothing to remove.\n");
        return;
    }
    
    if (removeNode == myList->head) {
        myList->head = myList->head->pointerNextNode;
        if (myList->head) {
            myList->head->pointerPrevNode = NULL;
        } else {
            myList->tail = NULL;
        }
    } else if (removeNode == myList->tail) {
        myList->tail = myList->tail->pointerPrevNode;
        if (myList->tail) {
         myList->tail->pointerNextNode = NULL;
        } else {
            myList->head = NULL;
        }
    } else {
        tempNode->pointerNextNode->pointerPrevNode = tempNode->pointerPrevNode;
        tempNode->pointerPrevNode->pointerNextNode = tempNode->pointerNextNode;
    }
    
    free(tempNode->data); // TODO: call data-specific free function later
    free(tempNode);

    myList->counterVar--;

    return;
}

void clearList(List *myList) { // TODO: add function pointer typedefs
    if (!myList->head || !myList->tail) {
        printf("List is already empty\n");
        return;
    }

    Node *tempNode = myList->head;
    
    while(tempNode != NULL) {
            Node *tempNodeNext = tempNode->pointerNextNode;
            free(tempNode->data); // TODO: call data-specific free function later
            free(tempNode);
            tempNode = tempNodeNext;
    }

    myList->head = NULL;
    myList->tail = NULL;
    myList->counterVar = 0;
    
    return;
}

