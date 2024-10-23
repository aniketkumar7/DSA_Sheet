/// Bubble Sort

// Bubble Sort is a simple comparison-based sorting algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. This process is repeated until the list is sorted. Bubble Sort is named for the way smaller elements "bubble" to the top of the list.

/// How Bubble Sort Works

/// Iterate Through the List:
// Start from the beginning of the list and iterate through each element.

/// Compare Adjacent Elements:
// Compare each pair of adjacent elements.
// If the elements are in the wrong order (i.e., the first element is greater than the second), swap them.

/// Repeat the Process:
// Repeat the process for the entire list.
// After each pass, the largest element in the unsorted portion of the list is moved to its correct position.
// Reduce the range of the unsorted portion by one after each pass.

/// Stop When Sorted:
// Continue the process until no swaps are needed, indicating that the list is sorted.

// Example
// Consider the input array: [5, 1, 4, 2, 8]

/// Initial Input:
// arr = [ 5, 1, 4, 2, 8 ]

/// First Pass:
// Compare and swap if needed:
// [5, 1, 4, 2, 8] → [1, 5, 4, 2, 8] (swap 5 and 1)
// [1, 5, 4, 2, 8] → [1, 4, 5, 2, 8] (swap 5 and 4)
// [1, 4, 5, 2, 8] → [1, 4, 2, 5, 8] (swap 5 and 2)
// [1, 4, 2, 5, 8] → [1, 4, 2, 5, 8] (no swap needed)

/// Second Pass:
// Compare and swap if needed:
// [1, 4, 2, 5, 8] → [1, 4, 2, 5, 8] (no swap needed)
// [1, 4, 2, 5, 8] → [1, 2, 4, 5, 8] (swap 4 and 2)
// [1, 2, 4, 5, 8] → [1, 2, 4, 5, 8] (no swap needed)

/// Third Pass:
// Compare and swap if needed:
// [1, 2, 4, 5, 8] → [1, 2, 4, 5, 8] (no swap needed)
// [1, 2, 4, 5, 8] → [1, 2, 4, 5, 8] (no swap needed)

/// Fourth Pass:
// Compare and swap if needed:
// [1, 2, 4, 5, 8] → [1, 2, 4, 5, 8] (no swap needed)

/// Final Output:
// arr = [ 1, 2, 4, 5, 8 ]

// Time and Space Complexity
/// Time Complexity:
// Best Case: (O(n)) when the array is already sorted.
// Average Case: (O(n^2)) due to the nested loops.
// Worst Case: (O(n^2)) when the array is sorted in reverse order.

/// Space Complexity: (O(1))

// Bubble Sort is an in-place sorting algorithm, meaning it requires only a constant amount of additional space.

/// Advantages and Disadvantages

/// Advantages:

// Simple to understand and implement.
// Does not require additional memory (in-place sorting).
/// Disadvantages:

// Inefficient for large datasets due to its (O(n^2)) time complexity.
// Not suitable for performance-critical applications.

/// Conclusion
// Bubble Sort is a straightforward sorting algorithm that is useful for educational purposes and small datasets. However, due to its inefficiency with larger datasets, it is not recommended for use in performance-critical applications.

// Code

#include <bits/stdc++.h>
    using namespace std;

void bubbleSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}


int main()
{
    vector<int> arr = {12, 11, 13, 5, 6};
    cout << "Before Sorting: ";
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    bubbleSort(arr);

    cout << "After Sorting: ";
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

// Output:
// Before Sorting: 12 11 13 5 6
// After Sorting: 5 6 11 12 13

// How Bubble Sort Works:
// Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in the wrong order.

// Let's understand how Bubble Sort works with an example:
// Consider an array {12, 11, 13, 5, 6}.

// First Pass:
// (12 11 13 5 6) -> (11 12 13 5 6) -> (11 12 13 5 6) -> (11 12 5 13 6) -> (11 12 5 6 13)

// Second Pass:
// (11 12 5 6 13) -> (11 5 12 6 13) -> (11 5 6 12 13) -> (5 11 6 12 13) -> (5 6 11 12 13)

// ... and so on.