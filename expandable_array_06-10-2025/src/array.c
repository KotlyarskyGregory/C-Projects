#include <stdlib.h>
#include <stdio.h>
#include "../include/array.h"

void initArray(Array *myArray, int initialCapacity) {
    myArray->items = malloc(sizeof(int) * initialCapacity);
    myArray->currentCapacity = initialCapacity;
    myArray->itemCount = 0;
    return;
}

void addToArray(Array *myArray, const int entry) {
    if (myArray->itemCount == myArray->currentCapacity) {
        myArray->items = realloc(myArray->items, sizeof(int) * myArray->currentCapacity * 2);
        myArray->currentCapacity *= 2;
    }
    
    myArray->items[myArray->itemCount] = entry;
    myArray->itemCount++;
    
    return;
}

void printArray(Array *myArray) {
    for (int i = 0; i < myArray->itemCount; i++) {
        printf("%d, ", myArray->items[i]);
    }
    printf("\n");
    return;
}

void freeArray(Array *myArray) {
    free(myArray->items);
    return;
}