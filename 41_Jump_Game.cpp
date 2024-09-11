// Question: Jump Game
// Question Link: https://leetcode.com/problems/jump-game/

// Problem Statement:
// Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

// Return true if you can jump to the last index, or false otherwise.

// Example 1:
// Input: nums = [2,3,1,1,4]
// Output: true
// Explanation: You can jump 1 step from index 0 to 1, then 3 steps to the last index.

// Solution:
#include <iostream>
#include <vector>
using namespace std;


bool canJump(vector<int>& nums) {
    int n = nums.size();

    // base case
    if (n == 1)
        return true;

    int reachable = 0;
    for (int i = 0; i < n; i++) {
        if (i > reachable)
        return false;
        reachable = max(reachable, i + nums[i]);
    }
    return true;
}

int main()
{
    vector<int> nums = {2,3,1,1,4};
    cout << "Input: " << endl;
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    cout << "Output: " << endl;
    if(canJump(nums))
        cout << "It is possible to jump to the last index." << endl;
    else
        cout << "It is not possible to jump to the last index." << endl;
    return 0;
}