#include <stdio.h>
#include <stdlib.h>

#include "../include/array.h"
#include "../include/data.h"


void initArray(Array *myArray, const int initialCapacity) {
    myArray->entries = malloc(sizeof(Data*) * initialCapacity);
    if (myArray->entries == NULL) {
        printf("Error in array initial memory allocation.\n");
        
        return;
    }

    myArray->currentCapacity = initialCapacity;
    myArray->itemCount = 0;
    
    return;
}

void addToArray(Array *myArray, Data *newDataInput) {
    if (myArray->itemCount == myArray->currentCapacity) {
        Data **temp = realloc(myArray->entries, sizeof(Data*) * myArray->currentCapacity * 2);
        if (temp == NULL) {
            printf("Error in array memory reallocation\n");
            
            return;
        }
        myArray->entries = temp;
        myArray->currentCapacity *= 2;
    }

    myArray->entries[myArray->itemCount] = newDataInput;
    myArray->itemCount++;
    
    return;
}

void buildArray(Array *myArray, List *myList) {
    if (myArray->itemCount == myArray->currentCapacity) {
        Data **temp = realloc(myArray->entries, sizeof(Data*) * myArray->currentCapacity * 2);
        if (temp == NULL) {
            printf("Error in reallocating memory to array\n");
            
            return;
        }
        myArray->entries = temp;
        myArray->currentCapacity *= 2;
    }

    Node *tempNode = myList->head;

    int i = 0;
    while (tempNode != NULL) {
        myArray->entries[i] = tempNode->data;
        tempNode = tempNode->pointerNextNode;
        myArray->itemCount++;
        i++;
    }

    return;
}

void printArray(Array *myArray) {
    for (int i = 0; i < myArray->itemCount; i++) {
        printData(myArray->entries[i]);
    }
    
    return;
}

void clearArray(Array *myArray) { //TODO: figure out why now working right, double free.
    for (int i = 0; i < myArray->itemCount; i++) {
        free(myArray->entries);
    }
    
    return;
}

