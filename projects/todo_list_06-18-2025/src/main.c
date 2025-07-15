#include <stdio.h>
#include <time.h>

#include "../include/data.h"
#include "../include/doubly_linked_list.h"
#include "../include/array.h"

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