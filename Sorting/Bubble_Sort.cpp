// Question: Bubble Sort

// Approach:
// Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in the wrong order.

// Time Complexity: O(n^2)
// Space Complexity: O(1)

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