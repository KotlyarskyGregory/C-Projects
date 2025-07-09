#include <stdio.h>
#include <time.h>

#include "../include/data.h"

int main(void) {
    printf("Hello world\n");

    Data *output = initData();

    printf("%s\n" , output->taskName);
    printf("%s\n" , output->category);
    printf("%s\n" , output->taskDescription);
}