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

// Sure, let's dry run the provided code with an example. Let's consider coins = [1, 2, 5] and amount = 11.

// First, we call coinChange2(coins, 11), which internally calls findLowestCoins(coins, 0, 11).

// Inside findLowestCoins(coins, 0, 11):

// cur = 0, coins.size() = 3, and amount = 11, so we proceed to the next step.

// coins[cur] = coins[0] = 1, which is not greater than amount = 11, so we go to the else block.

// Inside the else block:

// We make a recursive call takeCoin = 1 + findLowestCoins(coins, 0, 11 - 1) = 1 + findLowestCoins(coins, 0, 10).

// Inside findLowestCoins(coins, 0, 10):

// cur = 0, coins.size() = 3, and amount = 10, so we proceed to the next step.

// coins[cur] = coins[0] = 1, which is not greater than amount = 10, so we go to the else block.

// Inside the else block:

// We make a recursive call takeCoin = 1 + findLowestCoins(coins, 0, 10 - 1) = 1 + findLowestCoins(coins, 0, 9).

// ... (skipping some steps for brevity) ...

// After several recursive calls, we eventually reach findLowestCoins(coins, 0, 0), which returns 0 (base case).

// Going back up the recursive calls, we get takeCoin = 10 for findLowestCoins(coins, 0, 10).

// We also make a recursive call doNotTakeCoin = 0 + findLowestCoins(coins, 1, 10).

// Inside findLowestCoins(coins, 1, 10):

// cur = 1, coins.size() = 3, and amount = 10, so we proceed to the next step.

// coins[cur] = coins[1] = 2, which is not greater than amount = 10, so we go to the else block.

// Inside the else block:

// We make a recursive call takeCoin = 1 + findLowestCoins(coins, 1, 10 - 2) = 1 + findLowestCoins(coins, 1, 8).

// ... (skipping some steps for brevity) ...

// After several recursive calls, we get takeCoin = 5 for findLowestCoins(coins, 1, 10).

// We also make a recursive call doNotTakeCoin = 0 + findLowestCoins(coins, 2, 10).

// Inside findLowestCoins(coins, 2, 10):

// cur = 2, coins.size() = 3, and amount = 10, so we proceed to the next step.

// coins[cur] = coins[2] = 5, which is not greater than amount = 10, so we go to the else block.

// Inside the else block:

// We make a recursive call takeCoin = 1 + findLowestCoins(coins, 2, 10 - 5) = 1 + findLowestCoins(coins, 2, 5).

// ... (skipping some steps for brevity) ...

// After several recursive calls, we get takeCoin = 2 for findLowestCoins(coins, 2, 10).

// We also make a recursive call doNotTakeCoin = 0 + findLowestCoins(coins, 3, 10).

// Since cur = 3 and coins.size() = 3, we hit the base case and return INT_MAX - 1.

// Therefore, doNotTakeCoin = INT_MAX - 1 for findLowestCoins(coins, 2, 10).

// We take the minimum of takeCoin and doNotTakeCoin, which is min(2, INT_MAX - 1) = 2.

// Back in findLowestCoins(coins, 1, 10), we take the minimum of takeCoin and doNotTakeCoin, which is min(5, 2) = 2. [1]

// Back in findLowestCoins(coins, 0, 10), we take the minimum of takeCoin and doNotTakeCoin, which is min(10, 2) = 2.

// Back in findLowestCoins(coins, 0, 11), takeCoin = 2 + 1 = 3.

// We also make a recursive call doNotTakeCoin = 0 + findLowestCoins(coins, 1, 11).

// Inside findLowestCoins(coins, 1, 11):

// cur = 1, coins.size() = 3, and amount = 11, so we proceed to the next step.

// coins[cur] = coins[1] = 2, which is not greater than amount = 11, so we go to the else block.

// Inside the else block:

// We make a recursive call takeCoin = 1 + findLowestCoins(coins, 1, 11 - 2) = 1 + findLowestCoins(coins, 1, 9).

// ... (skipping some steps for brevity) ...

// After several recursive calls, we get takeCoin = 6 for findLowestCoins(coins, 1, 11).

