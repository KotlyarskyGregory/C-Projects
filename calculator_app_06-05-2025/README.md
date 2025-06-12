1. Input & Parsing
    Prompt the user to enter an expression in the format:

    <number> <operator> <number>  
    e.g., 5 + 3
    Accept these operators: +, -, *, /, %

Validate input:

    Only one operator allowed.

    Check for valid numeric input.

    Handle divide/mod by zero.

2. Operations
    Perform the operation and print the result.

    Use int for % and double for the other operators.

    Allow decimal inputs when applicable.

3. History Management
    Store each valid operation and its result (e.g., "5 + 3 = 8") in memory.

    Use an array of strings (char history[100][100] is one option).

    Up to 100 operations can be stored.

4. Menu Options
    After each operation, display a menu:

    [1] Continue
    [2] View History
    [3] Exit

5. View History
    If the user selects option 2, print all stored history.

6. Exit
    Cleanly exit the program when the user chooses option 3.

    
    
    
🧠 Suggested Functions (Modular Design)
    void print_menu();

    int parse_input(char* input, double* num1, char* op, double* num2);

    double calculate(double num1, char op, double num2, int* error);

    void add_to_history(char history[][100], int* count, double num1, char op, double num2, double result);

    void print_history(char history[][100], int count);

    
    
🧪 Example Interaction

    Enter operation: 4 * 2
    Result: 8.00

    [1] Continue
    [2] View History
    [3] Exit
    > 1

    Enter operation: 10 / 0
    Error: Cannot divide by zero.

    [1] Continue
    [2] View History
    [3] Exit
    > 2

    History:
    4 * 2 = 8.00

    [1] Continue
    [2] View History
    [3] Exit
    > 3
    Goodbye!