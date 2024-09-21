// Question: Subsets
// Question Link: https://leetcode.com/problems/subsets/


// Problem Statement:
// Given an integer array nums of unique elements, return all possible subsets (the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order.

// Example 1:
// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
// Example 2:
// Input: nums = [0]
// Output: [[],[0]]

// Solution:

#include <bits/stdc++.h>
using namespace std;


// Approach 1: Brute Force
void solve(vector<int> &nums, int index, vector<int> &output, vector<vector<int>> &result)
{
    if (index >= nums.size())
    {
        result.push_back(output);
        return;
    }

    // Include the current element
    int element = nums[index];
    output.push_back(element);
    solve(nums, index + 1, output, result);
    output.pop_back();

    // Exclude the current element
    solve(nums, index + 1, output, result);
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> result;
    vector<int> output;
    int index = 0;
    solve(nums, index, output, result);
    return result;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    cout << "Input: " << endl;
    for (auto i : nums)
    {
        cout << i << " ";
    }
    vector<vector<int>> result = subsets(nums);
    cout << "\nOutput: " << endl;
    for (auto i : result)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}