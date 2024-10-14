// Question: Decode the Message
// Question URL: https://leetcode.com/problems/decode-ways/

// Problem Statement:
// You are given the strings key and message, which represent a cipher key and a secret message, respectively. The steps to decode message are as follows:

// Use the first appearance of all 26 lowercase English letters in key as the order of the substitution table.
// Align the substitution table with the regular English alphabet.
// Each letter in message is then substituted using the table.
// Spaces ' ' are transformed to themselves.
// For example, given key = "happy boy" (actual key would have at least one instance of each letter in the alphabet), we have the partial substitution table of ('h' -> 'a', 'a' -> 'b', 'p' -> 'c', 'y' -> 'd', 'b' -> 'e', 'o' -> 'f').
// Return the decoded message.

// Example
// Input: key = "the quick brown fox jumps over the lazy dog", message = "vkbs bs t suepuv"
// Output: "this is a secret"
// Explanation: The diagram above shows the substitution table.
// It is obtained by taking the first appearance of each letter in "the quick brown fox jumps over the lazy dog".

// Code:

#include <bits/stdc++.h>
using namespace std;

string decodeMessage(string key, string message)
{
    vector<char> mp(26, ' ');
    char start = 'a';
    for (char c : key)
    {
        if (c != ' ' && mp[c - 'a'] == ' ')
        {
            mp[c - 'a'] = start;
            start++;
        }
    }
    string ans = "";
    for (char c : message)
    {
        if (c == ' ')
        {
            ans += ' ';
        }
        else
        {
            ans += mp[c - 'a'];
        }
    }
    return ans;
}

int main()
{
    string key = "the quick brown fox jumps over the lazy dog";
    cout << "Key: " << key << endl;
    string message = "vkbs bs t suepuv";
    cout << "Encoded Message: " << message << endl;

    cout << "Decoded Message: ";
    cout << decodeMessage(key, message) << endl;
    return 0;
}