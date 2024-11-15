#include <stdio.h>
#include <math.h>

// Function to calculate the mean of the sample
double calculateMean(double sample[], int size)
{
    double sum = 0.0;
    for (int i = 0; i < size; i++)
    {
        sum += sample[i];
    }
    return sum / size;
}

// Function to calculate the standard deviation of the sample
double calculateStandardDeviation(double sample[], int size, double mean)
{
    double sum = 0.0;
    for (int i = 0; i < size; i++)
    {
        sum += pow(sample[i] - mean, 2);
    }
    return sqrt(sum / size);
}

// Function to calculate the confidence interval
void calculateConfidenceInterval(double sample[], int size, double populationMean, double confidenceLevel)
{
    double sampleMean = calculateMean(sample, size);
    double stdDev = calculateStandardDeviation(sample, size, sampleMean);

    // Z-score for the given confidence level (e.g., 1.96 for 95%)
    double Z;
    if (confidenceLevel == 95)
    {
        Z = 1.96;
    }
    else if (confidenceLevel == 99)
    {
        Z = 2.576;
    }
    else
    {
        printf("Unsupported confidence level.\n");
        return;
    }

    double marginOfError = Z * stdDev / sqrt(size);
    double lowerBound = sampleMean - marginOfError;
    double upperBound = sampleMean + marginOfError;

    printf("Sample Mean: %f\n", sampleMean);
    printf("Population Mean: %f\n", populationMean);
    printf("Confidence Interval (%.0f%%): [%f, %f]\n", confidenceLevel, lowerBound, upperBound);
}

int main()
{
    int n;
    double confidenceLevel, populationMean;

    printf("Enter the size of the sample: ");
    scanf("%d", &n);

    double sample[n];
    printf("Enter the sample data:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &sample[i]);
    }

    printf("Enter the population mean: ");
    scanf("%lf", &populationMean);
    printf("Enter the confidence level (95 or 99): ");
    scanf("%lf", &confidenceLevel);

    calculateConfidenceInterval(sample, n, populationMean, confidenceLevel);

    return 0;
}
