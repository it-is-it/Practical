#include <stdio.h>
#include <math.h>

#define MASS 1000.0          // Mass of the vehicle (kg)
#define DAMPING 100.0        // Damping coefficient (N·s/m)
#define SPRING 20000.0       // Spring constant (N/m)
#define TIME_STEP 0.01       // Time step for simulation (seconds)
#define SIMULATION_TIME 10.0 // Total simulation time (seconds)

// Function to calculate acceleration based on displacement, velocity, and external force
double calculateAcceleration(double displacement, double velocity, double externalForce)
{
    return (externalForce - DAMPING * velocity - SPRING * displacement) / MASS;
}

// Function to simulate a time-varying external force (e.g., sinusoidal force representing road bumps)
double externalForce(double time)
{
    return 500.0 * sin(2.0 * M_PI * 0.5 * time); // 500 N amplitude, 0.5 Hz frequency
}

int main()
{
    double time = 0.0;
    double displacement = 0.0; // Initial displacement (m)
    double velocity = 0.0;     // Initial velocity (m/s)
    double acceleration = 0.0; // Initial acceleration (m/s^2)

    printf("Time(s)\tDisplacement(m)\tVelocity(m/s)\tAcceleration(m/s^2)\n");

    // Loop to simulate the motion of the wheel suspension system
    while (time <= SIMULATION_TIME)
    {
        // Calculate external force at the current time step
        double extForce = externalForce(time);

        // Print the current state of the system
        printf("%f\t%f\t%f\t%f\n", time, displacement, velocity, acceleration);

        // Calculate acceleration using the dynamic equation
        acceleration = calculateAcceleration(displacement, velocity, extForce);

        // Update velocity and displacement using basic kinematic equations
        velocity += acceleration * TIME_STEP;
        displacement += velocity * TIME_STEP;

        // Increment time step
        time += TIME_STEP;
    }

    return 0;
}
