#include <stdio.h>
#include <stdlib.h>
#include "../include/operations_declaration.h"
#include "../include/parser.h"
#include "../include/history.h"

int main(void) {
    
    History history;
    int initialCapacity = INITIAL_CAPACITY;
    
    initHistory(&history, initialCapacity);

    while (1) {        
        printf("Enter an arithmetic operation " 
            "(END to quit)(H to display history):\n"
        );
        
        ParsedExpression exp = parseInput();        

        if (exp.shouldExit == 1) {
            printf("The calculator has terminated\n.");
            return 0;
        }

        if (exp.displayHistory == 1) {
            getHistory(&history);
            printf("\n");
            continue;
        }

        float answer = outputValue(exp);

        
        int length = snprintf(NULL, 0, "%g %c %g = %g\n",
            exp.firstTerm, exp.operand, exp.secondTerm, answer);
        
        char *buffer = malloc(length + 1);
        sprintf(buffer, "%g %c %g = %g\n",
            exp.firstTerm, exp.operand, exp.secondTerm, answer);

        addToHistory(&history, buffer);

        printf("%s", buffer);
        printf("\n");

        free(buffer);
    }

    freeHistory(&history);

    return 0;
}
