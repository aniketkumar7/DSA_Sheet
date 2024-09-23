// Question: Permutations
// Question URL: https://leetcode.com/problems/permutations/

// Problem Statement:
// Given an array nums of distinct integers, return all the possible
// permutations. You can return the answer in any order.



// Example 1:

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// Example 2:

// Input: nums = [0,1]
// Output: [[0,1],[1,0]]

// Constraints:

// 1 <= nums.length <= 6
// -10 <= nums[i] <= 10
// All the integers of nums are unique.

// Solution:

#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> nums, int index, vector<vector<int>> &ans) {
    if (index == nums.size()) {
        ans.push_back(nums);
        return;
    }
    for (int i = index; i < nums.size(); i++) {
        swap(nums[index], nums[i]);
        solve(nums, index + 1, ans);
        swap(nums[index], nums[i]);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    solve(nums, 0, ans);
    return ans;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = permute(nums);
    for (auto v : ans) {
        for (int i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}