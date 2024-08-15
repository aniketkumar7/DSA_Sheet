// https://leetcode.com/problems/number-of-islands/

// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.



// Example 1:

// Input: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 1


// Example 2:

// Input: grid = [
//   ["1","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","1","0","0"],
//   ["0","0","0","1","1"]
// ]
// Output: 3


// Algorithm:
// 1. The numIslands function takes a 2D vector of characters representing the grid as input.

// 2. It initializes a variable islands to keep track of the number of islands.

// 3. It iterates over each cell in the grid.

// 4. If a cell contains a '1' (land), it increments the islands count and calls the dfs function to explore and mark all connected land cells as visited ('0').

// 5. The dfs function performs a depth-first search on the grid, starting from the given cell.

// 6. It checks if the current cell is out of bounds or contains water ('0'). If so, it returns without doing anything.

// 7. If the current cell contains land ('1'), it marks it as visited ('0') and recursively calls dfs on all four adjacent cells (up, down, left, right).

// 8. After exploring all connected land cells, the numIslands function returns the total count of islands.

// Time Complexity: O(m * n)
// Space Complexity: O(m * n)


#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<char>> &grid, int i, int j)
{
    // Check if the coordinates are out of the grid or if it's water
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0')
    {
        return;
    }

    // Mark current land as visited by turning it into water
    grid[i][j] = '0';

    // Recursively check all four adjacent locations
    dfs(grid, i + 1, j); // Down
    dfs(grid, i - 1, j); // Up
    dfs(grid, i, j + 1); // Right
    dfs(grid, i, j - 1); // Left
}

int numIslands(vector<vector<char>> &grid)
{
    if (grid.empty())
        return 0;

    int islands = 0;
    int m = grid.size(), n = grid[0].size();

    // Iterate over the entire grid
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (grid[i][j] == '1')
            {
                // Found an island, count it and explore it fully
                islands++;
                dfs(grid, i, j);
            }
        }
    }

    return islands;
}

int main()
{
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}};

    cout << "Grid: " << endl;
    for (auto i : grid)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    cout << "Number of islands: " << numIslands(grid) << endl;

    return 0;
}
