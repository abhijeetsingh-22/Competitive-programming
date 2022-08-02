/*
 * @lc app=leetcode id=807 lang=cpp
 *
 * [807] Max Increase to Keep City Skyline
 */

// @lc code=start
class Solution
{
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int row_max[50] = {0};
        int col_max[50] = {0};

        for (int row = 0; row < n; row++)
        {
            int max_h = 0;
            for (int col = 0; col < n; col++)
            {
                row_max[row] = max(row_max[row], grid[row][col]);
                col_max[col] = max(col_max[col], grid[row][col]);
                // max_h = max(max_h, grid[row][col]);
            }
            // row_max[row] = max_h;
        }
        // for (int col = 0; col < n; col++)
        // {
        //     int max_h = 0;
        //     for (int row = 0; row < n; row++)
        //         max_h = max(max_h, grid[row][col]);
        //     col_max[col] = max_h;
        // }
        int ans = 0;
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                ans += min(row_max[row], col_max[col]) - grid[row][col];
            }
        }
        return ans;
    }
};
// @lc code=end
