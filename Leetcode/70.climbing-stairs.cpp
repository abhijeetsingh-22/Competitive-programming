/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution
{
private:
    static int climbing_stairs_TD(int n, int *dp)
    {
        if (n == 0)
            return 1;
        if (n < 0)
            return 0;
        if (dp[n] != -1)
            return dp[n];

        int ans = climbing_stairs_TD(n - 1, dp) + climbing_stairs_TD(n - 2, dp);

        return dp[n] = ans;
    }
    static int climbing_stairs_BU(int n)
    {
        // int dp[50];
        // dp[0] = dp[1] = 1;
        int prev = 1, prev_prev = 1, cur = 1;
        for (int i = 2; i <= n; i++)
        {
            cur = prev + prev_prev;
            prev_prev = prev;
            prev = cur;
            // dp[i] = dp[i - 1] + dp[i - 2];
        }
        // return dp[n];
        return cur;
    }

public:
    int climbStairs(int n)
    {
        // int dp[50];
        // memset(dp, -1, sizeof(dp));

        // return climbing_stairs_TD(n, dp);
        return climbing_stairs_BU(n);
    }
};
// @lc code=end
