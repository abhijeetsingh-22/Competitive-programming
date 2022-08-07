/*
 * @lc app=leetcode id=931 lang=cpp
 *
 * [931] Minimum Falling Path Sum
 */

// @lc code=start
class Solution
{
private:
    static int min_path_sum(int idx, int prev_col, vector<vector<int>> &matrix, vector<vector<int>> &dp)
    {
        if (idx < 0)
            return 0;

        if (dp[idx][prev_col] != -1)
            return dp[idx][prev_col];

        int n = matrix[0].size();
        int ans = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            if (i == prev_col or i == prev_col - 1 or i == prev_col + 1 or prev_col == n)
                ans = min(ans, min_path_sum(idx - 1, i, matrix, dp) + matrix[idx][i]);
        }
        return dp[idx][prev_col] = ans;
    }

public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return min_path_sum(n - 1, n, matrix, dp);
    }
};
// @lc code=end
