// Question:  Selection Sort

// Selection sort is a simple sorting algorithm. This sorting algorithm is an in-place comparison-based algorithm in which the list is divided into two parts, the sorted part at the left end and the unsorted part at the right end. Initially, the sorted part is empty, and the unsorted part is the entire list.

// The smallest element is selected from the unsorted array and swapped with the leftmost element, and that element becomes a part of the sorted array. This process continues moving unsorted array boundary by one element to the right.

// This algorithm is not suitable for large data sets as its average and worst-case complexities are of Ο(n2), where n is the number of items.

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