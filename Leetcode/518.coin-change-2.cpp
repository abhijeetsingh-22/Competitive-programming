/*
 * @lc app=leetcode id=518 lang=cpp
 *
 * [518] Coin Change 2
 */

// @lc code=start
class Solution
{
    int count_ways(int idx, int target, vector<int> &coins, vector<vector<int>> &dp)
    {
        if (idx == 0)
        {
            if (target == 0 or target % coins[0] == 0)
                return 1;
            return 0;
        }
        if (dp[idx][target] != -1)
            return dp[idx][target];
        int not_take = count_ways(idx - 1, target, coins, dp);
        int take = 0;
        if (target >= coins[idx])
            take = count_ways(idx, target - coins[idx], coins, dp);

        return dp[idx][target] = take + not_take;
    }

public:
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        return count_ways(n - 1, amount, coins, dp);
    }
};
// @lc code=end
