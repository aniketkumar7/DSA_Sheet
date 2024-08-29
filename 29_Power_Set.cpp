// QUESTION: POWER SET

// PROBLEM STATEMENT:
// Given a string s of length n, find all the possible non-empty subsequences of the string s in lexicographically-sorted order.

// Example 1:
// Input :
// s = "abc"
// Output:
// a ab abc ac b bc c
// Explanation :
// There are a total 7 number of subsequences possible for the given string, and they are mentioned above in lexicographically sorted order.

// SOLUTION:

#include <bits/stdc++.h>
using namespace std;

// Approach 1: Brute Force

vector<string> result;
void printSubsequences(string &s, string &output, int index)
{
    if (index == s.length())
    {
        if(output != "")
        {
            result.push_back(output);
        }
        return;
    }

    // Exclude the current character
    output.push_back(s[index]);
    printSubsequences(s, output, index + 1);
    output.pop_back();
    printSubsequences(s, output, index + 1);
}

vector<string> AllPossibleStrings(string s)
{
    string output = "";
    printSubsequences(s, output, 0);
    sort(result.begin(), result.end());
    return result;
}

int main()
{
    string s = "abc";
    cout << "Input string: " << s << endl;

    vector<string> ans = AllPossibleStrings(s);
    cout << "All possible subsequences are: " << endl;
    for (string i : ans)
    {
        cout << i << " ";
    }
    return 0;
}