/// Count Sort

// Counting Sort is a non-comparison-based sorting algorithm that sorts integers by counting the occurrences of each unique element in the input array. It is particularly efficient when the range of input values (keys) is not significantly larger than the number of elements to be sorted.

/// How Counting Sort Works

/// Determine the Range:
// Identify the maximum and minimum values in the input array to determine the range of the count array.

/// Count Occurrences:
// Create a count array to store the count of each unique element in the input array.
// Iterate through the input array and increment the count of each element in the count array.

/// Cumulative Count:
// Modify the count array such that each element at each index stores the sum of previous counts.
// This step helps in determining the position of each element in the sorted output array.

/// Build the Output Array:
// Create an output array to store the sorted elements.
// Iterate through the input array from the end to the beginning.
// Place each element in its correct position in the output array using the count array.
// Decrement the count of the placed element.

/// Copy to Original Array:
// Copy the sorted elements from the output array back to the original array.


// Example
// Consider the input array: [1, 4, 1, 2, 7, 5, 2]

// Initial Input:
// arr = [ 1, 4, 1, 2, 7, 5, 2 ]

// Count Occurrences:
// Create a count array to store the count of each unique element.
// Count array after counting occurrences:
// Index : 0 1 2 3 4 5 6 7 8 9
// Count : 0 2 2 0 1 1 0 1 0 0

// Cumulative Count:
// Modify the count array to store the cumulative count.
// Index : 0 1 2 3 4 5 6 7 8 9
// Count : 0 2 4 4 5 6 6 7 7 7

// Build the Output Array:
// Place each element in its correct position in the output array.
// Output array after placing elements:
// Output: [ 1, 1, 2, 2, 4, 5, 7 ]

// Copy to Original Array:
// Copy the sorted elements back to the original array.
// Final sorted array:
// arr = [ 1, 1, 2, 2, 4, 5, 7 ]


// Time and Space Complexity

/// Time Complexity: (O(n + k))
// (O(n)) to find the maximum and minimum elements.
// (O(n)) to count the elements.
// (O(k)) to modify the count array.
// (O(n)) to build the output array.
// Overall, (O(n + k)), where (n) is the number of elements and (k) is the range of the input.

/// Space Complexity: (O(n + k))
// (O(k)) for the count array.
// (O(n)) for the output array.
// Overall, (O(n + k)).


// Advantages and Disadvantages
/// Advantages:
// Efficient for sorting integers when the range of input values is not significantly larger than the number of elements.
// Stable sorting algorithm, meaning it maintains the relative order of equal elements.

/// Disadvantages:
// Not suitable for sorting non-integer data or data with a large range of values.
// Requires additional space for the count and output arrays.

/// Conclusion
// Counting Sort is a powerful sorting algorithm for specific use cases where the range of input values is limited. It provides linear time complexity and is stable, making it a valuable tool in the right scenarios.


// Code:

#include <bits/stdc++.h>
    using namespace std;

// Function to perform Counting Sort
void countingSort(vector<int> &arr)
{
    // Find the maximum element in the array
    int maxElement = *max_element(arr.begin(), arr.end());

    // Create a count array to store the count of each unique element
    vector<int> count(maxElement + 1, 0);

    // Store the count of each element in the count array
    for (int num : arr)
    {
        count[num]++;
    }

    // Modify the count array such that each element at each index
    // stores the sum of previous counts
    for (int i = 1; i <= maxElement; i++)
    {
        count[i] += count[i - 1];
    }

    // Create an output array to store the sorted elements
    vector<int> output(arr.size());

    // Build the output array by placing elements at their correct positions
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the sorted elements back to the original array
    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = output[i];
    }
}

int main()
{
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};
    cout << "Before Sorting: ";
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    countingSort(arr);

    cout << "After Sorting: ";
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}