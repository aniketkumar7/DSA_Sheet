// Question: Two Sum
// Question link: https://leetcode.com/problems/two-sum/

// Problem Statement:
// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.

// Example 1:
// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Output: Because nums[0] + nums[1] == 9, we return [0, 1].

// Solution:
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// function to find two numbers whose sum is equal to given number
vector<int> twoSum(vector<int> &nums, int target){
    // create a map to store the numbers
    unordered_map<int, int> map;

    // loop through the array
    for(int i=0; i<nums.size(); i++)
    {
        // find the difference
        int diff = target - nums[i];

        // check if the difference is in the map
        if(map.find(diff) != map.end()){
            return {map[diff], i};
        }

        // enter the number in the map
        map[nums[i]] = i;
    }

    return {-1, -1};
}

int main(){
    int n;
    vector<int> arr;

    cout << " Enter the size of the array: ";
    cin>>n;

    cout <<  " Enter the elements of the array: ";
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }

    // target sum
    int target;
    cout << " Enter the target sum: ";
    cin>>target;

    // call the function
    vector<int> ans = twoSum(arr, target);
    cout << " The indices of the numbers whose sum is equal to the target sum are: " << ans[0] << " and " << ans[1] << endl;

    return 0;
}