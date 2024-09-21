// Question: Rat in a Maze
// Question Link: https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1


// PROBLEM STATEMENT:
// Consider a rat placed at (0, 0) in a square matrix mat of order n* n. It has to reach the destination at (n - 1, n - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
// Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell. In case of no path, return an empty list. The driver will output "-1" automatically.

// Examples:

// Input: mat[][] = [[1, 0, 0, 0],
//                 [1, 1, 0, 1],
//                 [1, 1, 0, 0],
//                 [0, 1, 1, 1]]
// Output: DDRDRR DRDDRR
// Explanation: The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR and DDRDRR, when printed in sorted order we get DDRDRR DRDDRR.
// Input: mat[][] = [[1, 0],
//                 [1, 0]]
// Output: -1
// Explanation: No path exists and destination cell is blocked.

// Expected Time Complexity: O(3n^2)
// Expected Auxiliary Space: O(l * x)
// Here l = length of the path, x = number of paths.

// Solution:

#include <bits/stdc++.h>
using namespace std;

void Solve(int i, int j, vector<vector<int>> &mat, vector<string> &ans, vector<vector<bool>> &visited, string path)
{
    int n = mat.size();
    if (i < 0 || j < 0 || i >= n || j >= n || mat[i][j] == 0 || visited[i][j] == true)
    {
        return;
    }

    if (i == n - 1 && j == n - 1)
    {
        ans.push_back(path);
        return;
    }

    visited[i][j] = true;
    Solve(i + 1, j, mat, ans, visited, path + 'D');
    Solve(i, j - 1, mat, ans, visited, path + 'L');
    Solve(i, j + 1, mat, ans, visited, path + 'R');
    Solve(i - 1, j, mat, ans, visited, path + 'U');
    visited[i][j] = false;
}

// Approach 1
vector<string> findPath(vector<vector<int>> &mat, int n)
{
    vector<string> ans;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    string path = "";
    Solve(0, 0, mat, ans, visited, path);
    return ans;
}


// Approach 2
void Solve2(int i, int j, vector<vector<int>> &Maze, string &path, vector<string> &ans)
{
    int n = Maze.size();
    //Base case
    if (i < 0 || j < 0 || i >= n || j >= n || Maze[i][j] == 0)  // If the rat goes out of the maze or the cell is blocked
    {
        return;
    }

    if(i== n-1 && j== n-1)
    {
        ans.push_back(path);
        return;
    }

    Maze[i][j] = 0;

    // Left
    path.push_back('L');
    Solve2(i, j - 1, Maze, path, ans);
    path.pop_back();

    // Right
    path.push_back('R');
    Solve2(i, j + 1, Maze, path, ans);
    path.pop_back();

    // Down
    path.push_back('D');
    Solve2(i + 1, j, Maze, path, ans);
    path.pop_back();

    // Up
    path.push_back('U');
    Solve2(i - 1, j, Maze, path, ans);
    path.pop_back();

    Maze[i][j] = 1;
}

vector<string> printPath(vector<vector<int>> &Maze, int n)
{
    vector<string> ans;
    string path = "";
    if (Maze[0][0] == 0)
    {
        return ans;
    }
    Solve2(0, 0, Maze, path, ans);
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> Maze(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> Maze[i][j];
        }
    }
    vector<string> ans = findPath(Maze, n);
    if (ans.size() == 0)
    {
        cout << "-1";
    }
    else
    {
        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
    }
    return 0;
}