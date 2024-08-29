// QUESTION: GENERATE PARENTHESES

// PROBLEM STATEMENT:
// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

// Example 1:
// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]

// Example 2:
// Input: n = 1
// Output: ["()"]

// SOLUTION:

#include <bits/stdc++.h>
using namespace std;

// Approach 1: Brute Force - (Recursion)
// vector<string> result1;

// bool isValid(string &s)
// {
//     int count = 0;

//     for (char &ch : s)
//     {
//         if (ch == '(')
//         {
//             count++;
//         }
//         else
//         {
//             count--;
//         }
//         if (count < 0)
//         {
//             return false;
//         }
//     }
//     return count == 0;
// }

// void Solve(string &curr, int n)
// {
//     if (curr.length() == 2 * n)
//     {
//         if (isValid(curr))
//         {
//             result1.push_back(curr);
//         }
//         return;
//     }

//     curr.push_back('(');
//     Solve(curr, n);
//     curr.pop_back();

//     curr.push_back(')');
//     Solve(curr, n);
//     curr.pop_back();
// }



// Approach 2: BackTracking Optimized

// vector<string> result2;

// void Solve(string &curr, int n, int open, int close)
// {
//     if (curr.length() == 2 * n)
//     {
//         result2.push_back(curr);
//         return;
//     }

//     if (open < n)
//     {
//         curr.push_back('(');
//         Solve(curr, n, open + 1, close);
//         curr.pop_back();
//     }

//     if (close < open)
//     {
//         curr.push_back(')');
//         Solve(curr, n, open, close + 1);
//         curr.pop_back();
//     }
// }



// Approach 3: Optimized Recursion

void generateParenthesisHelper(vector<string> &result, string current, int open, int close, int max)
{
    if (current.length() == max * 2)
    {
        result.push_back(current);
        return;
    }

    if (open < max)
    {
        generateParenthesisHelper(result, current + "(", open + 1, close, max);
    }

    if (close < open)
    {
        generateParenthesisHelper(result, current + ")", open, close + 1, max);
    }
}

vector<string> generateParenthesis(int n)
{
    vector<string> result;
    generateParenthesisHelper(result, "", 0, 0, n);
    return result;

    // string curr = "";
    // Solve(curr, n);
    // return result1;

    // Solve(curr, n, 0, 0);
    // return result2;
}

int main()
{
    int n = 3;
    vector<string> result = generateParenthesis(n);
    cout << "Result: " << endl;
    for (string s : result)
    {
        cout << s << endl;
    }
    return 0;
}
