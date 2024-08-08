// Problem: Merge Two Sorted Arrays

// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

// The overall run time complexity should be O(log (m+n)).


// Example 1:

// Input: nums1 = [1,3], nums2 = [2]
// Output: 2.00000
// Explanation: merged array = [1,2,3] and median is 2.
// Example 2:

// Input: nums1 = [1,2], nums2 = [3,4]
// Output: 2.50000
// Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.


// How to solve this problem:

// Brute Force Approach:

// 1. Sort both the arrays
// 2. Find the median of both the arrays

// Time Complexity: O(m + n)
// Space Complexity: O(m + n)


// Optimized Approach:

// 1. Merge both the arrays
// 2. Find the median of the merged array

// Time Complexity: O(m + n)
// Space Complexity: O(m + n)


#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach

// Function to find the median of two sorted arrays
double findMedian(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> merged(nums1.size() + nums2.size());
    merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), merged.begin());

    if (merged.size() % 2 == 0)
    {
        int mid = merged.size() / 2;
        return (merged[mid] + merged[mid - 1]) / 2.0;
    }

    return merged[merged.size() / 2];
}

// Function to find the median of two sorted arrays
double findMedianSorted(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();    // Size of the first array
    int m = nums2.size();    // Size of the second array
    vector<int> ans(n + m);  // Array to hold the merged result
    int i = 0, j = 0, k = 0; // Pointers for nums1, nums2, and ans

    // Merge the two arrays
    while (i < n && j < m)
    {
        if (nums1[i] <= nums2[j])
        {
            ans[k++] = nums1[i++]; // Add from nums1
        }
        else
        {
            ans[k++] = nums2[j++]; // Add from nums2
        }
    }

    // Add remaining elements from nums1, if any
    while (i < n)
    {
        ans[k++] = nums1[i++];
    }

    // Add remaining elements from nums2, if any
    while (j < m)
    {
        ans[k++] = nums2[j++];
    }

    // Calculate the median
    int mid = (m + n) / 2;
    if ((m + n) % 2 != 0)
    {
        return double(ans[mid]); // Odd case
    }
    return double((ans[mid] + ans[mid - 1]) / 2); // Even case
}


// Optimized Approach

// Function to find the median of two sorted arrays
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int m = nums1.size();
    int n = nums2.size();

    // Ensure that nums1 is the smaller array
    if (m > n)
    {
        return findMedianSortedArrays(nums2, nums1);
    }

    // Initialize the pointers for binary search
    int left = 0, right = m;

    // Loop until the pointers meet
    while (left <= right)
    {
        // Calculate the partition index
        int partitionX = (left + right) / 2;
        int partitionY = (m + n + 1) / 2 - partitionX;

        // Calculate the maximum and minimum elements around the partitions
        int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
        int minRightX = (partitionX == m) ? INT_MAX : nums1[partitionX];

        int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
        int minRightY = (partitionY == n) ? INT_MAX : nums2[partitionY];

        if (maxLeftX <= minRightY && maxLeftY <= minRightX)
        {
            if ((m + n) % 2 == 0)
            {
                return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
            }
            else
            {
                return max(maxLeftX, maxLeftY);
            }
        }
        else if (maxLeftX > minRightY)
        {
            right = partitionX - 1;
        }
        else
        {
            left = partitionX + 1;
        }
    }

    // This should never happen
    return 0.0;
}

int main()
{
    // Example usage
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    double median = findMedianSorted(nums1, nums2);
    cout << "The median is: " << median << endl; // Output: The median is: 2

    // Another example
    vector<int> nums3 = {1, 2};
    vector<int> nums4 = {3, 4};

    median = findMedianSortedArrays(nums3, nums4);
    cout << "The median is: " << median << endl; // Output: The median is: 2.5

    return 0;
}




// Dry run:
