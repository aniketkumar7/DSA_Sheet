// QUESTION : CHECK IF TWO STRING ARRAYS ARE EQUIVALENT

// PROBLEM STATEMENT :
// Given two string arrays word1 and word2, return true if the two arrays represent the same string, and false otherwise.

// EXAMPLE 1:

// Input: word1 = ["ab", "ba"], word2 = ["ab", "ba"]
// Output: true
// Explanation:
// word1 represents string "ab" + "c" -> "abc"
// word2 represents string "a" + "bc" -> "abc"
// The strings are the same, so return true.

// SOLUTION :

#include <bits/stdc++.h>
using namespace std;

// Approach : Brute Force
bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
{
    // edge case
    if (word1.size() != word2.size())
    {
        return false;
    }
    string s1 = "";
    string s2 = "";
    for (int i = 0; i < word1.size(); i++)
    {
        s1 += word1[i];
    }
    for (int i = 0; i < word2.size(); i++)
    {
        s2 += word2[i];
    }
    return s1 == s2;
}
// Time Complexity : O(N + M)
// Space Complexity : O(N + M)


// Approach : Using Two Pointers
bool arrayStringsAreEqualTwo(vector<string> &word1, vector<string> &word2)
{
    int i = 0, j = 0;           // Pointers for word1 and word2
    int index1 = 0, index2 = 0; // Indexes for the chars in the current string

    while (i < word1.size() && j < word2.size())
    {
        if (word1[i][index1] != word2[j][index2])
        {
            return false; // Characters do not match
        }

        // Move to the next character in word1
        index1++;
        if (index1 == word1[i].size())
        { // Move to the next string in word1
            i++;
            index1 = 0;
        }

        // Move to the next character in word2
        index2++;
        if (index2 == word2[j].size())
        { // Move to the next string in word2
            j++;
            index2 = 0;
        }
    }

    // Check if both pointers have reached the end of their respective arrays
    return i == word1.size() && j == word2.size();
}
// Time Complexity : O(N + M)
// Space Complexity : O(1)


int main()
{
    vector<string> word1 = {"ab", "ba"};
    vector<string> word2 = {"ab", "ba"};
    cout << "Input: " << endl;
    for (int i = 0; i < word1.size(); i++)
    {
        cout << word1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < word2.size(); i++)
    {
        cout << word2[i] << " ";
    }
    cout << endl;

    cout << "Output: " << endl;
    cout << arrayStringsAreEqualTwo(word1, word2);
    return 0;
}