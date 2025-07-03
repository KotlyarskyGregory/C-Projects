#ifndef DATA_H
#define DATA_H

#include <time.h>

#define PRIORITY_LOW 0
#define PRIOTIRY_MEDIUM 1
#define PRIOTIRY_HIGH 2

typedef struct Data 
{
    char *taskName;
    char *category;
    char *taskDescription;
    time_t inputDate;
    time_t dueDate;
    int priority;

} Data;

void getFields();

void initData();

void freeData();

#endif