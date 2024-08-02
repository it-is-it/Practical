// Sequential Search, also known as Linear Search, is a simple searching algorithm. It checks each element in the array one by one until it finds the target value or reaches the end of the array.

// Algorithm :
// 1. prompt user to input array size n and target value.
// 2.Set index i to 0 (start from the first element).
// 3.While i < n (ensure i is within array bounds):
// Compare: Check if arr[i] == target.
//     If True: Return i (index where the target is found).
//     If False:Increment: Increase i by 1 to move to the next element.
// 6.If the target value is not found, return -1 (or another indicator that the target is not present).

#include <iostream>
using namespace std;

int sequentialSearch(int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            return i; // Return the index of the target value
        }
    }
    return -1; // Target not found
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
    int target;
    cout << "Enter the element to search for: ";
    cin >> target;
    int result = sequentialSearch(arr, size, target);
    if (result != -1)
    {
        cout << "Element found at index " << result << endl;
    }
    else
    {
        cout << "Element not found in the array" << endl;
    }
    delete[] arr;
    return 0;
}

// Complexity Analysis:
// Time Complexity: O(n), where n is the number of elements in the array. In the worst case, the algorithm needs to check all n elements.
// Space Complexity: O(1), because it only uses a constant amount of extra space for variables.