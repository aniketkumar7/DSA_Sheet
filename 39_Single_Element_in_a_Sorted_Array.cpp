// Question: Single Element in a Sorted Array
// Question Link: https://leetcode.com/problems/single-element-in-a-sorted-array/


// Problem Statement:
// You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

// Example 1:

// Input: [1,1,2,3,3,4,4,8,8]
// Output: 2

// Solution:
#include <bits/stdc++.h>
using namespace std;



int singleNonDuplicate1(vector<int> &nums)
{
    int n = nums.size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans ^= nums[i];
    }
    return ans;
}



int singleNonDuplicate2(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i += 2)
    {
        if (i == nums.size() - 1 || nums[i] != nums[i + 1])
        {
            return nums[i];
        }
    }
    return -1;
}


int singleNonDuplicate3(vector<int> &nums)
{
    int n = nums.size();
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (mid % 2 == 1)
            mid--;
        if (nums[mid] == nums[mid + 1])
            low = mid + 2;
        else
            high = mid - 1;
    }
    return nums[low];
}


int main()
{
    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    cout << "Input: " << endl;
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }

    cout << "\nOutput: " << endl;
    cout << singleNonDuplicate1(nums) << endl;
    cout << singleNonDuplicate2(nums) << endl;
    cout << singleNonDuplicate3(nums) << endl;
    return 0;
}