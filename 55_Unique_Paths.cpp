// Question: Unique Paths
// Question URL: https://leetcode.com/problems/unique-paths/

// Problem Statement:
// There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

// Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

// The test cases are generated so that the answer will be less than or equal to 2 * 109.

// Example 1:
// Input: m = 3, n = 2
// Output: 3
// Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
// 1. Right -> Down -> Down
// 2. Down -> Down -> Right
// 3. Down -> Right -> Down

//Solution:

#include <bits/stdc++.h>
using namespace std;

// Recursion ke saath
int Solve(int m, int n, int i, int j)
{
    // Agar i or j m se bade ho jaye to 0 return karo
    if (i >= m || j >= n)
    {
        return 0;
    }

    // Agar i or j m-1 or n-1 ke barabar ho jaye to 1 return karo
    if (i == m - 1 && j == n - 1)
    {
        return 1;
    }

    // Right case
    int right = Solve(m, n, i, j + 1);
    // Down case
    int down = Solve(m, n, i + 1, j);
    return right + down;
}

int uniquePaths(int m, int n)
{
    return Solve(m, n, 0, 0);
}

// Memoization ke saath

int SolveMemo(int m, int n, int i, int j, vector<vector<int>> &dp)
{
    // Agar i or j m se bade ho jaye to 0 return karo
    if (i >= m || j >= n)
    {
        return 0;
    }

    // Agar i or j m-1 or n-1 ke barabar ho jaye to 1 return karo
    if (i == m - 1 && j == n - 1)
    {
        return 1;
    }

    // Agar dp me se answer mil jaye to return karo
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    // Right case
    int right = SolveMemo(m, n, i, j + 1, dp);
    // Down case
    int down = SolveMemo(m, n, i + 1, j, dp);
    return dp[i][j] = right + down;
}

int uniquePathsMemo(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return SolveMemo(m, n, 0, 0, dp);
}

// Tabulation ke saath

int uniquePathsTabulation(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[m - 1][n - 1] = 1;
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (i == m - 1 && j == n - 1)
            {
                continue;
            }
            int right = j + 1 < n ? dp[i][j + 1] : 0;
            int down = i + 1 < m ? dp[i + 1][j] : 0;
            dp[i][j] = right + down;
        }
    }
    return dp[0][0];
}


int main()
{
    int m = 7, n = 3;
    cout << "Input:" << endl;
    cout << "m = " << m << ", n = " << n << endl;
    cout << "Output:" << endl;
    cout << "Using Recursion:" << endl;
    cout << uniquePaths(m, n) << endl;
    cout << "Using Memoization:" << endl;
    cout << uniquePathsMemo(m, n) << endl;
    cout << "Using Tabulation:" << endl;
    cout << uniquePathsTabulation(m, n) << endl;
    return 0;
}