// We also make a recursive call doNotTakeCoin = 0 + findLowestCoins(coins, 2, 11).

// Inside findLowestCoins(coins, 2, 11):

// cur = 2, coins.size() = 3, and amount = 11, so we proceed to the next step.

// coins[cur] = coins[2] = 5, which is not greater than amount = 11, so we go to the else block.

// Inside the else block:

// We make a recursive call takeCoin = 1 + findLowestCoins(coins, 2, 11 - 5) = 1 + findLowestCoins(coins, 2, 6).

// ... (skipping some steps for brevity) ...

// After several recursive calls, we get takeCoin = 3 for findLowestCoins(coins, 2, 11).

// We also make a recursive call doNotTakeCoin = 0 + findLowestCoins(coins, 3, 11).

// Since cur = 3 and coins.size() = 3, we hit the base case and return INT_MAX - 1.

// Therefore, doNotTakeCoin = INT_MAX - 1 for findLowestCoins(coins, 2, 11).

// We take the minimum of takeCoin and doNotTakeCoin, which is min(3, INT_MAX - 1) = 3.

// Back in findLowestCoins(coins, 1, 11), we take the minimum of takeCoin and doNotTakeCoin, which is min(6, 3) = 3.

// Back in findLowestCoins(coins, 0, 11), we take the minimum of takeCoin and doNotTakeCoin, which is min(3, 3) = 3.

// Therefore, the final result is 3, which is the minimum number of coins needed to make the change for 11.






// We initialize n = 3 (the size of the coins vector) and create a vector dp of size amount + 1 = 12 with all elements initialized to INT_MAX. We also set dp[0] = 0.

// We start the outer loop with i = 1:

// For i = 1:

// We start the inner loop with j = 0:

// coins[j] = coins[0] = 1, which is less than or equal to i = 1.

// sub_res = dp[1 - 1] = dp[0] = 0, which is not equal to INT_MAX.

// dp[1] = min(dp[1], sub_res + 1) = min(INT_MAX, 0 + 1) = 1.

// For j = 1:

// coins[j] = coins[1] = 2, which is greater than i = 1, so we skip this iteration.

// For j = 2:

// coins[j] = coins[2] = 5, which is greater than i = 1, so we skip this iteration.

// After the inner loop, dp[1] = 1.

// For i = 2:

// For j = 0:

// coins[j] = coins[0] = 1, which is less than or equal to i = 2.

// sub_res = dp[2 - 1] = dp[1] = 1, which is not equal to INT_MAX.

// dp[2] = min(dp[2], sub_res + 1) = min(INT_MAX, 1 + 1) = 2.

// For j = 1:

// coins[j] = coins[1] = 2, which is less than or equal to i = 2.

// sub_res = dp2 - 2 = dp0 = 0 , which is not equal to INT_MAX`.

// dp[2] = min(dp[2], sub_res + 1) = min(2, 0 + 1) = 1.

// For j = 2:

// coins[j] = coins[2] = 5, which is greater than i = 2, so we skip this iteration.

// After the inner loop, dp[2] = 1.

// ... (skipping some steps for brevity) ...

// For i = 11:

// For j = 0:

// coins[j] = coins[0] = 1, which is less than or equal to i = 11.

// sub_res = dp[11 - 1] = dp[10] = 10, which is not equal to INT_MAX.

// dp[11] = min(dp[11], sub_res + 1) = min(INT_MAX, 10 + 1) = 11.

// For j = 1:

// coins[j] = coins[1] = 2, which is less than or equal to i = 11.

// sub_res = dp[11 - 2] = dp[9] = 9, which is not equal to INT_MAX.

// dp[11] = min(dp[11], sub_res + 1) = min(11, 9 + 1) = 10.

// For j = 2:

// coins[j] = coins[2] = 5, which is less than or equal to i = 11.

// sub_res = dp[11 - 5] = dp[6] = 2, which is not equal to INT_MAX.

// dp[11] = min(dp[11], sub_res + 1) = min(10, 2 + 1) = 3.

// After the inner loop, dp[11] = 3.

// Finally, we return dp[amount] = dp[11] = 3, which is the correct minimum number of coins needed to make the change for 11.