// Binary search is an efficient algorithm used to find an item in a sorted list. It follows the divide and conquer approach by repeatedly dividing the search interval in half. Here's how the binary search algorithm works:
//  Binary Search Algorithm

// 1. Initialize:
//    - Set low to 0 (start of the list).
//    - Set high to n - 1 (end of the list).

// 2. Repeat until low ≤ high:
//    - Compute mid as (low + high) / 2.
//    - If arr[mid] equals target, return mid.
//    - Else If target < arr[mid], set high to mid - 1.
//    - Else set low to mid + 1.

// 3. Return -1 if the target is not found (when low exceeds high).

// Here's a C++ implementation of binary search:
#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int target)
{
    int low = 0;
    int high = size - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1; // Target not found
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int size;
    cout << "Enter the number of elements in the ordered list: ";
    cin >> size;
    int *arr = new int[size];
    cout << "Enter " << size << " sorted elements:" << endl;
    for (int i = 0; i < size; ++i)
    {
        cin >> arr[i];
    }
    int target;
    cout << "Enter the element to search for: ";
    cin >> target;
    int result = binarySearch(arr, size, target);
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

// Key Points:
// 1. Sorted Array Required: Binary search assumes that the array is sorted. If the array is not sorted, the algorithm will not work correctly.
// 2. Time Complexity: O(log n) - Each step halves the search interval, so the number of comparisons grows logarithmically with the size of the array.
// 3. Space Complexity: O(1) - Binary search uses a constant amount of extra space.
