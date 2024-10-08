// Search in Rotated Sorted Array

// There is an integer array nums sorted in ascending order (with distinct values).

// Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

// Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.



// Example 1:

// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4



#include <iostream>
#include <vector>
using namespace std;

// Brute force approach to find the target in the rotated sorted array
int searchBruteForce(vector<int> &nums, int target)
{
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == target)
        {
            return i; // Return the index if found
        }
    }
    return -1; // Return -1 if not found
}


// Optimized approach using binary search
int searchBinarySearch(vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target)
        {
            return mid; // Target found
        }

        // Determine which part is sorted
        if (nums[left] <= nums[mid])
        { // Left part is sorted
            if (nums[left] <= target && target < nums[mid])
            {
                right = mid - 1; // Search in the left part
            }
            else
            {
                left = mid + 1; // Search in the right part
            }
        }
        else
        { // Right part is sorted
            if (nums[mid] < target && target <= nums[right])
            {
                left = mid + 1; // Search in the right part
            }
            else
            {
                right = mid - 1; // Search in the left part
            }
        }
    }
    return -1; // Target not found
}

int main(){
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int target;
    cout << "Enter the target: ";
    cin >> target;

    // Calling the brute force approach
    cout << "Index of target is: " << searchBruteForce(nums, target) << endl;
    // Calling the optimized approach
    cout << "Index of target is: " << searchBinarySearch(nums, target) << endl;
    return 0;
}