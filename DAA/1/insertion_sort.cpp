// Algorithm:
// 1. Start from the second element of the array (index 1), as the first element is considered already sorted.
// 2. For each element `key` at position `i` (from `1` to `n-1`):
//    - Set `j` to `i-1`** (the index of the element just before `key`).
//    - While `j` is greater than or equal to `0` and the element at `arr[j]` is greater than `key`:
//      - Move the element `arr[j]` one position ahead (`arr[j + 1] = arr[j]`).
//      - Decrement `j` by `1`.
//    - **Place `key` in the correct position** (`arr[j + 1]`).
// 3. Repeat the above steps for all elements in the array.
// 4. End when the entire array is sorted.

// C++ Program
#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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
    cout << "Unsorted array: ";
    printArray(arr, size);
    insertionSort(arr, size);
    cout << "Sorted array: ";
    printArray(arr, size);
    delete[] arr;
    return 0;
}

// Complexity Analysis
// Time Complexity: O(n^2) - This occurs when the array is sorted in reverse order. In this scenario, each element has to be compared with every other element in the sorted portion.
// Space Complexity: O(1) - Insertion Sort is an in-place sorting algorithm, so it requires a constant amount of additional space.
