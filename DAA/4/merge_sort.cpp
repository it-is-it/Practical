// Merge Sort is a classic example of the divide and conquer paradigm. The algorithm works by recursively dividing the array into two halves, sorting each half, and then merging the sorted halves back together.

//  Algorithm for Merge Sort

// 1. Input:
//    - An array arr[] with n elements.

// 2. Recursive Function:
//    - mergeSort(arr, l, r): sorts the array arr from index l to r.

// 3. Base Case:
//    - If l >= r, return (the array is already sorted if it has one or no elements).

// 4. Divide:
//    - Calculate the middle point m of the array: m = l + (r - l) / 2.

// 5. Conquer:
//    - Recursively sort the left half: mergeSort(arr, l, m).
//    - Recursively sort the right half: mergeSort(arr, m + 1, r).

// 6. Combine:
//    - Merge the two halves using a helper function merge(arr, l, m, r).

// 7. Merge Function:
//    - merge(arr, l, m, r): merges two sorted subarrays arr[l..m] and arr[m+1..r] into a single sorted array.

//  C++ Program
#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int *L = new int[n1];
    int *R = new int[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[m + 1 + i];
    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
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
    cout << "Given array: ";
    printArray(arr, size);
    mergeSort(arr, 0, size - 1);
    cout << "Sorted array: ";
    printArray(arr, size);
    delete[] arr;
    return 0;
}

//  Complexity Analysis
// - Time Complexity:
//   - The time complexity of Merge Sort is (O(n log n)). This is because the array is divided into two halves ( log n ) times, and the merging step takes linear time ( O(n) ).

// - Space Complexity:
//   - The space complexity of Merge Sort is (O(n)) due to the temporary arrays used for merging.
