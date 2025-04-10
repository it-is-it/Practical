#include <stdio.h>
#include <string.h>

#define MAX_VARS 10

// Define a structure to store information about a variable
struct SymbolTable {
    char varName[20];
    char varType[20];
    float varValue;  // Can store both integer and float values
    int address;     // Memory address (simulated with an integer)
};

int main() {
    // Declare an array of SymbolTable structures to hold data
    struct SymbolTable symbolTable[MAX_VARS];
    int numVars = 0;  // Number of variables to be entered

    // Input the number of variables
    printf("Enter number of variables: ");
    scanf("%d", &numVars);
    getchar();  // Clear the newline character left by scanf

    // Input information for each variable
    for (int i = 0; i < numVars; i++) {
        printf("\nEnter details for variable %d:\n", i + 1);
        printf("Variable Name: ");
        scanf("%s", symbolTable[i].varName);
        getchar();  // Clear the newline character after string input
        
        printf("Variable Type (int/float): ");
        scanf("%s", symbolTable[i].varType);
        getchar();  // Clear the newline character after string input

        // Input variable value (for simplicity, assuming only integer and float values)
        printf("Variable Value: ");
        if (strcmp(symbolTable[i].varType, "int") == 0) {
            int value;
            scanf("%d", &value);
            symbolTable[i].varValue = (float)value;  // Store as float
        } else if (strcmp(symbolTable[i].varType, "float") == 0) {
            float value;
            scanf("%f", &value);
            symbolTable[i].varValue = value;
        }
        
        // Assign a simulated address (e.g., starting from 100 and increasing by 100)
        symbolTable[i].address = 100 * (i + 1);
    }

    // Display the symbol table
    printf("\nSymbol Table:\n");
    printf("-------------------------------------------------\n");
    printf("%-15s %-15s %-15s %-15s\n", "Variable Name", "Type", "Value", "Address");
    printf("-------------------------------------------------\n");
    
    for (int i = 0; i < numVars; i++) {
        printf("%-15s %-15s %-15.2f %-15d\n", symbolTable[i].varName, 
               symbolTable[i].varType, symbolTable[i].varValue, symbolTable[i].address);
    }

    return 0;
}
