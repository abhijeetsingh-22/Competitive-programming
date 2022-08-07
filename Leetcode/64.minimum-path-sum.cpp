/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */

// @lc code=start
class Solution
{

    static int min_path(int m, int n, vector<vector<int>> &grid)
    {
        if (m < 0 or n < 0)
            return INT_MAX;
        if (m == 0 and n == 0)
            return grid[0][0];

        // recursive case
        int left = min_path(m, n - 1, grid);
        int up = min_path(m - 1, n, grid);

        return min(left, up) + grid[m][n];
    }

public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        return min_path(m - 1, n - 1, grid);
    }
};
// @lc code=end
