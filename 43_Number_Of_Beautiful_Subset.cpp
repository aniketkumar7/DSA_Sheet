// Question: Number Of Beautiful Subset
// Question Link: https://leetcode.com/problems/number-of-beautiful-subsets/


// Problem Statement:
// You are given an array nums of positive integers and a positive integer k.

// A subset of nums is beautiful if it does not contain two integers with an absolute difference equal to k.

// Return the number of non-empty beautiful subsets of the array nums.

// A subset of nums is an array that can be obtained by deleting some (possibly none) elements from nums. Two subsets are different if and only if the chosen indices to delete are different.



// Example 1:

// Input: nums = [2,4,6], k = 2
// Output: 4
// Explanation: The beautiful subsets of the array nums are: [2], [4], [6], [2, 6].
// It can be proved that there are only 4 beautiful subsets in the array [2,4,6].

// Solution:

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to find and print beautiful subsets
void findBeautifulSubsets(int index, const vector<int> &nums, int k, unordered_map<int, int> &freq, int &count, vector<int> &currentSubset)
{
    if (index == nums.size())
    {
        // If the current subset is not empty, increment the count and print the subset
        if (!currentSubset.empty())
        {
            count++;
            cout << "[ ";
            for (int num : currentSubset)
            {
                cout << num << " ";
            }
            cout << "]" << endl;
        }
        return;
    }

    // Exclude the current element
    findBeautifulSubsets(index + 1, nums, k, freq, count, currentSubset);

    // Include the current element if it doesn't violate the beautiful subset condition
    if (!freq[nums[index] - k] && !freq[nums[index] + k])
    {
        freq[nums[index]]++;
        currentSubset.push_back(nums[index]);
        findBeautifulSubsets(index + 1, nums, k, freq, count, currentSubset);
        currentSubset.pop_back();
        freq[nums[index]]--;
    }
}

int main()
{
    vector<int> nums = {2, 4, 6};
    cout << "Input: " << endl;
    cout << "nums = [";
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i];
        if (i != nums.size() - 1)
        {
            cout << ",";
        }
    }
    cout << "]" << endl;

    cout << "k = 2" << endl;
    int k = 2;

    unordered_map<int, int> freq;
    int count = 0;
    vector<int> currentSubset;

    findBeautifulSubsets(0, nums, k, freq, count, currentSubset);
    cout << "Output: " << count << endl;
    return 0;
}
