#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/data.h"

Data* initData() {
    Data *newDataInput = malloc(sizeof(Data));
    char buffer[10000];

    if (newDataInput == NULL) {
        printf("Memory to new data input not allocated\n");
        return NULL;
    }

    // Getting task name
    printf("Please put in the task name: \n");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    newDataInput->taskName = malloc(strlen(buffer) + 1);
    strcpy(newDataInput->taskName, buffer);

    // Getting task category
    printf("Please put in the task catogory: \n");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    newDataInput->category = malloc(strlen(buffer) + 1);
    strcpy(newDataInput->category, buffer);

    // Getting task description
    printf("Please put in a task description: \n");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    newDataInput->taskDescription = malloc(strlen(buffer) + 1);
    strcpy(newDataInput->taskDescription, buffer);

    // Getting priority
    while (1)
    {
        printf("Please put in a priotity (high, medium, low): \n");
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        
        for (long unsigned int i = 0; i < strlen(buffer); i++) {
            buffer[i] = tolower(buffer[i]);
        }
        
        if (!strcmp(buffer, "high") || !strcmp(buffer, "medium") || !strcmp(buffer, "low")) {
            newDataInput->priority = malloc(strlen(buffer) + 1);
            strcpy(newDataInput->priority, buffer);
            break;
        } else {
            printf("That is not a valid priority \n");
        }

    }

    // User input due date
    while (1) 
    {
        printf("Please enter a due date (mm/dd/yyyy):");

    }

    // Automatically enter input date
    time(&newDataInput->inputDate);

    return newDataInput;

}