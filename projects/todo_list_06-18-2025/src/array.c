#include <stdio.h>
#include <stdlib.h>
#include "../include/array.h"
#include "../include/data.h"


void initArray(Array *myArray, const int initialCapacity) {
    myArray->data = (Data**) malloc(sizeof(Data*) * initialCapacity);
    if (myArray->data == NULL) {
        printf("Error in array initial memory allocation.\n");
        return;
    }

    myArray->currentCapacity = initialCapacity;
    myArray->itemCount = 0;
    
    return;
}

void addToArray(Array *myArray, Data *newData) {
    if (myArray->itemCount == myArray->currentCapacity) {
        myArray->data = (Data**) realloc(myArray->data, sizeof(Data*) * myArray->currentCapacity * 2);
        if (myArray->data == NULL) {
            printf("Error in array memory reallocation\n");
        }
    }

    myArray->data[myArray->itemCount] = newData;
    myArray->itemCount++;
    return;
}
