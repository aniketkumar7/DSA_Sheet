/// QUICK SORT

// Quick Sort is a Divide and Conquer algorithm. It picks an element as pivot and partitions the given array around the picked pivot.
// There are many different versions of quickSort that pick pivot in different ways.
// 1. Always pick first element as pivot.
// 2. Always pick last element as pivot (implemented below)
// 3. Pick a random element as pivot.
// 4. Pick median as pivot.

// The key process in quickSort is partition(). Target of partitions is, given an array and an element x of array as pivot, put x at its correct position in sorted array and put all smaller elements (smaller than x) before x,
// and put all greater elements (greater than x) after x. All this should be done in linear time.

// Algorithm:
// 1. Pick an element, called a pivot from the array.
// 2. Partitioning: Rearrange the array in such a way that all elements less than the pivot are on the left side of the pivot and all elements greater than the pivot are on the right side of the pivot.
// 3. Recursively apply the above steps to the sub-arrays of elements with smaller values and separately to the sub-arrays of elements with greater values.


// Time and Space Complexity:
// Time Complexity:
// Best Case: O(nlogn)
// Average Case: O(nlogn)
// Worst Case: O(n^2)

// Space Complexity:
// O(logn) for recursive calls
// O(n) for stack space



#include<iostream>
using namespace std;

int quickSort(int arr[], int low, int high)
{
    if (low >= high)
    {
        return 0;
    }
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    i++;
    swap(arr[i], arr[high]);

    quickSort(arr, low, i - 1);
    quickSort(arr, i + 1, high);
}

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Unsorted Array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    quickSort(arr, 0, n - 1);
    cout << endl;
    cout << "Sorted Array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
