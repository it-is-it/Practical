// 1)ImplementMonteCarloSimulationtoestimate valueofPI.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Function to generate a random double between -1 and 1
double randomDouble()
{
    return (double)rand() / RAND_MAX * 2.0 - 1.0;
}

// Function to estimate the value of PI using Monte Carlo
double estimatePI(int numPoints)
{
    int pointsInsideCircle = 0;

    // Generate random points and check if they are inside the unit circle
    for (int i = 0; i < numPoints; i++)
    {
        double x = randomDouble();
        double y = randomDouble();

        if (x * x + y * y <= 1)
        {
            pointsInsideCircle++;
        }
    }

    // The ratio of points inside the circle to total points approximates Pi/4
    return 4.0 * pointsInsideCircle / numPoints;
}

int main()
{
    srand(time(0)); // Seed the random number generator

    int numPoints;
    printf("Enter the number of random points to generate: ");
    scanf("%d", &numPoints);

    // Estimate PI using Monte Carlo simulation
    double estimatedPI = estimatePI(numPoints);
    printf("Estimated value of PI: %f\n", estimatedPI);

    return 0;
}
