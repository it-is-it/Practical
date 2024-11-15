#include <stdio.h>
// Function to calculate the mean of the sample
double calculateMean(int sample[], int size)
{
    double sum = 0.0;
    for (int i = 0; i < size; i++)
    {
        sum += sample[i];
    }
    return sum / size;
}
// Function to calculate the bias of the sample mean
double calculateBias(double sampleMean, double populationMean)
{
    return sampleMean - populationMean;
}
int main()
{
    int n;
    double populationMean;
    printf("Enter the size of the sample: ");
    scanf("%d", &n);
    int sample[n];
    printf("Enter the sample data:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &sample[i]);
    }
    printf("Enter the population mean: ");
    scanf("%lf", &populationMean);
    double sampleMean = calculateMean(sample, n);
    double bias = calculateBias(sampleMean, populationMean);
    printf("Sample Mean: %f\n", sampleMean);
    printf("Bias: %f\n", bias);
    return 0;
}