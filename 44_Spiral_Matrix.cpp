// Question: Spiral Matrix
// Question Link: https://leetcode.com/problems/spiral-matrix/description/

// PROBLEM STATEMENT:
// Given an m x n matrix, return all elements of the matrix in spiral order.

// Example 1:

// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,3,6,9,8,7,4,5]

// Solution:
#include <bits/stdc++.h>
using namespace std;

// Function to generate the spiral order of a matrix
vector<int> generateSpiralOrder(vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<int> spiralOrder;
    int direction = 0; // 0: left to right, 1: top to bottom, 2: right to left, 3: bottom to top
    int topRow = 0, bottomRow = rows - 1, leftCol = 0, rightCol = cols - 1;

    while (topRow <= bottomRow && leftCol <= rightCol)
    {
        // Traverse from left to right
        if (direction == 0)
        {
            for (int col = leftCol; col <= rightCol; col++)
            {
                spiralOrder.push_back(matrix[topRow][col]);
            }
            topRow++;
        }

        // Traverse from top to bottom
        else if (direction == 1)
        {
            for (int row = topRow; row <= bottomRow; row++)
            {
                spiralOrder.push_back(matrix[row][rightCol]);
            }
            rightCol--;
        }

        // Traverse from right to left
        else if (direction == 2)
        {
            for (int col = rightCol; col >= leftCol; col--)
            {
                spiralOrder.push_back(matrix[bottomRow][col]);
            }
            bottomRow--;
        }

        // Traverse from bottom to top
        else if (direction == 3)
        {
            for (int row = bottomRow; row >= topRow; row--)
            {
                spiralOrder.push_back(matrix[row][leftCol]);
            }
            leftCol++;
        }

        // Update the direction
        direction = (direction + 1) % 4;
    }

    return spiralOrder;
}

// Function to generate the spiral order of a matrix
vector<int> generateSpiralOrder(const vector<vector<int>> &matrix)
{
    vector<int> spiralOrder;
    int rows = matrix.size();
    int cols = matrix[0].size();

    int topRow = 0, bottomRow = rows - 1;
    int leftCol = 0, rightCol = cols - 1;

    while (topRow <= bottomRow && leftCol <= rightCol)
    {
        // Traverse top row from left to right
        for (int col = leftCol; col <= rightCol; col++)
        {
            spiralOrder.push_back(matrix[topRow][col]);
        }
        topRow++;

        // Traverse right column from top to bottom
        for (int row = topRow; row <= bottomRow; row++)
        {
            spiralOrder.push_back(matrix[row][rightCol]);
        }
        rightCol--;

        // Traverse bottom row from right to left (if there are remaining rows)
        if (topRow <= bottomRow)
        {
            for (int col = rightCol; col >= leftCol; col--)
            {
                spiralOrder.push_back(matrix[bottomRow][col]);
            }
            bottomRow--;
        }

        // Traverse left column from bottom to top (if there are remaining columns)
        if (leftCol <= rightCol)
        {
            for (int row = bottomRow; row >= topRow; row--)
            {
                spiralOrder.push_back(matrix[row][leftCol]);
            }
            leftCol++;
        }
    }

    return spiralOrder;
}

int main()
{
    int rows, cols;
    cout << "Enter the number of rows and columns: ";
    cin >> rows >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));
    cout << "Enter the matrix elements: " << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> matrix[i][j];
        }
    }

    vector<int> spiralOrder = generateSpiralOrder(matrix);
    cout << "Spiral order of the matrix: ";
    for (int num : spiralOrder)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}