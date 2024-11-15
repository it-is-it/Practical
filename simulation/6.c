#include <stdio.h>
#include <math.h>

int getNumberOfDigits(int num)
{
    return num == 0 ? 1 : (int)log10(num) + 1;
}

int midSquareMethod(int seed)
{
    long long squared = (long long)seed * seed;                                       // Square the seed
    int seedDigits = getNumberOfDigits(seed);                                         // Get the number of digits in the seed
    int squaredDigits = getNumberOfDigits(squared);                                   // Get the number of digits in the squared value
    int midStart = (squaredDigits / 2) - (seedDigits / 2);                            // Calculate starting position of middle digits
    int middleDigits = (squared / (int)pow(10, midStart)) % (int)pow(10, seedDigits); // Extract middle digits
    return middleDigits;
}

int main()
{
    int seed, n;
    printf("Enter the initial seed: ");
    scanf("%d", &seed);
    printf("Enter the number of random numbers to generate: ");
    scanf("%d", &n);

    printf("Generated random numbers:\n");
    for (int i = 0; i < n; i++)
    {
        seed = midSquareMethod(seed); // Generate next number using mid-square method
        printf("%d\n", seed);
    }

    return 0;
}
