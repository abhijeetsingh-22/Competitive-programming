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
    static int ways_bottomup(int m, int n, vector<vector<int>> &grid)
    {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    dp[i][j] = 0;
                }

                else if (i == 0 and j == 0)
                    dp[i][j] = 1;
                else
                {

                    int up = 0, left = 0;
                    if (i > 0)
                        up = dp[i - 1][j];
                    if (j > 0)
                        left = dp[i][j - 1];
                    dp[i][j] = left + up;
                }
            }
        }
        return dp[m - 1][n - 1];
    }
    static int ways_sopt(int m, int n, vector<vector<int>> &grid)
    {
        vector<int> prev(n, 0);
        for (int i = 0; i < m; i++)
        {
            vector<int> cur(n, 0);
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                    cur[j] = 0;
                else if (i == 0 and j == 0)
                    cur[j] = 1;
                else
                {
                    int left = 0, up = 0;
                    if (i > 0)
                        up = prev[j];
                    if (j > 0)
                        left = cur[j - 1];
                    cur[j] = left + up;
                }
            }
            prev = cur;
        }
        return prev[n - 1];
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return ways_to_reach(m - 1, n - 1, obstacleGrid, dp);
        // return ways_bottomup(m, n, obstacleGrid);
        return ways_sopt(m, n, obstacleGrid);
    }
};
// @lc code=end
