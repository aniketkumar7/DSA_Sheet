// QUESTION: Find Players With Zero or One Losses

// PROBLEM STATEMENT:
// You are given an integer array matches where matches[i] = [winneri, loseri] indicates that the player winneri defeated player loseri in a match.

// Return a list answer of size 2 where:

// answer[0] is a list of all players that have not lost any matches.
// answer[1] is a list of all players that have lost exactly one match.
// The values in the two lists should be returned in increasing order.

// Note:

// You should only consider the players that have played at least one match.
// The testcases will be generated such that no two matches will have the same outcome.

// Example 1:
// Input: matches = [[1,3],[2,3],[3,6],[5,6],[5,7],[4,5],[4,8],[4,9],[10,4],[10,9]]
// Output: [[1,2,10],[4,5,7,8]]
// Explanation:
// Players 1, 2, and 10 have not lost any matches.
// Players 4, 5, 7, and 8 each have lost one match.
// Players 3, 6, and 9 each have lost two matches.
// Thus, answer[0] = [1,2,10] and answer[1] = [4,5,7,8].

// SOLUTION:

#include <bits/stdc++.h>
using namespace std;

// APPROACH 1:
vector<vector<int>> findWinner(vector<vector<int>>& matches)
{
    map<int, pair<int, int>> mp;
    for (auto match : matches)
    {
        mp[match[0]].first++;
        mp[match[1]].second++;
    }
    vector<vector<int>> ans(2);
    for (auto it = mp.begin(); it != mp.end(); ++it)
    {
        int player = it->first;
        pair<int, int> v = it->second;
        if (v.second == 0)
            ans[0].push_back(player);
        else if (v.second == 1)
            ans[1].push_back(player);
    }
    return ans;
}

// APPROACH 2:
vector<vector<int>> findWinners1(vector<vector<int>> &matches)
{
    int n = matches.size();

    unordered_map<int, int> Lost_map;

    for (int i = 0; i < n; i++)
    {
        int loser = matches[i][1];
        Lost_map[loser]++;
    }

    vector<int> Lost;
    vector<int> NotLost;

    for (int i = 0; i < n; i++)
    {
        int winner = matches[i][0];
        int loser = matches[i][1];

        if (Lost_map.find(winner) == Lost_map.end())
        {
            NotLost.push_back(winner);
            Lost_map[winner] = 2;
        }
        if (Lost_map[loser] == 1)
        {
            Lost.push_back(loser);
        }
    }
    sort(begin(Lost), end(Lost));
    sort(begin(NotLost), end(NotLost));

    return {NotLost, Lost};
}

int main()
{
    vector<vector<int>> matches = {{1, 3}, {2, 3}, {3, 6}, {5, 6}, {5, 7}, {4, 5}, {4, 8}, {4, 9}, {10, 4}, {10, 9}};

    cout << "Input: " << endl;
    for (auto i : matches)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    cout << "Approach 1: " << endl;
    vector<vector<int>> ans = findWinner(matches);
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    cout << "Approach 2: " << endl;
    vector<vector<int>> ans1 = findWinners1(matches);
    for (auto i : ans1)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}