#include <stdio.h>
#include <ctype.h>
#include <string.h>

enum State {q0, q1, q2}; // Define DFA states

// Function to check if the string is a valid C variable name
int isValidVariableName(char *str) {
    enum State currentState = q0; // Start at state q0
    int i = 0;

    // Loop through each character of the input string
    while (str[i] != '\0') {
        char ch = str[i];
        
        switch (currentState) {
            case q0: // Check if the first character is valid
                if (isalpha(ch) || ch == '_') {
                    currentState = q1; // Move to q1 (valid state)
                } else {
                    currentState = q2; // Move to q2 (reject state)
                }
                break;
            case q1: // After first valid character, accept letters, digits, and underscores
                if (isalnum(ch) || ch == '_') {
                    currentState = q1; // Stay in q1 (valid state)
                } else {
                    currentState = q2; // Move to q2 (reject state)
                }
                break;
            case q2: // Once in reject state, stay in reject state
                return 0; // Reject immediately
        }
        i++;
    }

    // If we end in q1, it's a valid variable name
    if (currentState == q1) {
        return 1; // Valid variable name
    } 
    return 0; // Invalid variable name
}

int main() {
    char variableName[100];
    
    printf("Enter a variable name: ");
    scanf("%s", variableName);

    // Check if the variable name is valid
    if (isValidVariableName(variableName)) {
        printf("Valid variable name: %s\n", variableName);
    } else {
        printf("Invalid variable name: %s\n", variableName);
    }

    return 0;
}
