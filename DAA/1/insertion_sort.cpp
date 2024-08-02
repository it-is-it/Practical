// Insertion Sort is a sorting algorithm that builds the final sorted list one item at a time. It repeatedly takes the next item from the unsorted part and inserts it into its correct position in the sorted part.
// Algorithm:
// 1.Start with the second element in the array (at index 1), first element is consider already sorted.
// 2.For each element at index i (from 1 to n-1):
//      1. Set the Key:
//         - Set key to the element at index i.
//         - Set j to i-1.
//      2. Shift Elements:
//         - While j >= 0 and the element at arr[j] > key:
//           - Move arr[j] to the position j+1.
//           - j=j-1.
//      3. Place the Key:
//         - Insert key into the position j+1.
// 3. The array is now sorted.

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
