// QUESTION: MERGE SORT
// QUESTION LINK:

// PROBLEM STATEMENT:
// Write a program to sort an array using Merge Sort.

// SOLUTION:

#include<bits/stdc++.h>
using namespace std;

vector<int> merge(vector<int> &nums, int low, int mid, int high)
{
    vector<int> temp;
    int i = low, j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (nums[i] < nums[j])
        {
            temp.push_back(nums[i]);
            i++;
        }
        else
        {
            temp.push_back(nums[j]);
            j++;
        }
    }
    while (i <= mid)
    {
        temp.push_back(nums[i]);
        i++;
    }
    while (j <= high)
    {
        temp.push_back(nums[j]);
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        nums[i] = temp[i - low];
    }
    return nums;
}

vector<int> solve(vector<int> &nums, int low, int high)
{
    if (low == high)
    {
        return {nums[low]};
    }
    int mid = low + (high - low) / 2;
    vector<int> left = solve(nums, low, mid);
    vector<int> right = solve(nums, mid + 1, high);
    return merge(nums, low, mid, high);
}


int main()
{
    cout << "Enter the size of the array: ";
    int n;
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    vector<int> ans = solve(nums, 0, n - 1);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
