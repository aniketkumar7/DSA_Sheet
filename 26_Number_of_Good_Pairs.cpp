// QUESTION: NUMBER OF GOOD PAIRS

// PROBLEM STATEMENT:
// Given an array of integers nums, return the number of good pairs.

// A pair (i, j) is called good if nums[i] == nums[j] and i < j.

// EXAMPLE:
// Input: nums = [1,2,3,1,1,3]
// Output: 4
// Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.


// SOLUTION :

#include <bits/stdc++.h>
using namespace std;

// Approach 1: Brute Force
// Time Complexity: O(n^2)
// Space Complexity: O(1)

int numIdenticalPairs1(vector<int>& nums) {
    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] == nums[j] && i < j) {
                count++;
            }
        }
    }
    return count;
}


// Approach 2: Hashing
// Time Complexity: O(n)
// Space Complexity: O(n)


int numIdenticalPairs(vector<int>& nums) {
    unordered_map<int, int> mp;
    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (mp.find(nums[i]) != mp.end()) {
            count += mp[nums[i]];
        }
        mp[nums[i]]++;
    }
    return count;
}


int main() {
    vector<int> nums = {1, 2, 3, 1, 1, 3};
    cout << "Number of good pairs: " << numIdenticalPairs(nums) << endl;
    return 0;
}


// DRY RUN:

// nums = [1, 2, 3, 1, 1, 3]

// Initialize an empty unordered_map mp and set count = 0.

// Start the loop: i = 0:
// nums[0] = 1
// 1 is not in mp
// Add 1 to mp: mp = {1: 1}
// count = 0

// i = 1:
// nums[1] = 2
// 2 is not in mp
// Add 2 to mp: mp = {1: 1, 2: 1}
// count = 0

// i = 2:
// nums[2] = 3
// 3 is not in mp
// Add 3 to mp: mp = {1: 1, 2: 1, 3: 1}
// count = 0

// i = 3:
// nums[3] = 1
// 1 is in mp
// count += mp[1] = 0 + 1 = 1
// Increment mp[1]: mp = {1: 2, 2: 1, 3: 1}
// count = 1

// i = 4:
// nums[4] = 1
// 1 is in mp
// count += mp[1] = 1 + 2 = 3
// Increment mp[1]: mp = {1: 3, 2: 1, 3: 1}
// count = 3

// i = 5:
// nums[5] = 3
// 3 is in mp
// count += mp[3] = 3 + 1 = 4
// Increment mp[3]: mp = {1: 3, 2: 1, 3: 2}
// count = 4