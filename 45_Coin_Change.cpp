// Question: Coin Change
// Question Link: https://leetcode.com/problems/coin-change/

// PROBLEM STATEMENT:

// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

// You may assume that you have an infinite number of each kind of coin.

// Example 1:

// Input: coins = [1,2,5], amount = 11
// Output: 3
// Explanation: 11 = 5 + 5 + 1

// Solution:

#include <bits/stdc++.h>
using namespace std;


// Approach 1: Brute Force

int coinChange(vector<int> &coins, int amount)
{
    // Base case: If the amount is 0, no coins are needed
    if (amount == 0)
    {
        return 0;
    }

    int res = INT_MAX; // Initialize res to a large value

    for (int coin : coins)
    {
        if (coin <= amount)
        {
            // Recursive call to find the minimum number of coins for the remaining amount
            int sub_res = coinChange(coins, amount - coin);

            // If a valid solution exists for the remaining amount
            if (sub_res != INT_MAX)
            {
                // Update res with the minimum value
                res = min(res, sub_res + 1);
            }
        }
    }

    // If no valid solution is found, return INT_MAX
    return res == INT_MAX ? INT_MAX : res;
}

// Time Complexity: O(n * amount)
// Space Complexity: O(amount)





// Approach 2: recursion (optimised)

int findLowestCoins(vector<int> &coins, int cur, int amount)
{
    if (cur >= coins.size() || amount <= 0)
        return (amount == 0) ? 0 : INT_MAX - 1;

    int res = -1;
    if (coins[cur] > amount)
    {
        int doNotTakeCoin = 0 + findLowestCoins(coins, cur + 1, amount - 0);
        res = doNotTakeCoin;
    }
    else
    {
        int takeCoin = 1 + findLowestCoins(coins, cur + 0, amount - coins[cur]);
        int doNotTakeCoin = 0 + findLowestCoins(coins, cur + 1, amount - 0);
        res = min(takeCoin, doNotTakeCoin);
    }
    return res;
}

int coinChange2(vector<int> &coins, int amount)
{
    int res = findLowestCoins(coins, 0, amount);
    return (res == INT_MAX - 1) ? -1 : res;
}







// Approach 2: Dynamic Programming

int coinChange3(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (coins[j] <= i)
            {
                int sub_res = dp[i - coins[j]];
                if (sub_res != INT_MAX)
                {
                    dp[i] = min(dp[i], sub_res + 1);
                }
            }
        }
    }

    return dp[amount] == INT_MAX ? -1 : dp[amount];
}


int main()
{
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    cout << coinChange(coins, amount) << endl;
    cout << coinChange2(coins, amount) << endl;
    cout << coinChange3(coins, amount) << endl;
    return 0;
}
