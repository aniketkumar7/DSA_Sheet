// Question:  House Robber II
// Question URL: https://leetcode.com/problems/house-robber-ii/

// Problem Statement:
// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.



// Example 1:

// Input: nums = [2,3,2]
// Output: 3
// Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.


// Code:

#include <bits/stdc++.h>
using namespace std;

int Solve(int start, int end, vector<int> &nums)
{
    int n = nums.size();
    int prev = 0;
    int PrevPrev = 0;
    for (int i = start; i <= end; i++)
    {
        int skip = prev;
        int take = nums[i] + PrevPrev;

        // Take the maximum of the two
        int temp = max(skip, take);

        // Update the variables for the next iteration
        PrevPrev = prev;
        prev = temp;
    }
}

int rob(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return nums[0];
    if (n == 2)
        return max(nums[0], nums[1]);

    // if take the first house then we can't take the last house and vice versa
    int takeFirst = Solve(0, n - 2, nums);
    int skipFirst = Solve(1, n - 1, nums);

    return max(takeFirst, skipFirst);
}

int main()
{
    vector<int> nums = {2, 3, 2};
    cout << "Input: " ;
    for(int i=0;i<nums.size();i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    cout << "Output: ";
    cout << rob(nums) << endl;
    return 0;
}