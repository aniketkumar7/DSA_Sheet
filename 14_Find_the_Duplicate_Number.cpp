// Problem : Find the dublicate number

// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

// There is only one repeated number in nums, return this repeated number.

// You must solve the problem without modifying the array nums and uses only constant extra space.

// Example 1:

// Input: nums = [1,3,4,2,2]
// Output: 2
// Example 2:

// Input: nums = [3,1,3,4,2]
// Output: 3

// Complexity Analysis:
// Time Complexity: O(n) - The algorithm makes a constant number of passes over the array.
// Space Complexity: O(1) - No additional data structures are used, only a few pointers.


// Algorithm:

// Initialize two pointers :
//     - slow and fast are initialized to the first element of the vector.

// Find the meeting point :
//     - Using Floyd's cycle detection algorithm (tortoise and hare algorithm), move slow one step and fast two steps until they meet. This is done in the first do-while loop.

// Reset one pointer :
//     - Reset slow to the start of the vector.

// Find the entry point of the cycle :
//      - Move slow and fast one step at a time until they meet again. This meeting point is the entry point of the cycle, which is the duplicate number.

// Return the duplicate number :
//     - Return the value of slow (or fast), which is the duplicate number.


#include <iostream>
#include <vector>
using namespace std;


int findDuplicate(vector<int>& nums)
{
    int slow = nums[0];
    int fast = nums[0];

    do{
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while(slow != fast);

    // Reset the slow
    slow = nums[0];

    // find the dublicate
    while(slow != fast){
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}


int main()
{
    vector<int> nums = {1,3,4,2,2};
    cout << " The dublicate number is: " << findDuplicate(nums);

    return 0;
}