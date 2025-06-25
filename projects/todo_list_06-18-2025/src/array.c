#include <stdio.h>
#include <stdlib.h>
#include "../include/array.h"


void initArray(Array *myArray, const int initialCapacity) {
    myArray->data = (Data*) malloc(sizeof(Data) * initialCapacity);
    if (myArray->data == NULL) {
        printf("Error in allocating memory to data.\n");
        return;
    }

    myArray->currentCapacity = initialCapacity;
    myArray->itemCount = 0;
    
    return;
}

void addToArray(Array *myArray, Data *myData) {

    return;
}