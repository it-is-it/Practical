#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to simulate NFA
bool nfaAccepts(const char *str) {
    int len = strlen(str);

    if (len == 0) {
        return false;  // Empty string is not accepted
    }

    // We check if the last character is 'a'
    if (str[len - 1] == 'a') {
        // Valid input: (a + b)*a
        for (int i = 0; i < len; i++) {
            if (str[i] != 'a' && str[i] != 'b') {
                return false; // Invalid character
            }
        }
        return true;
    }

    return false;  // Does not end with 'a'
}

int main() {
    char input[100];

    printf("Enter a string of a's and b's: ");
    scanf("%s", input);

    if (nfaAccepts(input)) {
        printf("Accepted by NFA.\n");
    } else {
        printf("Rejected by NFA.\n");
    }

    return 0;
}
