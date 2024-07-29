#include <iostream>
using namespace std;

int sequentialSearch(int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            return i; // Return the index of the target value
        }
    }
    return -1; // Target not found
}

int main()
{
    int arr[] = {4, 2, 7, 1, 9, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 7;

    int result = sequentialSearch(arr, n, target);

    if (result != -1)
    {
        cout << "Element found at index " << result << endl;
    }
    else
    {
        cout << "Element not found in the array" << endl;
    }

    return 0;
}
