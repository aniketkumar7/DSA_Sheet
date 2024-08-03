// MaximumSubArray

// Problem Statement :
// 🔍 Find the maximum sum of a contiguous subarray in a given array of integers.


// Example:
// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: [4,-1,2,1] has the largest sum = 6.


//     Algorithm :

// 1. 🌱 Initialize the maxSum and currSum with the first element of the array.
// 2. 🔄 Iterate over the array from the second element.
// 3. 🔃 For each element,
//     update the currSum by taking the maximum of the current element and the
//     sum of the current element with the previous currSum.
// 4. 🔼 Update the maxSum by taking the maximum of the current maxSum and the updated currSum.
// 5. 🏆 After iterating over the entire array, return the maxSum.



#include <iostream>
#include <vector>
using namespace std;

int maxSubarray(vector<int> &nums)
{
    int n = nums.size();
    int maxSum = nums[0];
    int currSum = nums[0];

    for (int i = 1; i < n; i++)
    {
        currSum = max(nums[i], currSum + nums[i]);
        maxSum = max(maxSum, currSum);
    }

    return maxSum;
}


int main(){
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Input array: ";
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
    cout << "Length of the longest subarray with the maximum Sum: ";
    cout << maxSubarray(nums) << endl;
    return 0;
}




// Dry run
// Input: nums = -2, 1, -3, 4, -1, 2, 1, -5, 4

// Initialization:
// maxSum = nums[0] = -2
// currSum = nums[0] = -2

// Iteration:
// i = 1
// currSum = max(nums1, currSum + nums1) = max(1, -2 + 1) = 1
// maxSum = max(maxSum, currSum) = max(-2, 1) = 1

// i = 2
// currSum = max(nums2, currSum + nums2) = max(-3, 1 + (-3)) = -2
// maxSum = max(maxSum, currSum) = max(1, -2) = 1

// i = 3
// currSum = max(nums3, currSum + nums3) = max(4, -2 + 4) = 4
// maxSum = max(maxSum, currSum) = max(1, 4) = 4

// i = 4
// currSum = max(nums4, currSum + nums4) = max(-1, 4 + (-1)) = 3
// maxSum = max(maxSum, currSum) = max(4, 3) = 4

// i = 5
// currSum = max(nums5, currSum + nums5) = max(2, 3 + 2) = 5
// maxSum = max(maxSum, currSum) = max(4, 5) = 5

// i = 6
// currSum = max(nums6, currSum + nums6) = max(1, 5 + 1) = 6
// maxSum = max(maxSum, currSum) = max(5, 6) = 6

// i = 7
// currSum = max(nums7, currSum + nums7) = max(-5, 6 + (-5)) = 1
// maxSum = max(maxSum, currSum) = max(6, 1) = 6

// i = 8
// currSum = max(nums8, currSum + nums8) = max(4, 1 + 4) = 5
// maxSum = max(maxSum, currSum) = max(6, 5) = 6

// Final Result:
// maxSum = 6

// Explanation: The maximum sum of a contiguous subarray is 6, which corresponds to the subarray 4, -1, 2, 1


