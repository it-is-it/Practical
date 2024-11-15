#include <stdio.h>
#include <string.h>
#include <math.h>

// Function to perform the Gap Test
void gapTest(char *sequence)
{
    int n = strlen(sequence);
    int gapCounts[n]; // Array to store counts of gaps of different lengths
    memset(gapCounts, 0, sizeof(gapCounts));
    int gapLength = 0; // Variable to keep track of the current gap length

    // Iterate through the sequence and count gaps
    for (int i = 0; i < n; i++)
    {
        if (sequence[i] == '1')
        {
            if (gapLength < n)
            {
                gapCounts[gapLength]++;
            }
            gapLength = 0; // Reset the gap length after encountering '1'
        }
        else
        {
            gapLength++;
        }
    }

    // Output the counts of gaps
    printf("Gap counts:\n");
    for (int i = 0; i < n; i++)
    {
        if (gapCounts[i] > 0)
        {
            printf("Gap length %d: %d\n", i, gapCounts[i]);
        }
    }

    // Calculate the chi-square statistic
    double expectedCount = (double)(n - 1) / 2; // Expected count for each gap length
    double chiSquare = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (gapCounts[i] > 0)
        {
            double diff = gapCounts[i] - expectedCount;
            chiSquare += (diff * diff) / expectedCount;
        }
    }

    printf("Chi-square statistic: %f\n", chiSquare);
}

int main()
{
    char sequence[100];

    // Input the binary sequence
    printf("Enter the binary sequence: ");
    scanf("%s", sequence);

    // Run the Gap Test
    gapTest(sequence);

    return 0;
}
