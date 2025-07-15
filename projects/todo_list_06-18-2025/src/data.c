#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#include "../include/data.h"
#include"../include/data_functions.h"

Data* initData() {
    Data *newDataInput = malloc(sizeof(Data));

    if (newDataInput == NULL) {
        printf("Memory to new data input not allocated.\n");
        return NULL;
    }

    // Getting task name
    newDataInput->taskName = getTaskName();

    // Getting task category
    newDataInput->category = getTaskCategory();

    // Getting task description
    newDataInput->taskDescription= getTaskDescription();

    // Getting priority
    newDataInput->priority = getTaskPriority();

    // User input due date
    newDataInput->dueDate = getDueDate();

    // Automatically enter input date
    time(&newDataInput->inputDate);

    return newDataInput;
}


void printData(Data *myData) {
    printf("-----------------------------------------------------\n");
    printf("Task name: %s\n", myData->taskName);
    printf("Task category: %s\n", myData->category);
    printf("Task description: %s\n", myData->taskDescription);
    printf("Task priority: %s\n", myData->priority);
    printf("Task input date: %s", ctime(&myData->inputDate));
    printf("Task due date: %s", ctime(&myData->dueDate));
    printf("-----------------------------------------------------\n");

    return;
}

//function to free data
void freeData(Data *myData) {
    Data *removeData = myData;
    
    free(removeData->taskName);
    free(removeData->category);
    free(removeData->taskDescription);
    free(removeData->priority);
    free(removeData);
    return;
}