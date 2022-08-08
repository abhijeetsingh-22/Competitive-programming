/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */

// @lc code=start
class Solution
{
    static int min_path(int row, int col, vector<vector<int>> &triangle, vector<vector<int>> &dp)
    {
        if (row == triangle.size() - 1)
            return triangle[row][col];
        if (dp[row][col] != -1)
            return dp[row][col];
        int down = min_path(row + 1, col, triangle, dp);
        int right = min_path(row + 1, col + 1, triangle, dp);

        return dp[row][col] = min(down, right) + triangle[row][col];
    }

public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return min_path(0, 0, triangle, dp);
    }
};
// @lc code=end
