// Question: Reverse Words in a String
// Question link: https://leetcode.com/problems/reverse-words-in-a-string/

// Problem Statement:
// Given an input string s, reverse the order of the words.

// A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

// Return a string of the words in reverse order concatenated by a single space.

// Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.



// Example 1:

// Input: s = "the sky is blue"
// Output: "blue is sky the"


// Code:

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void reverseWords2(string &s)
{
    vector<string> words;
    string word = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            if (word != "")
            {
                words.push_back(word);
                word = "";
            }
        }
        else
        {
            word += s[i];
        }
    }
    if (word != "")
    {
        words.push_back(word);
    }
    reverse(words.begin(), words.end());
    s = "";
    for (int i = 0; i < words.size(); i++)
    {
        s += words[i];
        if (i != words.size() - 1)
        {
            s += " ";
        }
    }
}


// Approach 2:

void reverseWords(string &s)
{
    reverse(s.begin(), s.end());
    int start = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            reverse(s.begin() + start, s.begin() + i);
            start = i + 1;
        }
    }
    reverse(s.begin() + start, s.end());
}


// Approach 3:

string reverseWords3(string &s)
{
    string ans = "";
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] == ' ')
            continue;
        int j = i;
        while (j >= 0 && s[j] != ' ')
        {
            j--;
        }
        ans += (s.substr(j + 1, i - j));
        ans += ' ';
        i = j;
    }
    return ans;
}



int main()
{
    string s = "the sky is blue";
    reverseWords3(s);
    cout << s << endl;
    return 0;
}
