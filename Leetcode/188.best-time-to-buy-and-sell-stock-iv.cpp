/*
 * @lc app=leetcode id=188 lang=cpp
 *
 * [188] Best Time to Buy and Sell Stock IV
 */

// @lc code=start
class Solution
{
    int max_profit(int idx, int orders_left, int n, vector<int> &prices, vector<vector<int>> &dp)
    {
        if (orders_left == 0 or idx == n)
            return 0;
        if (dp[idx][orders_left] != -1)
            return dp[idx][orders_left];
        int profit = 0;
        if (orders_left & 1)
        {
            // odd orders left means we have done buying now need to sell
            profit = max(prices[idx] + max_profit(idx + 1, orders_left - 1, n, prices, dp), max_profit(idx + 1, orders_left, n, prices, dp));
        }
        else
        {
            // even no of orders left so we need to buy
            profit = max(-1 * prices[idx] + max_profit(idx + 1, orders_left - 1, n, prices, dp), max_profit(idx + 1, orders_left, n, prices, dp));
        }
        return dp[idx][orders_left] = profit;
    }
    int max_profit_bottomup(vector<int> &prices, int k)
    {
        int n = prices.size();
        int max_orders = 2 * k;
        vector<vector<int>> dp(n + 1, vector<int>(max_orders + 1, 0));
        for (int idx = n - 1; idx >= 0; idx--)
        {
            for (int orders_left = 1; orders_left <= max_orders; orders_left++)
            {
                int profit = 0;
                if (orders_left & 1)
                {
                    profit = max(prices[idx] + dp[idx + 1][orders_left - 1], dp[idx + 1][orders_left]);
                }
                else
                {
                    profit = max(-1 * prices[idx] + dp[idx + 1][orders_left - 1], dp[idx + 1][orders_left]);
                }
                dp[idx][orders_left] = profit;
            }
        }
        return dp[0][max_orders];
    }
    int max_profit_sopt(vector<int> &prices, int k)
    {
        int n = prices.size();
        int max_orders = 2 * k;
        vector<int> next(max_orders + 1, 0), cur(max_orders + 1, 0);
        for (int idx = n - 1; idx >= 0; idx--)
        {
            for (int orders_left = 1; orders_left <= max_orders; orders_left++)
            {
                int profit = 0;
                if (orders_left & 1)
                {
                    profit = max(prices[idx] + next[orders_left - 1], next[orders_left]);
                }
                else
                {
                    profit = max(-1 * prices[idx] + next[orders_left - 1], next[orders_left]);
                }
                cur[orders_left] = profit;
            }
            next = cur;
        }
        return next[max_orders];
    }

public:
    int maxProfit(int k, vector<int> &prices)
    {
        // int n = prices.size();
        // int orders_left = 2 * k;
        // vector<vector<int>> dp(n, vector<int>(orders_left + 1, -1));
        // return max_profit(0, orders_left, n, prices, dp);
        // return max_profit_bottomup(prices, k);
        return max_profit_sopt(prices, k);
    }
};
// @lc code=end
