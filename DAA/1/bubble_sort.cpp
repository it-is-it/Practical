// Bubble sort is a simple sorting algorithm that works by repeatedly stepping through the list to be sorted, comparing adjacent elements, and swapping them if they are in the wrong order. This process is repeated until the list is sorted.

// Iterative Bubble Sort Algorithm
// 1. Start with the first element of the list.
// 2. Compare the current element with the next element.
// 3. Swap them if the current element is greater than the next element.
// 4. Move to the next pair of elements and repeat the comparison and swapping.
// 5. Repeat the process for each element, reducing the number of comparisons as the largest elements "bubble" to the end of the list.
// 6. Continue until no more swaps are needed.

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