// Question: Count Occurences of Anagrams
// Question link: https://practice.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1
// Solution link: https://www.geeksforgeeks.org/count-occurrences-of-anagrams/
// Difficulty: Medium


// Problem Statement:
// Given a word pat and a text txt. Return the count of the occurences of anagrams of the word in the text.

// Example 1:
// Input:
// txt = forxxorfxdofr
// pat = for
// Output: 3
// Explanation: for, orf and ofr appears
// in the txt, hence answer is 3.


#include <bits/stdc++.h>
using namespace std;

int search(string pat, string txt)
{
    int n = txt.length();
    int m = pat.length();

    if (m > n)
        return 0; // If pattern length is greater than text length, return 0

    vector<int> patFreq(26, 0);
    vector<int> windowFreq(26, 0);

    // Fill the frequency vector for the pattern
    for (int i = 0; i < m; i++)
    {
        patFreq[pat[i] - 'a']++;
        windowFreq[txt[i] - 'a']++;
    }

    int count = 0;

    // Check the first window
    if (patFreq == windowFreq)
        count++;

    // Slide the window over the text
    for (int i = m; i < n; i++)
    {
        // Add the next character to the window
        windowFreq[txt[i] - 'a']++;
        // Remove the first character of the previous window
        windowFreq[txt[i - m] - 'a']--;

        // Compare the frequency vectors
        if (patFreq == windowFreq)
            count++;
    }

    return count;
}

bool allZero(vector<int> patFreq)
{
    for(int i = 0; i < 26; i++)
    {
        if(patFreq[i] != 0)
        {
            return false;
        }
    }
    return true;
}

int search2(string pat, string txt)
{
    int n = txt.length();
    int m = pat.length();

    vector<int> patFreq(26, 0);

    for (int i = 0; i < m; i++)
    {
        patFreq[pat[i] - 'a']++;
    }

    int i = 0, j = 0;
    int count = 0;

    while (j < n)
    {
        patFreq[txt[j] - 'a']--;

        if(j - i + 1 == m){
            if(allZero(patFreq)){
                count++;
            }
            patFreq[txt[i] - 'a']++;
            i++;
        }
        j++;
    }
    return count;
}

int main()
{
    string txt = "forxxorfxdofr";
    string pat = "for";
    cout << "Input text: " << txt << endl;
    cout << "Input pattern: " << pat << endl;

    cout << "Output: ";
    cout << search(pat, txt) << endl;

    return 0;
}