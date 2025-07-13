#include <stdio.h>
#include <time.h>

#include "../include/data.h"
#include "../include/doubly_linked_list.h"
#include "../include/array.h"

int main(void) {
    printf("Hello world\n");

    List myList;
    //Array myArray;

    //int initialCapacity = INITIAL_CAPACITY;

    initList(&myList);
    //initArray(&myArray, initialCapacity);


    addToTail(&myList);
    addToTail(&myList);

    //buildArray(&myArray, &myList);
    //printArray(&myArray);
    
    clearList(&myList);

    printf("Got to here\n");

    //clearArray(&myArray); 

    printf("Success\n");

}