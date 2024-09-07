// QUESTION: SEARCH IN 2D MATRIX
// QUESTION LINK: https://leetcode.com/problems/search-a-2d-matrix/


// PROBLEM STATEMENT:
// You are given an m x n integer matrix matrix with the following two properties:

// Each row is sorted in non-decreasing order.
// The first integer of each row is greater than the last integer of the previous row.
// Given an integer target, return true if target is in matrix or false otherwise.

// You must write a solution in O(log(m * n)) time complexity.


// Example: 1
// Input : matrix = [ [ 1, 3, 5, 7 ], [ 10, 11, 16, 20 ], [ 23, 30, 34, 60 ] ], target = 3
// Output : true

// SOLUTION:

#include<bits/stdc++.h>
using namespace std;


// Approach: 1

bool searchMatrix1(vector<vector<int>>& matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == target)
                return true;
        }
    }
    return false;
}



// Approach: 2

bool searchMatrix2(vector<vector<int>>& matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int i = 0, j = m - 1;
    while (i < n && j >= 0)
    {
        if (matrix[i][j] == target)
            return true;
        else if (matrix[i][j] < target)
            i++;
        else
            j--;
    }
    return false;
}


// Approach: 3

bool searchMatrix(vector<vector<int>>& matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int low = 0, high = (n * m) - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int row = mid / m;
        int col = mid % m;
        if (matrix[row][col] == target)
            return true;
        else if (matrix[row][col] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = { { 1, 3, 5, 7 }, { 10, 11, 16, 20 }, { 23, 30, 34, 60 } };
    cout << "Input: " << endl;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    int target = 3;
    cout << "Target: " << target << endl;

    cout << "Output: ";
    cout << searchMatrix(matrix, target) << endl;
    return 0;
}

// TIME COMPLEXITY : O(log(m*n))
// SPACE COMPLEXITY : O(1)
