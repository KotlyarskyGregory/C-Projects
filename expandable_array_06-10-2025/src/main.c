#include <stdio.h>
#include <stdlib.h>
#include "../include/array.h"

int main(void) {

    Array myArray;

    int initialCapacity = INITIAL_CAPACITY;

    initArray(&myArray,initialCapacity);

    for (int i = 0; i < 20; i++) {
        addToArray(&myArray, i);
    }

    printArray(&myArray);

    freeArray(&myArray);
    
}