// Question: Maximum Alternating Sequence Sum
// Question URL: https://leetcode.com/problems/maximum-alternating-subsequence-sum/


// Problem Statement:
// The alternating sum of a 0-indexed array is defined as the sum of the elements at even indices minus the sum of the elements at odd indices.
// For example, the alternating sum of [4,2,5,3] is (4 + 5) - (2 + 3) = 4.
// Given an array nums, return the maximum alternating sum of any subsequence of nums (after reindexing the elements of the subsequence).

// Example 1:
// Input: nums = [4,2,5,3]
// Output: 7
// Explanation: The subsequence [4,2,5] has an alternating sum of (4 + 5) - 2 = 7.

//Solution:

#include <bits/stdc++.h>
using namespace std;

// Recursion ke saath
int Solve(vector<int> &nums, bool isEven, int i)
{
    int n = nums.size();

    // Agar index n se bada ya barabar ho jaye to 0 return karo
    if (i >= n)
    {
        return 0;
    }

    // Not take case
    long long notTake = Solve(nums, isEven, i + 1);
    int val = isEven ? nums[i] : -nums[i];
    // Take case
    long long take = val + Solve(nums, !isEven, i + 1);
    return max(take, notTake);
}

long long maxAlternatingSum(vector<int> &nums)
{
    int n = nums.size();
    // Agar sirf ek element ho to wahi return karo
    if (n == 1)
    {
        return nums[0];
    }
    return Solve(nums, true, 0);
}

// Memoization ke saath
long long SolveMemo(vector<int> &nums, bool isEven, int i, vector<vector<long long>> &dp)
{
    int n = nums.size();

    // Agar index n se bada ya barabar ho jaye to 0 return karo
    if (i >= n)
    {
        return 0;
    }

    // Agar dp mein value already hai to wahi return karo
    if (dp[i][isEven] != -1)
    {
        return dp[i][isEven];
    }

    // Not take case
    long long notTake = SolveMemo(nums, isEven, i + 1, dp);
    int val = isEven ? nums[i] : -nums[i];
    // Take case
    long long take = val + SolveMemo(nums, !isEven, i + 1, dp);
    return dp[i][isEven] = max(take, notTake);
}

long long maxAlternatingSumMemo(vector<int> &nums)
{
    int n = nums.size();
    // Agar sirf ek element ho to wahi return karo
    if (n == 1)
    {
        return nums[0];
    }
    vector<vector<long long>> dp(n, vector<long long>(2, -1));
    return SolveMemo(nums, true, 0, dp);
}

// DP ke saath
long long maxAlternatingSumDP(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        dp[i][1] = max(nums[i] + dp[i + 1][0], dp[i + 1][1]);  // Even index
        dp[i][0] = max(-nums[i] + dp[i + 1][1], dp[i + 1][0]); // Odd index
    }

    return dp[0][1]; // Starting from even index
}

int main() {
    vector<int> nums = {4, 2, 5, 3};
    cout << "Input:" << endl;
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    cout << "Output: " << maxAlternatingSum(nums) << endl;
    return 0;
}
