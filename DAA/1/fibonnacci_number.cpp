#include <iostream>
using namespace std;

int findNthFibonacci(int n)
{
    if (n <= 0)
        return -1; // Handle edge cases
    if (n == 1)
        return 0; // First Fibonacci number
    if (n == 2)
        return 1; // Second Fibonacci number

    int a = 0, b = 1; // Initial Fibonacci numbers
    for (int i = 3; i <= n; ++i)
    {
        int next = a + b; // Calculate next Fibonacci number
        a = b;            // Update a to the previous Fibonacci number
        b = next;         // Update b to the current Fibonacci number
    }
    return b; // Return the nth Fibonacci number
}

int main()
{
    int n;
    cout << "Enter the position of the Fibonacci number to find: ";
    cin >> n;
    int result = findNthFibonacci(n);
    if (result != -1)
        cout << "The " << n << "th Fibonacci number is: " << result << endl;
    else
        cout << "Invalid input! Please enter a positive integer." << endl;
    return 0;
}
