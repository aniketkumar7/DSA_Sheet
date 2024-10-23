/// Selection Sort

// Selection Sort is a simple comparison-based sorting algorithm that divides the input list into two parts: the sorted part at the beginning and the unsorted part at the end. The algorithm repeatedly selects the smallest (or largest, depending on the sorting order) element from the unsorted part and swaps it with the leftmost unsorted element, moving the boundary between the sorted and unsorted parts one element to the right.

/// How Selection Sort Works

/// Iterate Through the List:
// Start from the beginning of the list and iterate through each element.

/// Find the Minimum Element:
// For each position in the list, find the smallest element in the unsorted part of the list.

/// Swap Elements:
// Swap the found minimum element with the first element of the unsorted part.

/// Repeat the Process:
// Move the boundary between the sorted and unsorted parts one element to the right.
// Repeat the process until the entire list is sorted.

// Example
// Consider the input array: [64, 25, 12, 22, 11]

/// Initial Input:
// arr = [ 64, 25, 12, 22, 11 ]

/// First Pass:
// Find the minimum element in the unsorted part [64, 25, 12, 22, 11] (minimum is 11).
// Swap 11 with the first element (64):
// arr = [ 11, 25, 12, 22, 64 ]

/// Second Pass:
// Find the minimum element in the unsorted part [25, 12, 22, 64] (minimum is 12).
// Swap 12 with the first element of the unsorted part (25):
// arr = [11, 12, 25, 22, 64]

/// Third Pass:
// Find the minimum element in the unsorted part [25, 22, 64] (minimum is 22).
// Swap 22 with the first element of the unsorted part (25):
// arr = [11, 12, 22, 25, 64]

/// Fourth Pass:
// Find the minimum element in the unsorted part [25, 64] (minimum is 25).
// Swap 25 with the first element of the unsorted part (25):
// arr = [11, 12, 22, 25, 64]

/// Final Output:
// arr = [ 11, 12, 22, 25, 64 ]


// Time and Space Complexity
/// Time Complexity:
// Best Case: (O(n^2))
// Average Case: (O(n^2))
// Worst Case: (O(n^2))

/// Space Complexity: (O(1))
// Selection Sort is an in-place sorting algorithm, meaning it requires only a constant amount of additional space.

/// Advantages and Disadvantages
/// Advantages:
// Simple to understand and implement.
// Does not require additional memory (in-place sorting).

/// Disadvantages:
// Inefficient for large datasets due to its (O(n^2)) time complexity.
// Not stable, meaning it does not maintain the relative order of equal elements.

/// Conclusion
// Selection Sort is a straightforward sorting algorithm that is useful for educational purposes and small datasets. However, due to its inefficiency with larger datasets, it is not recommended for use in performance-critical applications.

// Code:

#include <bits/stdc++.h>
    using namespace std;

void selectionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

int main()
{
    vector<int> arr = {64, 25, 12, 22, 11};
    cout << "Before Sorting: ";
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    selectionSort(arr);

    cout << "After Sorting: ";
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}