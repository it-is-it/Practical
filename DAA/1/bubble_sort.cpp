// Bubble sort is a simple sorting algorithm that works by repeatedly stepping through the list to be sorted, comparing adjacent elements, and swapping them if they are in the wrong order. This process is repeated until the list is sorted.

// Algorithm for Bubble Sort with Operations
//    1 Prompt user for the number of elements (size).
//    2 Allocate memory for the array (arr) and  Input the elements into the array.
// 3. Bubble Sort:
//    - For each element from the first to the second last (i from 0 to n-2):
//      - Set swapped to false.
//      - For each element from the first to n-i-2 (j from 0 to n-i-2):
//        - Compare arr[j] with arr[j+1].
//        - If arr[j] > arr[j+1], swap them and set swapped to true.
//      - If swapped is false, break the loop.

// 4. Use printArray to display the sorted array.

// Bubble Sort in C++
#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped)
        {
            break;
        }
    }
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
    bubbleSort(arr, size);
    cout << "Sorted array: ";
    printArray(arr, size);
    delete[] arr;
    return 0;
}

// Complexity Analysis
// Time Complexity: O(n^2) - This occurs when the list is in reverse order. Each element must be compared with each other element, leading to n*(n-1)/2 comparisons.

// Space Complexity:O(1) - Bubble sort is an in-place sorting algorithm, so it requires only a constant amount of extra space.