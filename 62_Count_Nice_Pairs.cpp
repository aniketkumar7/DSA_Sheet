// Question:  Count Nice Pairs in an Array
// Question link: https://leetcode.com/problems/count-nice-pairs-in-an-array/

// Problem Statement:
// You are given an array nums that consists of non-negative integers. Let us define rev(x) as the reverse of the non-negative integer x. For example, rev(123) = 321, and rev(120) = 21. A pair of indices (i, j) is nice if it satisfies all of the following conditions:
// i < j
// nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])
// Return the number of nice pairs of indices. Since the answer can be very large, return it modulo 109 + 7.

// Example 1:
// Input: nums = [42,11,1,97]
// Output: 2
// Explanation: The two pairs are:
// - (0, 3) : 42 + rev(97) = 42 + 79 = 121, 97 + rev(42) = 97 + 24 = 121.
// - (1, 2) : 11 + rev(1) = 11 + 1 = 12, 1 + rev(11) = 1 + 11 = 12.

// Example 2:
// Input: nums = [13,10,35,24,76]
// Output: 4

/// Pattern Suggestion:
// In this problem, we can take the ith element on the left side and the reverse of the jth element on the right side. We can then calculate the difference between the two elements and store it in a map.
/// Like nums[i] - rev(nums[j]) = nums[j] - rev(nums[i])

// Code:

#include <bits/stdc++.h>
using namespace std;

int CountNicePairs(vector<int>& nums) {
    int mod = 1000000007;
    int n = nums.size();
    unordered_map<int, int> mp;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int rev = 0;
        int temp = nums[i];

        // Reversing the number
        while (temp > 0) {
            rev = rev * 10 + temp % 10;
            temp /= 10;
        }

        // Calculating the difference
        int diff = nums[i] - rev;

        // check if the difference is already present in the map
        // if yes, then add the value of the difference to the answer
        ans = (ans + mp[diff]) % mod;

        // increment the value of the difference in the map
        mp[diff]++;
    }
    return ans;
}

int main() {
    vector<int> nums = {42, 11, 1, 97};
    cout << "Input: ";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    cout << "Output: ";
    cout << CountNicePairs(nums) << endl;
    return 0;
}




// Time and Space Complexity


///Time Complexity: O(n log n)
// The time complexity is O(n) for the outer loop and O(log n) for reversing the number. The space complexity of the solution is O(n) where n is the size of the input array nums.

/// Space Complexity: O(n)
// The space complexity is O(n) for storing the differences in the map.