#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../include/game.h"

// fuction to get random number
int getRandNum(void) {
    srand(time(NULL));
    int randNum = (rand() % 100) + 1;
    return randNum;
}

// function to get user input
int getUserInput(void) {
    int userInput;
    char extraValues;
    char buffer[100];

    while (1) {
        fgets(buffer, sizeof(buffer), stdin);
        
        if (sscanf(buffer, "%d %c", &userInput, &extraValues) == 1) {
            return userInput;
        } else {
            printf("Please enter a VALID integer between 1 and 100!\n");
        }
    }
}