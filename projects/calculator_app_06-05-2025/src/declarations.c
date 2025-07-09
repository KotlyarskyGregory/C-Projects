#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "../include/operations_declaration.h"
#include "../include/parser.h"


ParsedExpression parseInput(void) {

    ParsedExpression expression;
    char buffer[100];
    char extra;

    while(1) {
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';

        if (strcmp(buffer, "END") == 0) {
            expression.shouldExit = 1;
            return expression;
        }

        if (strcmp(buffer, "H") == 0) {
            expression.displayHistory = 1;
            return expression;
        }
        
        if (sscanf(buffer, "%lf %c %lf %c", 
            &expression.firstTerm, 
            &expression.operand, 
            &expression.secondTerm, 
            &extra) != 3) {
            printf("That is not a viable input.\n");
        } else if (expression.operand != '+' &&
                   expression.operand != '-' &&
                   expression.operand != '*' &&
                   expression.operand != '/' &&
                   expression.operand != '%') {     
            printf("That is not a viable input.\n");
        } else if(expression.operand == '/' && expression.secondTerm == 0){
            printf("Cannot divide by zero.\n");
        } else if (expression.operand == '%' && expression.secondTerm == 0) {
            printf("Cannot modulus by zero\n");
        } else {
            return expression;
        }
    }
}

double outputValue(const ParsedExpression expression) {
    double output;

    if (expression.operand == '+') {
        output = expression.firstTerm + expression.secondTerm;
    } else if (expression.operand == '-') {
        output = expression.firstTerm - expression.secondTerm;
    } else if (expression.operand == '*') {
        output = expression.firstTerm * expression.secondTerm;
    } else if (expression.operand == '/') {
        output = expression.firstTerm / expression.secondTerm;
    } else if (expression.operand == '%') {
        output = fmod(expression.firstTerm, expression.secondTerm);
    }

    return output;
}