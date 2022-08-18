/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
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
        if (can_buy)
        {
            int profit = max(-1 * prices[idx] + max_profit(idx + 1, 0, n, prices, dp), max_profit(idx + 1, 1, n, prices, dp));
            return dp[idx][can_buy] = profit;
        }
        else
        {
            int profit = max(prices[idx] + max_profit(idx + 1, 1, n, prices, dp), max_profit(idx + 1, 0, n, prices, dp));
            return dp[idx][can_buy] = profit;
        }
    }

    int max_profit_bottomup(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        dp[n][0] = dp[n][1] = 0;
        for (int idx = n - 1; idx >= 0; idx--)
        {
            for (int can_buy = 0; can_buy <= 1; can_buy++)
            {
                int profit = 0;
                if (can_buy)
                {
                    profit = max(-1 * prices[idx] + dp[idx + 1][0], dp[idx + 1][1]);
                }
                else
                {
                    profit = max(prices[idx] + dp[idx + 1][1], dp[idx + 1][0]);
                }
                dp[idx][can_buy] = profit;
            }
        }
        return dp[0][1];
    }

public:
    int maxProfit(vector<int> &prices)
    {
        // int n = prices.size();
        // vector<vector<int>> dp(n, vector<int>(2, -1));
        // return max_profit(0, 1, n, prices, dp);
        return max_profit_bottomup(prices);
    }
};
// @lc code=end
