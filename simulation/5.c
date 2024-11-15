#include <stdio.h>

int main()
{
    int M = 1000; // Modulus
    int a = 15;   // Multiplier
    int X = 13;   // Seed (initial value)

    // Generate 50 random numbers
    for (int i = 0; i < 50; i++)
    {
        X = (a * X) % M;  // Multiplicative Congruential Formula
        printf("%d ", X); // Print the generated number
    }

    return 0;
}
