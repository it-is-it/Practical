// Selection Sort is a sorting algorithm that divides the input list into two parts: the sorted part and the unsorted part. It repeatedly selects the smallest (or largest) element from the unsorted part and moves it to the end of the sorted part.
// Algorithm:
// 1. Start with the first element of the array.
// 2. Find the smallest element in the unsorted part of the array.
// 3. Swap this smallest element with the first element of the unsorted part.
// 4. Move the boundary between the sorted and unsorted parts one element to the right.
// 5. Repeat steps 2-4 until the entire array is sorted.

// C++ Program:
#include <iostream>
using namespace std;

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        // Find the index of the minimum element in the unsorted part
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        // Swap the found minimum element with the first element of the unsorted part
        if (minIndex != i)
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
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
    selectionSort(arr, size);
    cout << "Sorted array: ";
    printArray(arr, size);
    delete[] arr;
    return 0;
}

// Complexity Analysis:
// Time Complexity: O(n^2) - Even if the array is already sorted, the algorithm still performs n iterations for the first element, n-1 for the second, and so on.

// Space Complexity: O(1) - The sorting is done in place, so no additional space is needed other than the temporary variables for swapping.