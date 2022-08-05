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

public:
    int climbStairs(int n)
    {
        int dp[50];
        memset(dp, -1, sizeof(dp));

        return climbing_stairs_TD(n, dp);
    }
};
// @lc code=end
