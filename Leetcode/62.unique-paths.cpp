/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
class Solution
{
private:
    // int dp[100][100];
    // int num_path_topdown(int row, int col)
    // {
    //     if (row == 0 and col == 0)
    //         return 1;
    //     if (row < 0 or col < 0)
    //         return 0;
    //     if (dp[row][col] != -1)
    //         return dp[row][col];
    //     int ans = num_path_topdown(row - 1, col) + num_path_topdown(row, col - 1);
    //     dp[row][col] = ans;
    //     return ans;
    // }
    int num_path_bottomup(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 and j == 0)
                    dp[i][j] = 1;
                else
                {
                    int left = 0, up = 0;
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
    int num_paths_sopt(int m, int n)
    {
        vector<int> prev(n, 0);
        prev[0] = 1;

        for (int i = 0; i < m; i++)
        {
            vector<int> cur(n, 0);
            for (int j = 0; j < n; j++)
            {
                if (i == 0 and j == 0)
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
    int uniquePaths(int m, int n)
    {

        // memset(dp, -1, sizeof(dp));
        // return num_path_topdown(m - 1, n - 1);
        // return num_path_bottomup(m, n);
        return num_paths_sopt(m, n);
    }
};
// @lc code=end
