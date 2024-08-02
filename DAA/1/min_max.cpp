// Min-Max algorithm works by iterating through the list and keeping track of the current minimum and maximum values.
// Algorithm
// 1. Prompt user to enter the size of array and initialize array dynamically.
// 2. Set `min` to the first element of the list.
// 3. Set `max` to the first element of the list.
// 4. For each element i, check if (arr[i] < min). If so, min = arr[i].
// 5. For each element i,Check if (arr[i]>max). If so, max = arr[i].
// 6. Return the minimum and maximum values.

// C++ Program
#include <iostream>
using namespace std;

void findMinMax(const int arr[], int size, int &min, int &max)
{
    min = arr[0];
    max = arr[0];

    for (int i = 1; i < size; ++i)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
}

int main()
{
    int size;
    cout << "Enter the number of elements: ";
    cin >> size;
    int *arr = new int[size];
    cout << "Enter " << size << " elements:" << endl;
    for (int i = 0; i < size; ++i)
    {
        cin >> arr[i];
    }
    int min, max;
    findMinMax(arr, size, min, max);
    cout << "Minimum value: " << min << endl;
    cout << "Maximum value: " << max << endl;
    delete[] arr;
    return 0;
}

// Complexity Analysis
// Time Complexity: O(n)
// The algorithm scans through the list once, making it linear with respect to the number of elements, n.
// Space Complexity: O(1)
// The algorithm uses a fixed amount of extra space for the variables min and max, regardless of the input size.