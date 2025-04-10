#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

bool isValidGmailID(const char *email) {
    int i = 0;

    // Step 1: Validate username part
    if (!isalnum(email[i])) return false; // Username must start with letter/digit

    while (email[i] != '\0' && email[i] != '@') {
        char ch = email[i];
        if (!(isalnum(ch) || ch == '.' || ch == '_')) {
            return false; // Invalid character in username
        }
        i++;
    }

    if (email[i] != '@') return false; // '@' not found
    i++; // move past '@'

    // Step 2: Match 'gmail.com'
    const char *domain = "gmail.com";
    int j = 0;

    while (domain[j] != '\0' && email[i] != '\0') {
        if (email[i] != domain[j]) {
            return false;
        }
        i++;
        j++;
    }

    if (domain[j] == '\0' && email[i] == '\0') {
        return true; // Accepted
    }

    return false; // Extra characters after gmail.com
}

int main() {
    char email[100];
    printf("Enter a Gmail ID: ");
    scanf("%s", email);

    if (isValidGmailID(email)) {
        printf("Valid Gmail ID.\n");
    } else {
        printf("Invalid Gmail ID.\n");
    }

    return 0;
}
