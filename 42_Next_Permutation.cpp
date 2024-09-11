// Question: Next Permutation
// Question Link: https://leetcode.com/problems/next-permutation/

// Problem Statement:
// A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

// For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
// The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

// For example, the next permutation of arr = [1,2,3] is [1,3,2].
// Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
// While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
// Given an array of integers nums, find the next permutation of nums.

// The replacement must be in place and use only constant extra memory.

// Solution:
#include <bits/stdc++.h>
using namespace std;

vector<int> nextPermutation(vector<int> &nums)
{
    int n = nums.size(), k, l;

    // yha hm right side se smallest no. find krte hai
    for (k = n - 2; k >= 0; k--)
    {
        if (nums[k] < nums[k + 1])
        {
            break;
        }
    }

    // yha hm check krte ki k < 0 hai to reverse krdo
    if (k < 0)
    {
        reverse(nums.begin(), nums.end());
    }
    // yha hm right side se greater no. find krte hai to nums[k ] se bda ho
    else
    {
        for (l = n - 1; l > k; l--)
        {
            if (nums[l] > nums[k])
            {
                break;
            }
        }

        // swap krdo
        swap(nums[k], nums[l]);

        // reverse krdo k+1 se last tk
        reverse(nums.begin() + k + 1, nums.end());
    }
    return nums;
}


// Using C++ inbuilt function
// vector<int> nextPermutationSTL(vector<int> &nums)
// {
//     next_permutation(nums.begin(), nums.end());
//     return nums;
// }

// Main function
int main()
{
    vector<int> nums = {1, 2, 3};
    cout << "Input: " << endl;
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    cout << "Output: " << endl;
    vector<int> result = nextPermutation(nums);
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
