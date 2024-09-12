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

// Approach 1: Linear Search
int findMinMaxPages(const vector<int> &bookPages, int numStudents)
{
    int numBooks = bookPages.size();
    int totalPages = 0;
    int maxBookPages = 0;

    for (int pages : bookPages)
    {
        totalPages += pages;
        maxBookPages = max(maxBookPages, pages);
    }

    if (numStudents > numBooks)
        return -1;

    for (int maxAllocation = maxBookPages; maxAllocation <= totalPages; maxAllocation++)
    {
        int studentsRequired = 1;
        int pagesAllocated = 0;

        for (int pages : bookPages)
        {
            if (pagesAllocated + pages > maxAllocation)
            {
                studentsRequired++;
                pagesAllocated = pages;
            }
            else
            {
                pagesAllocated += pages;
            }
        }

        if (studentsRequired <= numStudents)
        {
            return maxAllocation;
        }
    }

    return -1;
}

// Approach 2: Binary Search
bool isValidAllocation(const vector<int> &bookPages, int numBooks, int numStudents, int maxPages)
{
    int studentsRequired = 1;
    int pagesAllocated = 0;

    for (int i = 0; i < numBooks; i++)
    {
        if (pagesAllocated + bookPages[i] > maxPages)
        {
            studentsRequired++;
            pagesAllocated = bookPages[i];
        }
        else
        {
            pagesAllocated += bookPages[i];
        }
    }

    return studentsRequired <= numStudents;
}

int allocateBooksBinarySearch(const vector<int> &bookPages, int numStudents)
{
    int numBooks = bookPages.size();
    int totalPages = 0;
    int result = -1;

    if (numBooks < numStudents)
        return -1;

    for (int pages : bookPages)
    {
        totalPages += pages;
    }

    int minPages = *max_element(bookPages.begin(), bookPages.end());
    int maxPages = totalPages;

    while (minPages <= maxPages)
    {
        int midPages = minPages + (maxPages - minPages) / 2;

        if (isValidAllocation(bookPages, numBooks, numStudents, midPages))
        {
            result = midPages;
            maxPages = midPages - 1;
        }
        else
        {
            minPages = midPages + 1;
        }
    }

    return result;
}

int main()
{
    vector<int> bookPages = {24, 46, 26, 15, 18, 19, 20, 21, 22} ;
    cout << "Book Pages: ";
    for (int pages : bookPages)
    {
        cout << pages << " ";
    }
    int numStudents = 4;
    cout << "\nNumber of Students: " << numStudents << endl;

    cout << "Binary Search Result: " << allocateBooksBinarySearch(bookPages, numStudents) << endl;
    cout << "Linear Search Result: " << findMinMaxPages(bookPages, numStudents) << endl;

    return 0;
}
