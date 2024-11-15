#include <stdio.h>
#include <string.h>

// Function to perform the Autocorrelation Test
void autocorrelationTest(char *sequence, int d)
{
    int n = strlen(sequence); // Length of the sequence
    int matchCount = 0;       // Counter for matches

    // Loop through the sequence, comparing characters with lag 'd'
    for (int i = 0; i < n - d; i++)
    {
        if (sequence[i] == sequence[i + d])
        {
            matchCount++;
        }
    }

    // Calculate the autocorrelation coefficient
    double autocorrelation = (double)matchCount / (n - d);
    printf("Autocorrelation Test Result: %f\n", autocorrelation);
}

int main()
{
    char sequence[100]; // Array to hold the binary sequence
    int d;              // Lag distance for the test

    // Input the binary sequence and lag
    printf("Enter the binary sequence: ");
    scanf("%s", sequence);
    printf("Enter the lag (d): ");
    scanf("%d", &d);

    // Run the autocorrelation test
    autocorrelationTest(sequence, d);

    return 0;
}
