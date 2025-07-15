#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

#include "../include/data.h"

// function to get dueDate
time_t getDueDate() {
    
    time_t resultDueDate;

    struct tm timeStruct = {0};

    while (1) 
    {
        char buffer[100];
        int month, day, year, hour, minute;
        int valid = 1;
        char extra;
        
        printf("Please enter a due date and optional 24h time without any trailing spaces(mm/dd/yyyy hh:mm):\n");
        
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        
        int count = sscanf(buffer, "%d/%d/%d %d:%d%c ", &month, &day, &year, &hour, &minute, &extra);
        
        if (count != 3 && count != 5) {
            printf("Input must be optional 24h time (mm/dd/yyyy hh:mm) with no trailing spaces.\n");
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

        if (count == 5) {
            if (minute < 0 || minute > 59) {
                printf("Minute values must be between 0 and 59.\n");
                valid = 0;
            }

            if (hour < 0 || hour > 23) {
                printf("Hour values must be between 0 and 23.\n");
                valid = 0;
            }

            timeStruct.tm_min = minute;
            timeStruct.tm_hour = hour;
        } else if (count == 3) {
            timeStruct.tm_sec = 59;
            timeStruct.tm_min = 59;
            timeStruct.tm_hour = 23;
            
        }

        timeStruct.tm_mday = day;
        timeStruct.tm_mon = month - 1;
        timeStruct.tm_year = year - 1900;
        timeStruct.tm_isdst = -1;

        time_t currentTime;
        
        time(&currentTime);
        
        resultDueDate = mktime(&timeStruct);

        if (resultDueDate == -1) {
            printf("Error converting time.\n");
            valid = 0;
        }        

        if (resultDueDate < currentTime) {
            printf("Cannot put a datetime that already passed.\n");
            valid = 0;
        }

        if (valid == 0) {
            continue;
        } else {
            printf("-----------------------------------------------------\n");
            break;
        }
    }
    
    return resultDueDate;
}

// function to get task name
char *getTaskName() {
    char buffer[100];
    
    printf("Please put in the task name: \n");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    char *taskName = malloc(strlen(buffer) + 1);
    strcpy(taskName, buffer);

    return taskName;
}

// function to get task category
char *getTaskCategory() {
    char buffer[100];
    
    printf("Please put in the task catogory: \n");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    char *category = malloc(strlen(buffer) + 1);
    strcpy(category, buffer);

    return category;
}

// function to get task description
char *getTaskDescription() {
    char buffer[100];
    
    printf("Please put in a task description: \n");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    char *taskDescription = malloc(strlen(buffer) + 1);
    strcpy(taskDescription, buffer);
    
    return taskDescription;
}

// function to get task priority
char *getTaskPriority() {
    char buffer[100];

    while (1)
    {
        printf("Please put in a priotity (high, medium, low): \n");
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        
        for (long unsigned int i = 0; i < strlen(buffer); i++) {
            buffer[i] = tolower(buffer[i]);
        }
        
        if (!strcmp(buffer, "high") || !strcmp(buffer, "medium") || !strcmp(buffer, "low")) {
            char *priority = malloc(strlen(buffer) + 1);
            strcpy(priority, buffer);
            
            return priority;
        } else {
            printf("That is not a valid priority.\n");
        }

    }

    printf("Error in get priority funciton.\n");
    return NULL;
}