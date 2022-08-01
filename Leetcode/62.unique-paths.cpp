/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
class Solution
{
private:
    int dp[100][100];
    int num_path(int row, int col, int m, int n)
    {
        if (row == m - 1 and col == n - 1)
            return 1;
        if (row >= m or col >= n)
            return 0;
        if (dp[row][col] != -1)
            return dp[row][col];
        int ans = num_path(row + 1, col, m, n) + num_path(row, col + 1, m, n);
        dp[row][col] = ans;
        return ans;
    }

public:
    int uniquePaths(int m, int n)
    {

        memset(dp, -1, sizeof(dp));
        return num_path(0, 0, m, n);
    }
};
// @lc code=end
