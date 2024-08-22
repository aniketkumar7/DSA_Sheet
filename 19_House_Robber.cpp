// QUESTION : House Robber

// PROBLEM STATEMENT:
// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.


// Example 1:

// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.


// Solution:

#include <bits/stdc++.h>
using namespace std;

// Approach: Recursion
// Time Complexity: O(2^N)
// Space Complexity: O(N)


int robBruteForce(vector<int> &nums, int i)
{
    if (i >= nums.size())
        return 0;

    // Take or not take
    int take = nums[i] + robBruteForce(nums, i + 2);
    int notTake = robBruteForce(nums, i + 1);

    return max(take, notTake);
}


// Approach: Memoization
// Time Complexity: O(N)
// Space Complexity: O(N)

int robMemo(vector<int> &nums, int i)
{
    vector<int> dp(nums.size(), -1);
    if (i >= nums.size())
        return 0;

    if (dp[i] != -1)
        return dp[i];

    int take = nums[i] + robMemo(nums, i + 2);
    int notTake = robMemo(nums, i + 1);

    return dp[i] = max(take, notTake);
}

// Approach: Tabulation or Bottom Up
// Time Complexity: O(N)
// Space Complexity: O(N)

int robDp2(vector<int> &nums)
{
    int n = nums.size();

    // base case
    if (n == 1)
    {
        return nums[0];
    }

    // dp
    vector<int> dp(n, 0);

    // dp[0] stores the maximum amount if only the first house is considered.
    // dp[1] stores the maximum amount if the robber either robs the first or the second house, whichever gives more money.
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    // Rob the i-th house and add its loot to the maximum amount that could be accumulated until two houses before (nums[i] + dp[i-2]).
    for (int i = 2; i < n; i++)
    {
        dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
    }

    return dp[n - 1];
}



// Approach: Space Optimization
// Time Complexity: O(N)
// Space Complexity: O(1)


int rob(vector<int> &nums)
{
    int n = nums.size();
    int prev2 = 0;
    int prev = nums[0];
    for (int i = 1; i < n; i++)
    {
        int take = nums[i] + prev2;
        int notTake = prev;
        int curri = max(take, notTake);
        prev2 = prev;
        prev = curri;
    }
    return prev;
}

int main()
{
    vector<int> nums = {1, 2, 3, 1, 2, 5, 3, 4};

    cout << "Input: " << endl;

    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    cout << "Maximum loot that can be robbed with recursion: " << robBruteForce(nums, 0) << endl;

    cout << "Maximum loot that can be robbed with memoization: " << robMemo(nums, 0) << endl;

    cout << "Maximum loot that can be robbed with tabulation or bottom up " << robDp2(nums) << endl;


    cout << "Maximum loot that can be robbed with space optimization " << rob(nums) << endl;
    return 0;
}