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
        int month, day, year, hour, minute;
        int valid = 1;
        char extra;
        
        printf("Please enter a due date and 24h time without any trailing spaces(mm/dd/yyyy hh:mm):\n");
        
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        
        int count = sscanf(buffer, "%d/%d/%d %d:%d%c ", &month, &day, &year, &hour, &minute, &extra);
        
        if (count != 5) {
            printf("Input must be 24h time (mm/dd/yyyy hh:mm) with no trailing spaces.\n");
            printf("Count: %d\n", count);
            valid = 0;
        }
        
        if (month < 1 || month > 12) {
            printf("The month must be between 1-12.\n");
            valid = 0;
        } else if ((month == 4 || month == 6 || month == 9 || month == 11) && (day > 30)) {
            printf("Inputed month cannot have more than 30 days.\n");
            valid = 0;
        } else if ((month == 2 && (year % 4 != 0)) && day > 28) {
            printf("February cannot have more than 28 days on a normal year.\n");
            valid = 0;
        } else if (month == 2 && (year % 4 == 0) && day > 29) {
            printf("February cannot have more than 29 days on a leap year.\n");
            valid = 0;
        } else if (day < 1 || day > 31) {
            printf("No month can have more than 31 days or less than 0 days.\n");
            valid = 0;
        }

        if (minute < 0 || minute > 59) {
            printf("Minute values must be between 0 and 59.\n");
            valid = 0;
        }

        if (hour < 0 || hour > 23) {
            printf("Hour values must be between 0 and 23.\n");
            valid = 0;
        }

        struct tm timeStruct = {0};

        timeStruct.tm_min = minute;
        timeStruct.tm_hour = hour;
        timeStruct.tm_mday = day;
        timeStruct.tm_mon = month - 1;
        timeStruct.tm_year = year - 1900;
        timeStruct.tm_isdst = -1;

        time_t currentTime;
        time(&currentTime);
        
        time_t resultDueDate = mktime(&timeStruct);

        if (resultDueDate == -1) {
            printf("Error converting time.\n");
            valid = 0;
        }        

        if (resultDueDate < currentTime) {
            printf("Cannot put a datetime that already passed\n");
            valid = 0;
        }

        if (valid == 0) {
            continue;
        } else {
            printf("Date accepted.\n");
            break;
        }
    }

    // Automatically enter input date
    time(&newDataInput->inputDate);

    return newDataInput;

}