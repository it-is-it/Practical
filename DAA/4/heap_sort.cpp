

//  Algorithm for Heap Sort

//  Step 1: Build Max Heap
// 1. Build Max Heap:
//    - For each node from the last non-leaf node to the root node, call heapify to ensure the subtree rooted at each node satisfies the max-heap property.
//    - The last non-leaf node is at index n/2 - 1.

//  Step 2: Heapify
// 1. Heapify Function:
//    - For a node i:
//      - Set largest to i.
//      - Compare arr[i] with its left and right children.
//      - Update largest to the index of the largest value.
//      - If largest is not i, swap arr[i] and arr[largest] and call heapify recursively on the affected subtree.

//  Step 3: Sort the Array
// 1. Heap Sort:
//    - Swap the root element with the last element.
//    - Reduce the heap size by one.
//    - Call heapify on the root to maintain the max-heap property.
//    - Repeat until the heap is fully sorted.

//  C++ Program for Heap Sort

#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int largest = i;       // Initialize largest as root
    int left = 2 * i + 1;  // left child
    int right = 2 * i + 2; // right child

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
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
    heapSort(arr, size);
    cout << "Sorted array: ";
    printArray(arr, size);
    delete[] arr;
    return 0;
}

//  Time Complexity
// - Building the heap: (O(n))
// - Heapify operation: (O(log n)) (performed (n) times)
// Thus, the overall time complexity of Heap Sort is (O(n log n)).

//  Space Complexity
// Heap Sort is an in-place sorting algorithm, so its space complexity is (O(1)) apart from the input array.
