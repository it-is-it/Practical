#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    int i = 0;
    char ch;
    enum { q0, q1, q2, q3 } state; // DFA states
    state = q0;

    printf("Enter a binary string: ");
    scanf("%s", input);

    // Check if input contains only 0s and 1s
    for (int j = 0; input[j] != '\0'; j++) {
        if (input[j] != '0' && input[j] != '1') {
            printf("Invalid input. Please enter a binary string (0s and 1s only).\n");
            return 1;
        }
    }

    printf("\nDFA Simulation:\n");

    while ((ch = input[i]) != '\0') {
        switch (state) {
            case q0:
                if (ch == '0') {
                    state = q1;
                    printf("q0 --0--> q1\n");
                } else {
                    state = q3; // trap state
                    printf("q0 --1--> q3 (trap)\n");
                }
                break;

            case q1:
                if (ch == '0') {
                    state = q1;
                    printf("q1 --0--> q1\n");
                } else {
                    state = q2;
                    printf("q1 --1--> q2\n");
                }
                break;

            case q2:
                if (ch == '0') {
                    state = q1;
                    printf("q2 --0--> q1\n");
                } else {
                    state = q2;
                    printf("q2 --1--> q2\n");
                }
                break;

            case q3:
                printf("q3 --%c--> q3 (trap)\n", ch);
                break;
        }
        i++;
    }

    if (state == q2) {
        printf("\nAccepted: The string starts with 0 and ends with 1.\n");
    } else {
        printf("\nRejected: The string does not start with 0 and end with 1.\n");
    }

    return 0;
}
