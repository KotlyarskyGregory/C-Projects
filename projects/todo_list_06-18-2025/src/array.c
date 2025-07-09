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
