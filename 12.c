//  12. ) Write a program to implement Markov chain to predict weather condition.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef enum
{
    SUNNY,
    RAINY
} WeatherState;
WeatherState getNextState(WeatherState currentState, double
                                                         transitionMatrix[2][2])
{
    double randProb = (double)rand() / RAND_MAX;
    if (currentState == SUNNY)
    {
        if (randProb < transitionMatrix[SUNNY][SUNNY])
        {
            return SUNNY;
        }
        else
        {
            return RAINY;
        }
    }
    else
    {
        if (randProb < transitionMatrix[RAINY][RAINY])
        {
            return RAINY;
        }
        else
        {
            return SUNNY;
        }
    }
}
void printWeatherState(WeatherState state)
{
    if (state == SUNNY)
    {
        printf("Sunny");
    }
    else
    {
        printf("Rainy");
    }
}
int main()
{
    srand(time(0));
    double transitionMatrix[2][2] = {
        {0.8, 0.2}, // Transition probabilities from Sunny
        {0.4, 0.6}  // Transition probabilities from Rainy
    };
    // Initial state
    WeatherState currentState = SUNNY;
    int numPredictions = 10;
    printf("Weather predictions:\n");
    for (int i = 0; i < numPredictions; i++)
    {
        printf("Day %d: ", i + 1);
        printWeatherState(currentState);
        printf("\n");
        currentState = getNextState(currentState, transitionMatrix);
    }
    return 0;
}