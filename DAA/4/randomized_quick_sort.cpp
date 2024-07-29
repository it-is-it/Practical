//  Algorithm for Randomized Quick Sort using Divide and Conquer

// 1. Randomized Partition:
//    - Randomly select a pivot element and swap it with the last element.
//    - Partition the array around this pivot.

// 2. Partition:
//    - Use the last element as pivot.
//    - Rearrange the array so that elements less than the pivot are on the left and elements greater than the pivot are on the right.

// 3. Quick Sort:
//    - If the array has one or zero elements, it is already sorted.
//    - Otherwise, perform the randomized partition and recursively apply Quick Sort to the left and right sub-arrays.

//  C++ Code Implementation

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

int randomizedPartition(int arr[], int low, int high)
{
    int pivotIndex = low + rand() % (high - low + 1);
    swap(arr[pivotIndex], arr[high]);
    return partition(arr, low, high);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = randomizedPartition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    srand(time(0));
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

//  Complexity Analysis
// - Time Complexity:
//   - Average Case: (O(n log n))
//   - Worst Case: (O(n^2)) (when the smallest or largest element is always chosen as pivot)

// - Space Complexity:
//   - (O(log n)) for the recursion stack in the best and average cases.
//   - (O(n)) in the worst case due to the depth of the recursion tree.
