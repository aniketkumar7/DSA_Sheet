// QUESTION: MERGE SORT
// QUESTION LINK:

// PROBLEM STATEMENT:
// Write a program to sort an array using Merge Sort.

// SOLUTION:

#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums, int s, int mid, int e)
{
    int i = s;
    int j = mid + 1;
    int k = 0;
    vector<int> temp(e - s + 1);
    while (i <= mid && j <= e)
    {
        if (nums[i] < nums[j])
        {
            temp[k++] = nums[i++];
        }
        else
        {
            temp[k++] = nums[j++];
        }
    }
    while (i <= mid)
    {
        temp[k++] = nums[i++];
    }
    while (j <= e)
    {
        temp[k++] = nums[j++];
    }
    for (int i = s, t=0; i <= e; i++, t++)
    {
        nums[i] = temp[t];
    }
}

void solve(vector<int> &nums, int s, int e)
{
    if (s >= e)
        return;

    int mid = s + (e - s) / 2;
    solve(nums, s, mid);
    solve(nums, mid + 1, e);
    merge(nums, s, mid, e);
}


vector<int> sortArray(vector<int> &nums)
{
    int n = nums.size();
    solve(nums, 0, n - 1);
    return nums;
}

int main()
{
    vector<int> nums = {5, 2, 3, 1, 7, 8, 2};
    vector<int> ans = sortArray(nums);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
