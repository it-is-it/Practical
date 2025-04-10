#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to simulate ε-NFA
bool simulateENFA(const char *input) {
    int len = strlen(input);

    // Accept only two-character strings
    if (len != 2)
        return false;

    // First character should be a or b
    if ((input[0] == 'a' || input[0] == 'b') &&
        (input[1] == 'a' || input[1] == 'b')) {
        return true;
    }

    return false;
}

int main() {
    char str[100];
    printf("Enter a string (only a and b allowed): ");
    scanf("%s", str);

    if (simulateENFA(str)) {
        printf("Accepted by NFA for (a+b)(a+b)\n");
    } else {
        printf("Rejected by NFA for (a+b)(a+b)\n");
    }

    return 0;
}
