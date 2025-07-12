#ifndef DATA_H
#define DATA_H

#include <time.h>

typedef struct Data 
{
    char *taskName;
    char *category;
    char *taskDescription;
    char *priority;
    time_t inputDate;
    time_t dueDate;

} Data;


Data* initData();

time_t getDueDate();

// void freeData();

#endif