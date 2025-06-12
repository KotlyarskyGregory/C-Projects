#ifndef PARSER
#define PARSER

typedef struct {
    double firstTerm;
    double secondTerm;
    char operand;
    int shouldExit;
    int displayHistory;
} ParsedExpression;

ParsedExpression parseInput(void);



#endif