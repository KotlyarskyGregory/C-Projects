#include <stdio.h>

int main(void) {
    char buffer[10];
    int userInput;
    printf("Enter and integer: \n");

    fgets(buffer, sizeof(buffer), stdin);

    sscanf(buffer, "%d", &userInput);

    int currentNumber = 0;
    int previousNumber = 0;
    int sum = 1;

    for (int i = 0; i < userInput; i++) {
        printf("Number %d: %d\n", i + 1, sum);
        previousNumber = currentNumber;
        currentNumber = sum;
        sum = currentNumber + previousNumber;
    }
}