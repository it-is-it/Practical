// Algorithm:
// 1.Start.
// 2.Read two numbers a and b.
// 3.If a is 0 and b is not 0, return b as the GCD.
// 4.If b is 0 and a is not 0, return a as the GCD.
// 5.While b is not 0:
// Store the value of b in a temporary variable temp.
// Update b to be the remainder of a divided by b (i.e., a % b).
// Assign the value of temp to a.
// 6.When b becomes 0, the value of a is the GCD.
// 7.stop

#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (a == 0 && b)
    {
        return b;
    }
    else if (a && b == 0)
    {
        return a;
    }
    else
        while (b != 0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
    return a;
}

int main()
{
    int num1, num2;
    cout << "Enter two integers: ";
    cin >> num1 >> num2;
    int result = gcd(num1, num2);
    cout << "GCD of " << num1 << " and " << num2 << " is " << result << endl;
    return 0;
}

// Complexity Analysis:
// Time Complexity: The time complexity of the Euclidean algorithm is O(logmin(a,b)). This is because the algorithm reduces the size of the numbers fairly quickly, and the number of steps is proportional to the logarithm of the smaller number.
// Space Complexity: The space complexity is O(1) since it uses a constant amount of space for variables regardless of the input size.