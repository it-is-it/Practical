#include <stdio.h>
#include <string.h>
#include <math.h>

// Function to perform the Poker Test
void pokerTest(char *sequence, int patternLength)
{
    int n = strlen(sequence);             // Length of the binary sequence
    int numPatterns = 1 << patternLength; // Number of possible patterns (2^patternLength)
    int counts[numPatterns];              // Array to hold counts of each pattern
    memset(counts, 0, sizeof(counts));    // Initialize counts to zero

    // Count the occurrences of each pattern in the sequence
    for (int i = 0; i <= n - patternLength; i++)
    {
        int pattern = 0;
        for (int j = 0; j < patternLength; j++)
        {
            pattern = (pattern << 1) | (sequence[i + j] - '0'); // Convert binary pattern to an integer
        }
        counts[pattern]++;
    }

    // Output the counts of each pattern
    printf("Pattern counts:\n");
    for (int i = 0; i < numPatterns; i++)
    {
        printf("Pattern %0*X: %d\n", (patternLength + 3) / 4, i, counts[i]);
    }

    // Calculate the chi-square statistic
    double expectedCount = (double)(n - patternLength + 1) / numPatterns;
    double chiSquare = 0.0;

    for (int i = 0; i < numPatterns; i++)
    {
        double diff = counts[i] - expectedCount;
        chiSquare += (diff * diff) / expectedCount;
    }

    printf("Chi-square statistic: %f\n", chiSquare);
}

int main()
{
    char sequence[100];    // Array to hold the binary sequence
    int patternLength = 3; // Length of the pattern to test (e.g., 3-bit patterns)

    // Input the binary sequence
    printf("Enter the binary sequence: ");
    scanf("%s", sequence);

    // Run the Poker Test
    pokerTest(sequence, patternLength);

    return 0;
}
