#include <stdio.h>
#include <stdlib.h>

#include "../../include/data_structures/doubly_linked_list.h"
#include "../../include/user_input/data.h"

void initList(List *myList) {
    myList->head = NULL;
    myList->tail = NULL;
    myList->counterVar = 0;    
    
    return;
}

void addToTail(List *myList) {
    Node *newNode = malloc(sizeof(Node));

    if (!newNode) {
        printf("Memory allocation to new node/data failed.\n");
        return;
    }

    Data *newData = initData();
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

void removeNode(List *myList, Node *removeNode) {
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
    
    freeData(tempNode->data);
    free(tempNode);

    myList->counterVar--;

    return;
}

void printList(List *myList) {

    Node *tempHead = myList->head;

    while (tempHead != NULL) {
        printData(tempHead->data);

        tempHead = tempHead->pointerNextNode;
    }

    return;
}

void clearList(List *myList) {
    if (!myList->head || !myList->tail) {
        printf("List is already empty\n");
        return;
    }

    Node *tempHead = myList->head;
    
    while(tempHead != NULL) {
            Node *tempHeadNext = tempHead->pointerNextNode;
            freeData(tempHead->data);
            free(tempHead);
            tempHead = tempHeadNext;
    }

    myList->head = NULL;
    myList->tail = NULL;
    myList->counterVar = 0;
    
    
    return;
}

