/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */

// @lc code=start
class Solution
{
    int max_profit(int idx, int can_buy, int n, vector<int> &prices, vector<vector<int>> &dp)
    {
        if (idx == n)
            return 0;
        if (dp[idx][can_buy] != -1)
            return dp[idx][can_buy];
        int take = INT_MIN;
        int not_take = INT_MIN;
        if (can_buy == 1)
        {
            take = -1 * prices[idx] + max_profit(idx + 1, 2, n, prices, dp);
            not_take = max_profit(idx + 1, 1, n, prices, dp);
        }
        else if (can_buy == 2)
        {
            take = prices[idx] + max_profit(idx + 1, 0, n, prices, dp);
            not_take = max_profit(idx + 1, 2, n, prices, dp);
        }
        else
            return dp[idx][can_buy] = max_profit(idx + 1, 1, n, prices, dp);
        return dp[idx][can_buy] = max(take, not_take);
    }
    int max_profit_bottom_up(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(3, 0));

        for (int idx = n - 1; idx >= 0; idx--)
        {
            for (int can_buy = 0; can_buy <= 2; can_buy++)
            {
                int take = INT_MIN;
                int not_take = INT_MIN;
                if (can_buy == 0)
                    dp[idx][can_buy] = dp[idx + 1][1];

                if (can_buy == 1)
                    dp[idx][can_buy] = max(-1 * prices[idx] + dp[idx + 1][2], dp[idx + 1][can_buy]);
                if (can_buy == 2)
                    dp[idx][can_buy] = max(prices[idx] + dp[idx + 1][0], dp[idx + 1][can_buy]);
            }
        }
        return dp[0][1];
    }

public:
    int maxProfit(vector<int> &prices)
    {
        // int n = prices.size();
        // vector<vector<int>> dp(n, vector<int>(3, -1));
        // return max_profit(0, 1, n, prices, dp);
        return max_profit_bottom_up(prices);
    }
};
// @lc code=end
