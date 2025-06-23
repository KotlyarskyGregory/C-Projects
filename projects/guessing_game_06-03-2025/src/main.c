#include <stdio.h>
#include <stdbool.h>
#include "../include/game.h"

int main() {
    printf("Welcome to the guessing game!\n");
    printf("\n");
    
    int challengeNumber = getRandNum();
    int currentGuess;
    int guessesNumber = 0;
    
    while (1) {
        printf("Input a number between 1 and 100. %d\n", challengeNumber);
        guessesNumber++;
        currentGuess = getUserInput();

        if (currentGuess == challengeNumber) {
            printf("You won the game, congradulations!\n");
            printf("You got the answer in %d guesses!\n", guessesNumber);
            return 0;
        } else if (currentGuess < 1 || currentGuess > 100) {
            printf("Your guess is not within the valid range\n");
        } else if (currentGuess > challengeNumber) {
            printf("Your guess is too high\n");
        } else if (currentGuess < challengeNumber) {
            printf("Your guess is too low\n");
        } else {
            printf("You did something wrong.\n");
        }
    }
}
