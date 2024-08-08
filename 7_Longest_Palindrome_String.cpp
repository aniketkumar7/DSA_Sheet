// Problem Statement :

//  Given a string s, find the length of the longest substring that is a palindrome.
//  A palindrome is a string that reads the same forward and backward,
//  such as "racecar" or "level".

// Example :
// Input: s = "babad"
// Output: 3
// Explanation: The longest palindrome is "aba", with a length of 3.


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

    using namespace std;

// Helper function to check if a substring is a palindrome
bool checkPalindrome(const string &s, int i, int j)
{
    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

// Helper function to check if a string is a palindrome
bool isPalindrome(const string &s)
{
    int i = 0, j = s.size() - 1;
    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

bool solve(vector<vector<bool>> &dp, int i, int j, string &s)
{
    if (i == j)
    {
        return dp[i][j] = true;
    }
    if (j - i == 1)
    {
        if (s[i] == s[j])
        {
            return dp[i][j] = true;
        }
        else
        {
            return dp[i][j] = false;
        }
    }
    if (s[i] == s[j] && dp[i + 1][j - 1] == true)
    {
        return dp[i][j] = true;
    }
    else
    {
        return dp[i][j] = false;
    }
}

// 1. Brute Force Approach(Three Nested Loops) :
// In this approach, we generate all possible substrings of the given string and check if each substring is a palindrome.We keep track of the longest palindromic substring found so far.string longestPalindromeBruteForce(string s)

//      - Time Complexity : O(N^3), Here Three nested loop creates the time complexity. Where N is the size of the string(s).
//      - Space Complexity : O(N^3), vector(substring) space.

string longestPalindromeBruteForce(string s)
{
    int n = s.size();
    int starting_index = 0;
    int max_len = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (checkPalindrome(s, i, j))
            {
                if (j - i + 1 > max_len)
                {
                    max_len = j - i + 1;
                    starting_index = i;
                }
            }
        }
    }
    return s.substr(starting_index, max_len);
}



// 2. Generate All Substrings Approach (Two Nested Loops):

// This approach is similar to the brute force approach, but instead of generating all substrings on the fly, we first generate all possible substrings and store them in a vector or list.Then, we check each substring to see if it is a palindrome and keep track of the longest one.

//      - Time Complexity : O(N^2), Here Two nested loop creates the time complexity. Where N is the size of the string(s).
//      -  Space Complexity : O(N^2*N), vector(substring) space.
string longestPalindromeSubstrings(string s)
{
    int n = s.size();
    vector<string> substrings;

    for (int i = 0; i < n; i++)
    {
        string temp = "";
        for (int j = i; j < n; j++)
        {
            temp += s[j];
            substrings.push_back(temp);
        }
    }

    int max_len = 0;
    string final_ans = "";
    for (const string &substr : substrings)
    {
        if (isPalindrome(substr))
        {
            if (substr.size() > max_len)
            {
                max_len = substr.size();
                final_ans = substr;
            }
        }
    }
    return final_ans;
}

// Solved using Dynamic Programming Approach(tabulation). Optimized Approach.
// Approach 3: Dynamic Programming
// This approach uses dynamic programming to solve the problem efficiently. We construct a 2D boolean table dp[n][n], where dp[i][j] represents whether the substring from index i to j is a palindrome or not.

// Time Complexity : O(N^2), The time complexity of the above code is O(N^2) because we are traversing over all the substrings and then checking each substring if it is a palindrome or not. There are N^2 substrings and      checking a substring takes O(1) time, so total time complexity is O(N^2).

// Space Complexity : (N^2), The space complexity of the above code is O(N^2) because we are using the dp array in which we are storing whether a substring is a palindrome or not.

string longestPalindromeDP(string s)
{
    int n = s.size();
    int startIndex = 0;
    int maxlen = 0;
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    for (int g = 0; g < n; g++)
    {
        for (int i = 0, j = g; j < n; i++, j++)
        {
            solve(dp, i, j, s);
            if (dp[i][j] == true)
            {
                if (j - i + 1 > maxlen)
                {
                    startIndex = i;
                    maxlen = j - i + 1;
                }
            }
        }
    }
    return s.substr(startIndex, maxlen);
}

int main()
{
    string input = "babad";

    // Testing Approach 1: Brute Force
    string result1 = longestPalindromeBruteForce(input);
    cout << "Longest Palindromic Substring (Brute Force): " << result1 << endl;

    // Testing Approach 2: Generate All Substrings
    string result2 = longestPalindromeSubstrings(input);
    cout << "Longest Palindromic Substring (Substrings): " << result2 << endl;

    // Testing Approach 3: Dynamic Programming
    string result3 = longestPalindromeDP(input);
    cout << "Longest Palindromic Substring (Dynamic Programming): " << result3 << endl;

    return 0;
}