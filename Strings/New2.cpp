#include <bits/stdc++.h>

using namespace std;

bool is_match(const string &text, const string &pattern)
{
    int n = text.size(), m = pattern.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    dp[0][0] = true;

    // Handle patterns with leading asterisks
    for (int j = 1; j <= m; ++j)
        if (pattern[j - 1] == '*')
            dp[0][j] = dp[0][j - 1];

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (pattern[j - 1] == '*')
                dp[i][j] = dp[i][j - 1] || dp[i - 1][j]; // Added || operator
            else
                dp[i][j] = (pattern[j - 1] == text[i - 1] || pattern[j - 1] == '?') && dp[i - 1][j - 1];
    // Added || operator and fixed parentheses

    return dp[n][m];
}

int main()
{
    string text, pattern;
    cin >> text >> pattern;
    cout << (is_match(text, pattern) ? "1" : "0") << endl;
    return 0;
}