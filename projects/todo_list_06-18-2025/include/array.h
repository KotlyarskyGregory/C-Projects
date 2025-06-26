#ifndef ARRAY_H
#define ARRAY_H

#include "data.h"

#define INITIAL_CAPACITY 10;

typedef struct Array
{
    Data **data;
    int currentCapacity;
    int itemCount;
    
} Array;

void initArray(Array *myArray, const int initialCapacity);

void addToArray(Array *myArray, Data *myData);


#endif