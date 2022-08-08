/*
 * @lc app=leetcode id=931 lang=cpp
 *
 * [931] Minimum Falling Path Sum
 */

// @lc code=start
class Solution
{
private:
    // static int min_path_sum(int row, int prev_col, vector<vector<int>> &matrix, vector<vector<int>> &dp)
    // {
    //     if (idx < 0 or col )
    //         return 0;

    //     if (dp[idx][prev_col] != -1)
    //         return dp[idx][prev_col];

    //     int n = matrix[0].size();
    //     int ans = INT_MAX;

    //     for (int i = 0; i < n; i++)
    //     {
    //         if (i == prev_col or i == prev_col - 1 or i == prev_col + 1 or prev_col == n)
    //             ans = min(ans, min_path_sum(idx - 1, i, matrix, dp) + matrix[idx][i]);
    //     }
    //     return dp[idx][prev_col] = ans;
    // }
    static int min_path_sum(int row, int col, vector<vector<int>> &matrix, vector<vector<int>> &dp)
    {
        if (col < 0 or col >= matrix.size())
            return INT_MAX;
        if (row == 0)
            return matrix[0][col];

        if (dp[row][col] != -1)
            return dp[row][col];
        int left_d = min_path_sum(row - 1, col - 1, matrix, dp);
        int up = min_path_sum(row - 1, col, matrix, dp);
        int right_d = min_path_sum(row - 1, col + 1, matrix, dp);

        return dp[row][col] = min(up, min(left_d, right_d)) + matrix[row][col];
    }

public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            ans = min(ans, min_path_sum(n - 1, i, matrix, dp));
        }
        return ans;
    }
};
// @lc code=end
