/// Insertion Sort

// Insertion Sort is a simple comparison-based sorting algorithm that builds the final sorted array one element at a time. It is much less efficient on large lists than more advanced algorithms such as quicksort, heapsort, or merge sort. However, it has the advantage of being simple to implement and efficient for small data sets or nearly sorted data.

/// How Insertion Sort Works
// Iterate Through the List:
// Start from the second element (index 1) and iterate through each element.

/// Compare and Insert:
// For each element, compare it with the elements in the sorted part of the list (to its left).
// Shift all elements in the sorted part that are greater than the current element to the right.
// Insert the current element into its correct position in the sorted part.

/// Repeat the Process:
// Repeat the process for all elements in the list until the entire list is sorted.


// Example
// Consider the input array: [12, 11, 13, 5, 6]

/// Initial Input:
// arr = [12, 11, 13, 5, 6]

/// First Pass (i = 1):
// Current element: 11
// Compare with 12 and shift 12 to the right:
// arr = [11, 12, 13, 5, 6]
// Insert 11 in its correct position:
// arr = [11, 12, 13, 5, 6]

/// Second Pass (i = 2):
// Current element: 13
// Compare with 12 and 11 (no shifts needed):
// arr  = [11, 12, 13, 5, 6]

/// Third Pass (i = 3):
// Current element: 5

// Compare with 13, 12, and 11, and shift them to the right:
// arr = [ 11, 12, 13, 13, 6 ]
// arr = [ 11, 12, 12, 13, 6 ]
// arr = [ 11, 11, 12, 13, 6 ]

// Insert 5 in its correct position:
// arr = [5, 11, 12, 13, 6]

/// Fourth Pass (i = 4):
// Current element: 6

// Compare with 13, 12, and 11, and shift them to the right:
// arr = [ 5, 11, 12, 13, 13 ]
// arr = [ 5, 11, 12, 12, 13 ]
// arr = [ 5, 11, 11, 12, 13 ]

// Insert 6 in its correct position:
// arr = [5, 6, 11, 12, 13]

/// Final Output:
// arr = [5, 6, 11, 12, 13]


// Time and Space Complexity
/// Time Complexity:
// Best Case: (O(n)) when the array is already sorted.
// Average Case: (O(n^2)) due to the nested loops.
// Worst Case: (O(n^2)) when the array is sorted in reverse order.

/// Space Complexity: (O(1))
// Insertion Sort is an in-place sorting algorithm, meaning it requires only a constant amount of additional space.

/// Advantages and Disadvantages

/// Advantages:
// Simple to understand and implement.
// Efficient for small datasets or nearly sorted data.
// Stable sorting algorithm, meaning it maintains the relative order of equal elements.

/// Disadvantages:
// Inefficient for large datasets due to its (O(n^2)) time complexity.

/// Conclusion
// Insertion Sort is a straightforward sorting algorithm that is useful for educational purposes, small datasets, or nearly sorted data. However, due to its inefficiency with larger datasets, it is not recommended for use in performance-critical applications.

// Code

#include <bits/stdc++.h>
    using namespace std;

void insertionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
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

    insertionSort(arr);

    cout << "After Sorting: ";
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}


// Important tricky questions on sorting algorithms
// 1. What is the difference between stable and unstable sorting algorithms?
// ANSWER: A stable sorting algorithm is one that preserves the relative order of equal elements in the sorted output. In other words, if two elements have the same key value, their relative order in the input array is maintained in the sorted array. An unstable sorting algorithm, on the other hand, does not guarantee the preservation of the relative order of equal elements.

// 2. What is the time complexity of the best, average, and worst cases for the Bubble Sort algorithm?
// ANSWER: The time complexity of Bubble Sort is as follows:
// Best Case: O(n) when the array is already sorted.
// Average Case: O(n^2) due to the nested loops.
// Worst Case: O(n^2) when the array is sorted in reverse order.

// 3. What is the time complexity of the best, average, and worst cases for the Quick Sort algorithm?
// ANSWER: The time complexity of Quick Sort is as follows:
// Best Case: O(n log n) when the pivot element divides the array into two equal halves.
// Average Case: O(n log n) when the pivot element divides the array into two unequal halves.
// Worst Case: O(n^2) when the pivot element is the smallest or largest element in the array.

// 4. What is the time complexity of the best, average, and worst cases for the Merge Sort algorithm?
// ANSWER: The time complexity of Merge Sort is as follows:
// Best Case: O(n log n) due to the divide-and-conquer approach.
// Average Case: O(n log n) due to the divide-and-conquer approach.
// Worst Case: O(n log n) due to the divide-and-conquer approach.

// 5. What is the time complexity of the best, average, and worst cases for the Insertion Sort algorithm?
// ANSWER: The time complexity of Insertion Sort is as follows:
// Best Case: O(n) when the array is already sorted.
// Average Case: O(n^2) due to the nested loops.
// Worst Case: O(n^2) when the array is sorted in reverse order.

// 6. What is the time complexity of the best, average, and worst cases for the Selection Sort algorithm?
// ANSWER: The time complexity of Selection Sort is as follows:
// Best Case: O(n^2) due to the nested loops.
// Average Case: O(n^2) due to the nested loops.
// Worst Case: O(n^2) due to the nested loops.

// 7. Which sorting algorithms are considered stable sorting algorithms?
// ANSWER: The following sorting algorithms are considered stable:
// Bubble Sort
// Insertion Sort

// 8. Which sorting algorithms are considered unstable sorting algorithms?
// ANSWER: The following sorting algorithms are considered unstable:
// Quick Sort
// Merge Sort
// Selection Sort

// 9. Which is the most efficient sorting algorithm for large datasets?
// ANSWER: Merge Sort is considered one of the most efficient sorting algorithms for large datasets due to its (O(n log n)) time complexity.

// 10. Which sorting algorithm is recommended for educational purposes or small datasets?
// ANSWER: Insertion Sort is recommended for educational purposes or small datasets due to its simplicity and efficiency for nearly sorted data.

// 11. What is the best sorting algorithm for nearly sorted data and why?
// ANSWER: Insertion Sort is the best sorting algorithm for nearly sorted data because it is efficient in such cases and requires fewer comparisons and swaps compared to other sorting algorithms.

