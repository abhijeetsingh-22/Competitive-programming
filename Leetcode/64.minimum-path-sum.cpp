/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */

// @lc code=start
class Solution
{

    static int min_path(int m, int n, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if (m < 0 or n < 0)
            return INT_MAX;
        if (m == 0 and n == 0)
            return grid[0][0];
        if (dp[m][n] != -1)
            return dp[m][n];
        // recursive case
        int left = min_path(m, n - 1, grid, dp);
        int up = min_path(m - 1, n, grid, dp);

        return dp[m][n] = min(left, up) + grid[m][n];
    }
    static int min_path_bottomup(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        dp[0][0] = grid[0][0];

        for (int row = 0; row < m; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (row == 0 and col == 0)
                    continue;
                int up = INT_MAX, left = INT_MAX;
                if (row > 0)
                    up = dp[row - 1][col];
                if (col > 0)
                    left = dp[row][col - 1];

                dp[row][col] = min(left, up) + grid[row][col];
            }
        }
        return dp[m - 1][n - 1];
    }

public:
    int minPathSum(vector<vector<int>> &grid)
    {
        // int m = grid.size();
        // int n = grid[0].size();
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return min_path(m - 1, n - 1, grid, dp);
        return min_path_bottomup(grid);
    }
};
// @lc code=end
