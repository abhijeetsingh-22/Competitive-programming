/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

// @lc code=start
class Solution
{
    static int ways_to_reach(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if (row < 0 or col < 0)
            return 0;
        if (grid[row][col] == 1)
            return 0;
        if (row == 0 and col == 0)
            return 1;
        if (dp[row][col] != -1)
            return dp[row][col];
        // recursive case;
        int up = ways_to_reach(row - 1, col, grid, dp);
        int left = ways_to_reach(row, col - 1, grid, dp);
        return dp[row][col] = up + left;
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return ways_to_reach(m - 1, n - 1, obstacleGrid, dp);
    }
};
// @lc code=end