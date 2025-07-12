#include <stdio.h>
#include <time.h>

#include "../include/data.h"

int main(void) {
    printf("Hello world\n");

    Data *output = initData();

    printf("\n");
    printf("Task name: %s\n", output->taskName);
    printf("Task category: %s\n", output->category);
    printf("Task description: %s\n", output->taskDescription);
    printf("Task priority: %s\n", output->priority);
    printf("Task input date: %s", ctime(&output->inputDate));
    printf("Task due date: %s", ctime(&output->dueDate));

    freeData(output);

}