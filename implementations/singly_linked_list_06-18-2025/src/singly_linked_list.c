#include <stdio.h>
#include <stdlib.h>
#include "../include/singly_linked_list.h"

// Function to initialize list
void initList(List *myList) {
    myList->head = NULL;
    myList->tail = NULL;
    myList->nodeCounter = 0;
    return;
}

// Function to add to tail
void addToTail (List *myList, int varOne, int varTwo) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    Data *newData = (Data*) malloc (sizeof(Data));

    newData->inputOne = varOne;
    newData->inputTwo = varTwo;
    newNode->data = newData;
    newNode->pointerNextNode = NULL;

    if (myList->head == NULL) {
        myList->head = newNode;
        myList->tail = newNode;
    } else {
        myList->tail->pointerNextNode = newNode;
        myList->tail = newNode;
    }

    myList->nodeCounter++;
    
    return;
}

// Function to print list
void printList(List *myList) {
    Node *tempHead = myList->head;

    while (tempHead != NULL) {
        printf("Input one: %d, Input 2: %d\n", 
            tempHead->data->inputOne,
            tempHead->data->inputTwo
        );
        tempHead = tempHead->pointerNextNode;
    }
}