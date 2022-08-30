/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution
{
    void visit_dfs(int row, int col, int m, int n, vector<vector<char>> &grid)
    {
        if (row < 0 or row >= m or col < 0 or col >= n)
            return;
        if (grid[row][col] == '1')
        {
            grid[row][col] = '2';
            visit_dfs(row - 1, col, m, n, grid);
            visit_dfs(row, col + 1, m, n, grid);
            visit_dfs(row + 1, col, m, n, grid);
            visit_dfs(row, col - 1, m, n, grid);
        }
    }
    int num_islands(vector<vector<char>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        // vector<vector<int>> visited(m, vector<int>(n, 0));
        int count = 0;
        for (int row = 0; row < m; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (grid[row][col] == '1')
                {
                    count++;
                    visit_dfs(row, col, m, n, grid);
                }
            }
        }
        return count;
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        return num_islands(grid);
    }
};
// @lc code=end
