// Question: Letter Combinations of a Phone Number
// Question URL: https://leetcode.com/problems/letter-combinations-of-a-phone-number/

// Problem Statement:
// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


// Example 1:

// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
// Example 2:

// Input: digits = ""
// Output: []

// Constraints:
// 0 <= digits.length <= 4
// digits[i] is a digit in the range ['2', '9'].

// Solution:
#include<bits/stdc++.h>
using namespace std;


void solve(string digits, int index, string &s, vector<string> &ans, vector<string> &mapping) {
    if (index == digits.size()) {
        ans.push_back(s);
        return;
    }
    int number = digits[index] - '0';
    string value = mapping[number]; // let say number = 2, then value = "abc"
    for (char c : value) {
        s.push_back(c);
        solve(digits, index + 1, s, ans, mapping);
        s.pop_back();
    }
}
vector<string> letterCombinations(string digits) {
    vector<string> ans;
    if (digits.size() == 0)
    return ans;
    vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string s;
    solve(digits, 0, s, ans, mapping);
    return ans;
}

int main() {
    string digits = "23";
    cout << "Input: " << digits << endl;
    vector<string> ans = letterCombinations(digits);

    cout << "Output: " << endl;
    for (string s : ans) {
        cout << s << endl;
    }
    return 0;
}