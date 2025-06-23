#include <stdio.h>
#include <stdlib.h>
#include "../include/doubly_linked_list.h"

void initList(List *newList) {
    newList->head = NULL;
    newList->tail = NULL;
    newList->counterVar = 0;
    return;
}

void addToTail(List *myList, const int inputIndex, const int inputVal) {
    Data *newData = (Data*) malloc(sizeof(Data));
    Node *newNode = (Node*) malloc(sizeof(Node));

    if (!newData || !newNode) {
        printf("Error in allocating memory for new data/node\n");
        return;
    }

    newData->storeIndex = inputIndex;
    newData->storeValue = inputVal;
    newNode->data = newData;
    newNode->nextNodePointer = NULL;
    newNode->prevNodePointer = NULL;

    if (myList->head == NULL) {
        myList->head = newNode;
        myList->tail = newNode;
    } else {
        newNode->prevNodePointer = myList->tail;
        myList->tail->nextNodePointer = newNode;
        myList->tail = newNode;
    }

    myList->counterVar++;
    
    return;    
}

void printListForward(List *myList) {
    Node *tempHead = myList->head;

    while (tempHead != NULL) {
        printf("Index: %i | Value: %i\n", 
            tempHead->data->storeIndex, tempHead->data->storeValue
        );
        
        tempHead = tempHead->nextNodePointer;
    }
    return;
}

void printListReverse(List *myList) {
    Node *tempTail = myList->tail;

    while (tempTail !=NULL) {
        printf("Index: %i | Value: %i\n", 
            tempTail->data->storeIndex, tempTail->data->storeValue
        );

        tempTail = tempTail->prevNodePointer;
    }
    return;
}

