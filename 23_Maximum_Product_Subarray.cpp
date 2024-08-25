// QUESTION: MAXIMUM PRODUCT SUBARRAY

// PROBLEM STATEMENT:
// Given an integer array nums, find a subarray that has the largest product, and return the product.

// The test cases are generated so that the answer will fit in a 32-bit integer.

// Example 1:

// Input: nums = [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.

// Constraints:

// 1 <= nums.length <= 2 * 104
// -10 <= nums[i] <= 10

// SOLUTION:


#include <bits/stdc++.h>
using namespace std;

// Approach: Brute Force
int maxProduct(vector<int> &nums)
{
    int n = nums.size();
    int max_product = INT_MIN;

    for(int i = 0; i < n; i++)
    {
        int product = 1;
        for(int j = i; j < n; j++)
        {
            if(product == 0)
                product = 1;
            product *= nums[j];
            max_product = max(max_product, product);
        }
    }
    return max_product;
}

// Time Complexity: O(N^2)
// Space Complexity: O(1)


// Approach: Optimized
int maxProduct2(vector<int> &nums)
{
    int n = nums.size();
    int product = 1;
    int max_product = INT_MIN;

    for(int i = 0; i < n; i++)
    {
        if(product == 0)
            product = 1;
        product *= nums[i];
        max_product = max(max_product, product);
    }

    product = 1;

    for(int i = n - 1; i >= 0; i--)
    {
        if(product == 0)
            product = 1;
        product *= nums[i];
        max_product = max(max_product, product);
    }

    return max_product;
}
// Time Complexity: O(N)
// Space Complexity: O(1)


// Approach: Prefix Sum
int maxProduct3(vector<int> &nums)
{
    int n = nums.size();
    int max_product = INT_MIN;
    double maxi = INT_MIN;
    double pre = 1, suff = 1;

    for(int i = 0; i < n; i++)
    {
        if (pre == 0)
            pre = 1;
        if (suff == 0)
            suff = 1;
        pre *= nums[i];
        suff *= nums[n - 1 - i];
        maxi = max(maxi, max(pre, suff));
    }
    return maxi;
}
// Time Complexity: O(N)
// Space Complexity: O(1)



int main()
{
    vector<int> nums = {2,3,-2,4, 0, -1};
    cout << "Input: " << endl;

    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    cout << "Maximum Product: " << endl;

    cout << maxProduct(nums) << endl;
    return 0;
}