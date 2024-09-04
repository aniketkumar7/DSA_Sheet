// QUESTION: MERGE SORTED ARRAY
// QUESTION LINK: https://leetcode.com/problems/merge-sorted-array/

// PROBLEM STATEMENT:
// You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

// Merge nums1 and nums2 into a single array sorted in non-decreasing order.

// The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

// Example 1:

// Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
// Output: [1,2,2,3,5,6]

// SOLUTION:

#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    vector<int> res(m + n);
    int i = 0, j = 0, k = 0;
    while (i < m && j < n)
    {
        if (nums1[i] < nums2[j])
        {
            res[k] = nums1[i];
            k++;
            i++;
        }
        else
        {
            res[k] = nums2[j];
            k++;
            j++;
        }
    }
    while (i < m)
    {
        res[k] = nums1[i];
        i++;
        k++;
    }
    while (j < n)
    {
        res[k] = nums2[j];
        j++;
        k++;
    }
    for (i = 0; i < (m + n); i++)
    {
        nums1[i] = res[i];
    }
}

int main()
{
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    merge(nums1, 3, nums2, 3);
    cout << "The merged array is: " << endl;
    for (int i = 0; i < nums1.size(); i++)
    {
        cout << nums1[i] << " ";
    }
}