/*
 * @lc app=leetcode id=1289 lang=cpp
 *
 * [1289] Minimum Falling Path Sum II
 */

// @lc code=start
class Solution
{
private:
    int n;
    int min_path(vector<vector<int>> &grid, int prev_col, int row)
    {
        if (row < 0)
            return INT_MAX;

        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (prev_col != i)
                ans = min(ans, min_path(grid, i, row - 1) + grid[row][i]);
        }
        return ans;
    }

public:
    int minFallingPathSum(vector<vector<int>> &grid)
    {
        n = grid.size();
        return min_path(grid, -1, n - 1);
    }
};
// @lc code=end
