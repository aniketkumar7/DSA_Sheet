// QUESTION : VALID PARENTHESES
// QUESTION LINK : https://leetcode.com/problems/valid-parentheses/

// PROBLEM STATEMENT :

// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:
// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.

// EXAMPLES :
// Input: s = "()"
// Output: true

// Input: s = "()[]{}"
// Output: true

// SOLUTION :

#include <bits/stdc++.h>
using namespace std;

// Approach 1: Brute Force (Using Stack)
bool isValid1(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            st.push(s[i]);
        else
        {
            if (st.empty())
                return false;
            if (s[i] == ')' && st.top() == '(')
                st.pop();
            else if (s[i] == '}' && st.top() == '{')
                st.pop();
            else if (s[i] == ']' && st.top() == '[')
                st.pop();
            else
                return false;
        }
    }
    if (st.empty())
        return true;
    return false;
}

// Approach 2: Using Hashmap
bool isValid2(string s)
{
    unordered_map<char, char> m;
    m['('] = ')';
    m['{'] = '}';
    m['['] = ']';
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (m.count(s[i]))
            st.push(s[i]);
        else if (st.empty() || m[st.top()] != s[i])
            return false;
        else
            st.pop();
    }
    return st.empty();
}


// Approach 3: Using Vector
bool isValid(string s)
{
    vector<char> st;
    for (char c : s)
    {
        if (c == '(')
            st.push_back(')');
        else if (c == '{')
            st.push_back('}');
        else if (c == '[')
            st.push_back(']');
        else if (st.empty() || st.back() != c)
            return false;
        else
            st.pop_back();
    }
    return st.empty();
}


int main()
{
    string s="()[]{}";

    cout << "Input string: " << s << endl;

    cout << "Output: " << endl;

    if (isValid1(s))
        cout << "String is valid";
    else
        cout << "String is not valid";
    return 0;
}