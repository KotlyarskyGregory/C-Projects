#include <stdio.h>
#include <stdlib.h>
#include "../include/singly_linked_list.h"

void initList(List *list) {
    list->head = NULL;
    list->tail = NULL;
    list->inputsCounter = 0;
    return;
}

void addToTail(List *list, int input, int otherInput) {
    Node *newNode = (Node*) malloc(sizeof(*newNode));
    Data *newData = (Data*) malloc(sizeof(*newData));
    
    if (!newNode || !newData) {
        printf("Not able to allocate for new node or new data.\n");
        return;
    }

    newData->value = input;
    newData->otherValue = otherInput;
    newNode->data = newData;
    newNode->nextNodePointer = NULL;

    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail = newNode;
    }

    list->inputsCounter++;

    return;
}

void printList(List *list) {
    Node *tempHead = list->head;
    while (tempHead != NULL) {
        printf("%i %i\n", 
            tempHead->data->value, tempHead->data->otherValue
        );
        tempHead = tempHead->nextNodePointer;
    }
    printf("%i\n", list->inputsCounter);
}