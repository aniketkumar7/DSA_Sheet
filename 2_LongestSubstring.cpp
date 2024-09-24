// Question: Longest Substring Without Repeating Characters
// Question link: https://leetcode.com/problems/longest-substring-without-repeating-characters/

// Problem Statement:
// Given a string s, find the length of the longest substring without repeating characters.
// Example 1:
// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int LongestSubstring(string s){
    unordered_map<char, int> mp;
    int maxLength = 0;
    int start = 0; // starting index of the current window

    // sliding window
    for(int i=0; i < s.length(); i++){
        // Check if character is already in the string
        if(mp.find(s[i]) != mp.end()){
            // move the start to the right
            start = mp[s[i]] + 1;
        }
        // update the last index
        mp[s[i]] = i;
        // update the max length
        maxLength = max(maxLength, i - start + 1);
    }
    return maxLength;
}
// Time complexity: O(n)
// Space complexity: O(n)

// Approach 2: Using vector instead of unordered_map
int LongestSubstring(string s){
    vector<int> mp(256, -1);
    int maxLength = 0;
    int start = 0; // starting index of the current window

    // sliding window
    for(int i=0; i < s.length(); i++){
        // Check if character is already in the string
        if(mp[s[i]] != -1){
            // move the start to the right
            start = mp[s[i]] + 1;
        }
        // update the last index
        mp[s[i]] = i;
        // update the max length
        maxLength = max(maxLength, i - start + 1);
    }
    return maxLength;
}

// Time complexity: O(n)
// Space complexity: O(1)

// It is recommended to use vector instead of unordered_map as it is faster and more memory efficient. But if the input string contains unicode characters, then we should use unordered_map.

int main(){
    string s;
    cout << "Enter the string: ";
    cin >> s;

    cout << "Length of the longest substring: " << endl;
    cout << LongestSubstring(s) << endl;
    return 0;
}