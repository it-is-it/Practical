// Quick Sort is a divide and conquer algorithm that sorts an array by partitioning it into smaller sub-arrays around a pivot element. The process is repeated recursively until the entire array is sorted.

//  Algorithm
// 1. Choose a Pivot:
//    - Select a pivot element from the array. Common choices include the first element, the last element, the middle element, or a random element.

// 2. Partitioning:
//    - Rearrange the elements in the array such that:
//      - All elements less than the pivot are moved to its left.
//      - All elements greater than the pivot are moved to its right.
//    - The pivot is now in its correct sorted position.

// 3. Recursively Apply:
//    - Recursively apply the above steps to the sub-arrays formed by splitting the array at the pivot.

//  C++ Program for Quick Sort

#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // Choosing the last element as the pivot
    int i = low - 1;       // Index of smaller element

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high); // Partitioning index
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
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

    cout << "Original array: ";
    printArray(arr, size);

    quickSort(arr, 0, size - 1);

    cout << "Sorted array: ";
    printArray(arr, size);

    delete[] arr;
    return 0;
}

// Complexity Analysis :
// Time Complexity : -Average Case : (O(n log n))
// - Worst Case : (O(n ^ 2))(occurs when the smallest or largest element is always chosen as the pivot)
// - Best Case : (O(n log n))
// Space Complexity : -(O(log n))due to recursive stack space.
