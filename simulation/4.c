// 4. ) WAP to generate 50 random numbers using Mixed Congruential Method where X0=11, m=100, a = 5 and c = 13.

#include <stdio.h>

int main()
{
    int M = 100; // Modulus
    int a = 5;   // Multiplier
    int c = 13;  // Increment
    int X = 11;  // Seed (initial value)

    // Generate 50 random numbers
    for (int i = 0; i < 50; i++)
    {
        X = (a * X + c) % M; // Mixed Congruential Formula
        printf("%d ", X);    // Print the generated number
    }

    return 0;
}
