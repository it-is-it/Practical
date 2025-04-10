#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PRODUCTIONS 100
#define MAX_SYMBOL_LENGTH 10

// Structure to store production rules
typedef struct {
    char left[MAX_SYMBOL_LENGTH];
    char right[MAX_SYMBOL_LENGTH];
} Production;

// Function to check if a symbol is a non-terminal
int isNonTerminal(char symbol) {
    return isupper(symbol); // Non-terminals are usually uppercase letters
}

// Function to extract non-terminals and terminals from the production rules
void extractCFG(FILE *file) {
    Production productions[MAX_PRODUCTIONS];
    int productionCount = 0;
    char line[100];

    // Sets to store non-terminals, terminals, and productions
    char nonTerminals[MAX_PRODUCTIONS] = {0};
    char terminals[MAX_PRODUCTIONS] = {0};
    
    // Read productions from the file
    while (fgets(line, sizeof(line), file)) {
        // Remove newline character from the line
        line[strcspn(line, "\n")] = '\0';

        // Parse the left side and right side of the production
        char left[MAX_SYMBOL_LENGTH], right[MAX_SYMBOL_LENGTH];
        sscanf(line, "%s → %s", left, right);

        // Store the production
        strcpy(productions[productionCount].left, left);
        strcpy(productions[productionCount].right, right);
        productionCount++;

        // Add non-terminals
        if (!strchr(nonTerminals, left[0])) {
            strncat(nonTerminals, left, 1);
        }

        // Add terminals and non-terminals
        for (int i = 0; i < strlen(right); i++) {
            if (isNonTerminal(right[i]) && !strchr(nonTerminals, right[i])) {
                strncat(nonTerminals, &right[i], 1);
            } else if (!isNonTerminal(right[i]) && !strchr(terminals, right[i])) {
                strncat(terminals, &right[i], 1);
            }
        }
    }

    // Print the results
    printf("Set of non-terminals = {");
    for (int i = 0; i < strlen(nonTerminals); i++) {
        printf("%c", nonTerminals[i]);
        if (i < strlen(nonTerminals) - 1) {
            printf(", ");
        }
    }
    printf("}\n");

    printf("Set of terminals = {");
    for (int i = 0; i < strlen(terminals); i++) {
        printf("%c", terminals[i]);
        if (i < strlen(terminals) - 1) {
            printf(", ");
        }
    }
    printf("}\n");

    printf("Set of productions = {");
    for (int i = 0; i < productionCount; i++) {
        printf("%s -> %s", productions[i].left, productions[i].right);
        if (i < productionCount - 1) {
            printf(", ");
        }
    }
    printf("}\n");

    // Assuming the starting symbol is the first non-terminal in the list
    printf("Starting symbol = {%c}\n", nonTerminals[0]);
}

int main() {
    // Open the file containing the CFG
    FILE *file = fopen("cfg.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // Extract and display the CFG information
    extractCFG(file);

    // Close the file
    fclose(file);

    return 0;
}
