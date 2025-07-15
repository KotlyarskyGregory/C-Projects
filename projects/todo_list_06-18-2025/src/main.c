#include <stdio.h>

#include "../include/data_structures/array.h"
#include "../include/data_structures/doubly_linked_list.h"
#include "../include/data_structures/array.h"

int main(void) {
    List myList;
    initList(&myList);

    addToTail(&myList);
    
    Array myArray;
    int initialCapacity = INITIAL_CAPACITY;    
    initArray(&myArray, initialCapacity);
    buildArray(&myArray, &myList);    
    printArray(&myArray);
    
    clearArray(&myArray); 

    clearList(&myList);


    return 0;
}