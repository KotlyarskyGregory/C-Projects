#ifndef ARRAY_H
#define ARRAY_H

#include "../user_input/data.h"
#include "./doubly_linked_list.h"

#define INITIAL_CAPACITY 10;

typedef struct Array
{
    Data **entries;
    int currentCapacity;
    int itemCount;
    
} Array;

void initArray(Array *myArray, const int initialCapacity);

void addToArray(Array *myArray, Data *newDataInput);

void buildArray(Array *myArray, List *myList);

void printArray(Array *myArray);

void clearArray(Array *myAray);


#endif