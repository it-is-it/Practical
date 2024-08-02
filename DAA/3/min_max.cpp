// The divide and conquer approach is a strategy for solving problems by breaking them down into smaller subproblems, solving those subproblems independently, and then combining their solutions. To find the maximum and minimum elements in a list using this approach, you can recursively divide the list into two halves until you reach base cases, then combine the results to find the overall minimum and maximum.

// Divide and Conquer Algorithm for Finding Minimum and Maximum
// 1. Input:
//    - Array arr[] with n elements.
//    - Indices low and high representing the current subarray.

// 2. Base Case:
//    - Single Element: If low == high, set both min and max to arr[low].
//    - Two Elements: If high == low + 1, compare arr[low] and arr[high]:
//      - Set min to the smaller value.
//      - Set max to the larger value.

// 3. Recursive Case:
//    - Divide: Compute mid as (low + high) / 2.
//    - Conquer:
//      - Recursively find min1 and max1 in the left subarray (arr[low] to arr[mid]).
//      - Recursively find min2 and max2 in the right subarray (arr[mid + 1] to arr[high]).
//    - Combine:
//      - Set overall min as min(min1, min2).
//      - Set overall max as max(max1, max2).

// 4. Output:
//    - Return the combined min and max values for the entire array.

// Here is a C++ program implementing the divide and conquer approach to find both the maximum and minimum elements in a list :

#include <iostream>
using namespace std;

void findMinMax(int arr[], int low, int high, int &min, int &max)
{
    if (low == high)
    {
        min = max = arr[low];
    }
    else if (high == low + 1)
    {
        if (arr[low] > arr[high])
        {
            min = arr[high];
            max = arr[low];
        }
        else
        {
            min = arr[low];
            max = arr[high];
        }
    }
    else
    {
        int mid = (low + high) / 2;

        int min1, max1, min2, max2;
        findMinMax(arr, low, mid, min1, max1);
        findMinMax(arr, mid + 1, high, min2, max2);

        min = (min1 < min2) ? min1 : min2;
        max = (max1 > max2) ? max1 : max2;
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
    findMinMax(arr, 0, size - 1, min, max);

    cout << "Minimum element: " << min << endl;
    cout << "Maximum element: " << max << endl;

    delete[] arr;
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(logn)