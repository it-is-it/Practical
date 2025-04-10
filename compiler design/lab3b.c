#include <stdio.h>
#include <string.h>

#define MAX 10

int main() {
    // Grammar: A → A0 | A1 | 0
    char productions[MAX][20] = {
        "A0", // Left-recursive production
        "A1", // Left-recursive production
        "0"   // Non-left-recursive production
    };

    char recursive[MAX][20];       // For storing left-recursive productions
    char non_recursive[MAX][20];   // For storing non-left-recursive productions
    int rec_count = 0, non_rec_count = 0;

    char variable = 'A'; // The start variable (A)

    // Print the original grammar
    printf("Original Grammar:\n");
    printf("A -> ");
    for (int i = 0; i < 3; i++) {
        printf("%s", productions[i]);
        if (i != 2) printf(" | ");
    }
    printf("\n");

    // Step 1: Identify left-recursive and non-left-recursive productions
    for (int i = 0; i < 3; i++) {
        if (productions[i][0] == variable) {
            // Left-recursive: productions starting with A
            strcpy(recursive[rec_count], productions[i] + 1); // Skip 'A'
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
        printf("A->A%s  ", recursive[i]);
    }

    printf("\nNon-Left-Recursive: ");
    for (int i = 0; i < non_rec_count; i++) {
        printf("A->%s  ", non_recursive[i]);
    }
    printf("\n");

    // Step 3: Removing Left Recursion
    printf("Transformed Grammar:\n");

    // Non-recursive part for A
    printf("A -> ");
    for (int i = 0; i < non_rec_count; i++) {
        printf("%sA' ", non_recursive[i]);
        if (i != non_rec_count - 1) {
            printf("| ");
        }
    }
    printf("\n");

    // Recursive part for A'
    printf("A' -> ");
    for (int i = 0; i < rec_count; i++) {
        printf("%sA' ", recursive[i]);
        if (i != rec_count - 1) {
            printf("| ");
        }
    }
    printf("| epsilon\n");

    return 0;
}
