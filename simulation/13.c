// 13.) Write a program to calculate measures of a M/M/1 Queue for a given value of Arrival Rate and Service Rate.
#include <stdio.h>
void calculateMM1Queue(double arrivalRate, double
                                               serviceRate)
{
    double rho = arrivalRate / serviceRate;
    double L = arrivalRate / (serviceRate - arrivalRate);
    double Lq = rho * rho / (1 - rho);
    double W = 1 / (serviceRate - arrivalRate);
    double Wq = arrivalRate / (serviceRate * (serviceRate - arrivalRate));
    printf("Traffic Intensity (rho): %f\n", rho);
    printf("Average number of customers in the system (L): %f\n", L);
    printf("Average number of customers in the queue (Lq): %f\n", Lq);
    printf("Average time a customer spends in the system (W): %f\n", W);
    printf("Average time a customer spends in the queue (Wq): %f\n", Wq);
}
int main()
{
    double arrivalRate, serviceRate;
    printf("Enter the arrival rate (lambda): ");
    scanf("%lf", &arrivalRate);
    printf("Enter the service rate (mu): ");
    scanf("%lf", &serviceRate);
    if (arrivalRate >= serviceRate)
    {
        printf("Error: Arrival rate must be less than service rate for a stable system.\n");
    }
    else
    {
        calculateMM1Queue(arrivalRate, serviceRate);
    }
    return 0;
}