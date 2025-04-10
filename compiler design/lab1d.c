#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isValidNTCNumber(const char *number) {
    int len = strlen(number);
    int i = 0;

    // Check length: Should be exactly 10 digits
    if (len != 10) return false;

    // DFA states simulation
    enum State { q0, q1, q2, q_reject };
    enum State state = q0;

    while (number[i] != '\0') {
        char ch = number[i];

        switch (state) {
            case q0:
                if (ch == '9') {
                    state = q1;
                } else {
                    state = q_reject;
                }
                break;

            case q1:
                if (ch == '8') {
                    state = q2;
                } else {
                    state = q_reject;
                }
                break;

            case q2:
                if (ch >= '0' && ch <= '9') {
                    state = q2; // Stay in q2 for valid digits
                } else {
                    state = q_reject;
                }
                break;

            case q_reject:
                return false; // Rejected early
        }

        i++;
    }

    // Accept only if the final state is q2 (after 10 valid digits)
    return state == q2;
}

int main() {
    char number[100];
    printf("Enter a prepaid NTC number: ");
    scanf("%s", number);

    if (isValidNTCNumber(number)) {
        printf("Valid Prepaid NTC Number.\n");
    } else {
        printf("Invalid Prepaid NTC Number.\n");
    }

    return 0;
}

