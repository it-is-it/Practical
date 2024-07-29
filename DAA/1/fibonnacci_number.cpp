// The fibonacci sequence is a series of numbers where each number is the sum of the two preceding ones, usually starting with 0 and 1. The nth Fibonacci number is the number at position n in this sequence.
// Algorithm:
// 1. Initialize two variables `a` and `b` to 0 and 1, respectively.
// 2. Use a loop to iterate from 2 to n (inclusive).
// 3. In each iteration, update the variables: `temp = a + b`, `a = b`, `b = temp`.
// 4. After the loop ends, `b` will hold the nth Fibonacci number.

// C++ Program
#include <iostream>
using namespace std;

int fibonacci(int n)
{
    if (n <= 0)
        return 0;
    if (n == 1)
        return 1;

    int a = 0, b = 1;
    for (int i = 2; i <= n; ++i)
    {
        int temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    int result = fibonacci(n);
    cout << "The " << n << "th Fibonacci number is: " << result << endl;
    return 0;
}

// Complexity Analysis
// Time Complexity
// The time complexity of the iterative algorithm is O(n). This is because the loop runs n-1 times (for values from 2 to n, inclusive).

// Space Complexity
// The space complexity is O(1). This is because the algorithm uses a fixed amount of extra space (for the variables a, b, and temp), regardless of the input size n.