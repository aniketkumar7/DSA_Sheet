// QUESTION: CLIMBING STAIRS
// QUESTION LINK : https://leetcode.com/problems/climbing-stairs/

// PROBLEM STATEMENT:
// You are climbing a staircase. It takes n steps to reach the top.
// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

// EXAMPLE:
// Input: n = 2
// Output: 2
// Explanation: There are two ways to climb to the top.
// 1. 1 step + 1 step
// 2. 2 steps

// SOLUTION:

#include <bits/stdc++.h>
using namespace std;

// Approach 1: Brute Force
// Time Complexity: O(2^n)
// Space Complexity: O(n)


int climbStairs(int n)
{

    if (n == 0 || n == 1)
        return 1;

    return climbStairs(n - 1) + climbStairs(n - 2);
}
// Give time exceed Limit


// Approach 2: Dynamic Programming
// Time Complexity: O(n)
// Space Complexity: O(n)


    int climbStairsDP(int n)
    {
        if (n == 0 || n == 1)
        {
            return 1;
        }

        vector<int> dp(n + 1);
        dp[0] = dp[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }


// Approach 3: Fibonacci Number
// Time Complexity: O(n)
// Space Complexity: O(1)

int climbStairsFibonacci(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }

    int prev = 1, curr = 1;

    for (int i = 2; i <= n; i++)
    {
        int temp = curr;
        curr = prev + curr;
        prev = temp;
    }
    return curr;
}


// MAIN FUNCTION
int main()
{
    int n;
    cin >> n;
    cout << climbStairs(n) << endl;
    cout << climbStairsDP(n) << endl;
    cout << climbStairsFibonacci(n) << endl;
    return 0;
}