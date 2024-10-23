// Question: Insertion Sort

// Approach:
// Insertion sort is a simple sorting algorithm that works the way we sort playing cards in our hands.
// We start from the second element and compare it with the elements before it and place it in the correct position.
// Time Complexity: O(n^2)
// Space Complexity: O(1)

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

// Output:
// Before Sorting: 12 11 13 5 6
// After Sorting: 5 6 11 12 13

// How Insertion Sort Works:
// Insertion sort is a simple sorting algorithm that works the way we sort playing cards in our hands.
// We start from the second element and compare it with the elements before it and place it in the correct position.

// Let's understand how Insertion Sort works with an example:
// Consider an array {12, 11, 13, 5, 6}.

// First Pass:
// (12 11 13 5 6) -> (11 12 13 5 6) -> (11 12 13 5 6) -> (11 12 13 5 6) -> (5 11 12 13 6) -> (5 6 11 12 13)

// Second Pass:
// it will be same as first pass