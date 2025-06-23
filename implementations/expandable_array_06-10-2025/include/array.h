#include <stdlib.h>

#ifndef ARRAY
#define ARRAY

#define INITIAL_CAPACITY 10;

typedef struct
{
    int *items;
    int currentCapacity;
    int itemCount;
} Array;


void initArray(Array *myArray, int ititialCapacity);

void addToArray(Array *myArray, const int entry);

void printArray(Array *myArray);

void freeArray(Array *myArray);

#endif 