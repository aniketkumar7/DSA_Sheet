// QUESTION : MAXIMUM COUNT OF POSITIVE INTEGER AND NEGATIVE INTEGER

// PROBLEM STATEMENT:
// Given an array nums sorted in non-decreasing order, return the maximum between the number of positive integers and the number of negative integers.

// In other words, if the number of positive integers in nums is pos and the number of negative integers is neg, then return the maximum of pos and neg.
// Note that 0 is neither positive nor negative.

// Example 1:
// Input: nums = [-2,-1,-1,1,2,3]
// Output: 3
// Explanation: There are 3 positive integers and 3 negative integers. The maximum count among them is 3.

// Constraints:

// 1 <= nums.length <= 100
// -100 <= nums[i] <= 100
// nums is sorted in non-decreasing order.


// ALGORITHM:
// 1. Traverse the array and count the number of positive and negative integers in the array.
// 2. Return the maximum between the number of positive integers and the number of negative integers.

// SOLUTION:

#include <iostream>
#include <vector>
using namespace std;

// Approach 1: Brute Force
int maximumCount(vector<int> &nums)
{
    int pos = 0, neg = 0;
    for (int num : nums)
    {
        if (num > 0)
        {
            pos++;
        }
        else if (num < 0)
        {
            neg++;
        }
    }
    return max(pos, neg);
}


// MAIN FUNCTION
int main()
{
    vector<int> nums = {-3, -2, -1, 0, 0, 1, 2};
    cout << "Input: " << endl;

    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    cout << "Maximum count: " << maximumCount(nums) << endl;
    return 0;
}