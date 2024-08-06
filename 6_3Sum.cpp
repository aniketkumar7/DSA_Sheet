// Problem Statement 🔍: 3 Sum

// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]]  such that i != j,i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Example 1:
// Input : nums = [ -1, 0, 1, 2, -1, -4 ]
// Output : [ [ -1, -1, 2 ], [ -1, 0, 1 ] ]
// Explanation : nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0. nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0. nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0. The distinct triplets are[-1, 0, 1] and [ -1, -1, 2 ].


// Approach:

// 1. Sort the input array
// 2. Iterate through the array with a variable i,
// 3. Starting from index 0, initialize two pointers, j and k, with j starting at i + 1 and k starting at the end of the array.
// 4. In the while loop, check if the sum of nums[i], nums[j], and nums[k] is equal to 0.
// 5. If it is, insert the triplet into the set and increment j and decrement k to move the pointers.
// 6. If the sum is less than 0, increment j.
// 7. If the sum is greater than 0, decrement k.
// 8. After the while loop, iterate through the set and add each triplet to the output vector.
// 9. Return the output vector.



#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

// Approach 1: Using nested loops and a set.
// Time Complexity : O(N ^ 3), Here three nested loop creates the time complexity.Where N is the size of the array(nums).
// Space Complexity : O(N),Hash Table(set) space.

vector<vector<int>> threeSum1(vector<int> &nums)
{
    int n = nums.size();
    // Sort the vector to make the search efficient
    sort(nums.begin(), nums.end());
    set<vector<int>> set;           // Set to store unique triplets
    vector<vector<int>> output;     // Vector to store the output triplets

    for (int i = 0; i < n - 2; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue; // Skip duplicates
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if ((nums[i] + nums[j] + nums[k] == 0) && i != j && j != k && k != i)
                {
                    set.insert({nums[i], nums[j], nums[k]}); // Insert triplet into the set
                }
            }
        }
    }
    for (auto it : set)
    {
        output.push_back(it); // Copy the unique triplets from the set to the output vector
    }
    return output;
}



// Approach 2: Using two-pointer approach and a set
// Time Complexity : O(N ^ 2), Here Two nested loop creates the time complexity.Where N is the size of the array(nums).
// Space Complexity : O(N),Hash Table(set) space.

vector<vector<int>> threeSum2(vector<int> &nums)
{
    int n = nums.size();
    // Sort the vector to make the search efficient
    sort(nums.begin(), nums.end());
    set<vector<int>> set;           // Set to store unique triplets
    vector<vector<int>> output;     // Vector to store the output triplets

    for (int i = 0; i < n - 2; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;                  // Skip duplicates
        int low = i + 1, high = n - 1; // Initialize two pointers
        while (low < high)
        {
            if (nums[i] + nums[low] + nums[high] < 0)
            {
                low++; // Increment the low pointer
            }
            else if (nums[i] + nums[low] + nums[high] > 0)
            {
                high--; // Decrement the high pointer
            }
            else
            {
                // Insert triplet into the set
                set.insert({nums[i], nums[low], nums[high]});
                low++;                  // Increment the low pointer
                high--;                // Decrement the high pointer
            }
        }
    }
    for (auto it : set)
    {
        // Copy the unique triplets from the set to the output vector
        output.push_back(it);
    }
    return output;
}


// Approach 3: Using two-pointer approach and a vector
// Time Complexity : O(N^2), Here Two nested loop creates the time complexity. Where N is the size of the array(nums).

// Space Complexity : O(1), Constant space. Extra space is only allocated for the Vector(output), however the output does not count towards the space complexity.
vector<vector<int>> threeSum3(vector<int> &nums)
{
    int n = nums.size();
    // Sort the vector to make the search efficient
    sort(nums.begin(), nums.end());
    vector<vector<int>> output;     // Vector to store the output triplets

    for (int i = 0; i < n - 2; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;                  // Skip duplicates
        int low = i + 1, high = n - 1; // Initialize two pointers
        while (low < high)
        {
            if (nums[i] + nums[low] + nums[high] < 0)
            {
                low++; // Increment the low pointer
            }
            else if (nums[i] + nums[low] + nums[high] > 0)
            {
                high--; // Decrement the high pointer
            }
            else
            {
                // Insert triplet into the output vector
                output.push_back({nums[i], nums[low], nums[high]});
                // Store the current indices
                int tempIndex1 = low, tempIndex2 = high;

                while (low < high && nums[low] == nums[tempIndex1])
                    low++; // Skip duplicates

                while (low < high && nums[high] == nums[tempIndex2])
                    high--; // Skip duplicates
            }
        }
        while (i + 1 < n && nums[i] == nums[i + 1])
            i++; // Skip duplicates
    }
    return output;
}

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    cout << "Approach 1 (Using nested loops and a set):" << endl;
    vector<vector<int>> triplets1 = threeSum1(nums);
    for (auto triplet : triplets1)
    {
        for (int num : triplet)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    cout << "\nApproach 2 (Using two-pointer approach and a set):" << endl;
    vector<vector<int>> triplets2 = threeSum2(nums);
    for (auto triplet : triplets2)
    {
        for (int num : triplet)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    cout << "\nApproach 3 (Using two-pointer approach and a vector):" << endl;
    vector<vector<int>> triplets3 = threeSum3(nums);
    for (auto triplet : triplets3)
    {
        for (int num : triplet)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
