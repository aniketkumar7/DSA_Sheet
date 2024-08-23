// QUESTION: Longest Increasing Subsequence

#include <bits/stdc++.h>
using namespace std;


// Solution with Brute Force

int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    int maxLen = 1;

    for (int i = 0; i < n; i++)
    {
        int currLen = 1;
        int prev = nums[i];

        for (int j = i + 1; j < n; j++)
        {
            if (nums[j] > prev)
            {
                currLen++;
                prev = nums[j];
            }
        }

        maxLen = max(maxLen, currLen);
    }

    return maxLen;
}


// Solution with DP

int lengthOfLISDP(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 1);

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}


int main()
{
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "Input array: " << endl;

    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    cout << "Length of Longest Increasing Subsequence with Brute Force: " << lengthOfLIS(nums) << endl;

    cout << "Length of Longest Increasing Subsequence with DP: " << lengthOfLISDP(nums) << endl;
}