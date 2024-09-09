// Question: Book Allocation
// Question Link: https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1

// Problem Statement:
// You have n books, each with arr[i] a number of pages. m students need to be allocated contiguous books, with each student getting at least one book.
// Out of all the permutations, the goal is to find the permutation where the sum of the maximum number of pages in a book allotted to a student should be the minimum, out of all possible permutations.

// Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).

// Example :
// Input: n = 4, arr[] = [12, 34, 67, 90], m = 2
// Output: 113
// Explanation: Allocation can be done in following ways:
// {12} and {34, 67, 90} Maximum Pages = 191
// {12, 34} and {67, 90} Maximum Pages = 157
// {12, 34, 67} and {90} Maximum Pages =113.
// Therefore, the minimum of these cases is 113, which is selected as the output

// Solution:
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isValid(vector<int> &pages, int n, int m, int mid)
{
    int students = 1;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (sum + pages[i] > mid)
        {
            students++;
            sum = pages[i];
        }
        else
        {
            sum += pages[i];
        }
    }

    return students <= m;
}

int allocateBooks(vector<int> &pages, int m)
{
    int n = pages.size();
    int sum = 0;
    int result = -1;

    if (n < m)
    {
        return -1;
    }

    for (int page : pages)
    {
        sum += page;
    }

    int low = *max_element(pages.begin(), pages.end());
    int high = sum;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (isValid(pages, n, m, mid))
        {
            result = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return result;
}

int main()
{
    vector<int> pages = {12, 34, 67, 90};
    int m = 2;

    cout << allocateBooks(pages, m) << endl;

    return 0;
}
