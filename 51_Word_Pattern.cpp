// Question: Word Pattern
// Question URL: https://leetcode.com/problems/word-pattern/

// Problem Statement:
// Given a pattern and a string s, find if s follows the same pattern.
// Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

// Example 1:
// Input: pattern = "abba", s = "dog cat cat dog"
// Output: true

// Example 2:
// Input: pattern = "abba", s = "dog cat cat fish"
// Output: false

// Solution:
// Approach:
// 1. Create a map to store the mapping of pattern to string.
// 2. Create a set to store the unique strings.
// 3. Split the string s into words.
// 4. If the size of pattern and words are not equal, return false.
// 5. Iterate through the pattern and words.
// 6. If the pattern is not present in the map, check if the word is present in the set.
// 7. If the word is present in the set, return false.
// 8. Else, add the word to the set and map the pattern to the word.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>

using namespace std;

bool wordPattern(string pattern, string s)
{
    unordered_map<char, string> patternMap;
    unordered_set<string> uniqueWords;
    vector<string> words;

    // String s ko words mein split karna hai
    stringstream ss(s);
    string word;

    // Words ko vector mein alag alag indexes par push karna
    while (ss >> word)
    {
        words.push_back(word);
    }

    // Agar pattern aur words ka size equal nahi hai, to false return karna hai
    if (pattern.size() != words.size())
    {
        return false;
    }

    // Pattern aur words ko iterate karna
    for (int i = 0; i < pattern.size(); i++)
    {
        // Check karna agar pattern map mein nahi hai
        if (patternMap.find(pattern[i]) == patternMap.end())
        {
            // Check karna agar word set mein present hai
            if (uniqueWords.find(words[i]) != uniqueWords.end())
            {
                return false;
            }
            uniqueWords.insert(words[i]);
            patternMap[pattern[i]] = words[i];
        }
        else
        {
            // Agar pattern map mein hai aur word match nahi karta, to false return karna
            if (patternMap[pattern[i]] != words[i])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    string pattern = "abba";
    cout << "Input: pattern = \"abba\", s = \"dog cat cat dog\"" << endl;
    string s = "dog cat cat dog";
    int result = wordPattern(pattern, s);
    if (result == 1)
    {
        cout << "Output: true" << endl;
    }
    else
    {
        cout << "Output: false" << endl;
    }
    return 0;
}