#include <stdio.h>
#include <string.h>

#define MAX 10

int main() {
    char productions[MAX][20] = {
        "Sab", // Left-recursive production
        "ab",  // Non-left-recursive production
        "a",   // Non-left-recursive production
        "b"    // Non-left-recursive production
    };

    char recursive[MAX][20];       // For storing left-recursive productions
    char non_recursive[MAX][20];   // For storing non-left-recursive productions
    int rec_count = 0, non_rec_count = 0;

    char variable = 'S'; // The start variable (S)

    printf("Original Grammar:\n");
    printf("S -> ");
    for (int i = 0; i < 4; i++) {
        printf("%s", productions[i]);
        if (i != 3) printf(" | ");
    }
    printf("\n");

    // Step 1: Identify left-recursive and non-left-recursive productions
    for (int i = 0; i < 4; i++) {
        if (productions[i][0] == variable) {
            // Left-recursive: productions starting with S
            strcpy(recursive[rec_count], productions[i] + 1); // Skip 'S'
            rec_count++;
        } else {
            // Non-left-recursive
            strcpy(non_recursive[non_rec_count], productions[i]);
            non_rec_count++;
        }
    }

    // Step 2: Print the left-recursive and non-left-recursive productions
    printf("Left-Recursive: ");
    for (int i = 0; i < rec_count; i++) {
        printf("S->S%s  ", recursive[i]);
    }

    printf("\nNon-Left-Recursive: ");
    for (int i = 0; i < non_rec_count; i++) {
        printf("S->%s  ", non_recursive[i]);
    }
    printf("\n");

    // Step 3: Removing Left Recursion
    printf("Transformed Grammar:\n");

    // Non-recursive part for S
    printf("S -> ");
    for (int i = 0; i < non_rec_count; i++) {
        printf("%sS' ", non_recursive[i]);
        if (i != non_rec_count - 1) {
            printf("| ");
        }
    }
    printf("\n");

    // Recursive part for S'
    printf("S' -> ");
    for (int i = 0; i < rec_count; i++) {
        printf("%sS' ", recursive[i]);
        if (i != rec_count - 1) {
            printf("| ");
        }
    }
    printf("| epsilon\n");  // Replace ε with 'epsilon' instead of Greek character

    return 0;
}
