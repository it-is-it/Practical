// 2.)ImplementMonteCarloSimulationtoestimatethevalueofintegral ∫01 1/x^2
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Function to generate a random double between a and b
double randomDouble(double a, double b)
{
    return a + (b - a) * ((double)rand() / RAND_MAX);
}

// Function to estimate the integral using Monte Carlo simulation
double estimateIntegral(int numPoints, double epsilon)
{
    double sum = 0.0;

    // Generate random points and estimate the integral
    for (int i = 0; i < numPoints; i++)
    {
        double x = randomDouble(epsilon, 1.0); // Random x between epsilon and 1.0
        sum += 1.0 / (x * x);                  // Add the value of 1/x^2 to the sum
    }

    // The integral approximation is the average of 1/x^2 values multiplied by (1 - epsilon)
    return (sum / numPoints) * (1.0 - epsilon);
}

int main()
{
    srand(time(0)); // Seed the random number generator

    int numPoints;
    double epsilon;

    printf("Enter the number of random points to generate: ");
    scanf("%d", &numPoints);

    printf("Enter a small positive value for epsilon (close to 0): ");
    scanf("%lf", &epsilon);

    // Estimate the integral using Monte Carlo simulation
    double estimatedIntegral = estimateIntegral(numPoints, epsilon);

    printf("Estimated value of the integral: %f\n", estimatedIntegral);

    return 0;
}
