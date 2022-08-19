/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 */

// @lc code=start
class Solution
{
    int max_profit(int idx, int n, int transactions, vector<int> &prices, vector<vector<int>> &dp)
    {
        if (idx == n or transactions == 0)
            return 0;
        if (dp[idx][transactions] != -1)
            return dp[idx][transactions];
        int profit = 0;
        if (transactions & 1)
        {
            // sell state
            profit = max(prices[idx] + max_profit(idx + 1, n, transactions - 1, prices, dp), max_profit(idx + 1, n, transactions, prices, dp));
        }
        else
        {
            // buy state
            profit = max(-1 * prices[idx] + max_profit(idx + 1, n, transactions - 1, prices, dp), max_profit(idx + 1, n, transactions, prices, dp));
        }
        return dp[idx][transactions] = profit;
    }
    int max_profit_bottomup(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(5, 0));

        for (int idx = n - 1; idx >= 0; idx--)
        {
            for (int transactions = 1; transactions <= 4; transactions++)
            {
                int profit = 0;
                if (transactions & 1)
                {
                    // sell state
                    profit = max(prices[idx] + dp[idx + 1][transactions - 1], dp[idx + 1][transactions]);
                }
                else
                {
                    // buy state
                    profit = max(-1 * prices[idx] + dp[idx + 1][transactions - 1], dp[idx + 1][transactions]);
                }
                dp[idx][transactions] = profit;
            }
        }
        return dp[0][4];
    }

    int max_profit_sopt(vector<int> &prices)
    {
        int n = prices.size();
        vector<int> next(5, 0), cur(5, 0);

        for (int idx = n - 1; idx >= 0; idx--)
        {
            for (int transactions = 1; transactions <= 4; transactions++)
            {
                int profit = 0;
                if (transactions & 1)
                {
                    // sell state
                    profit = max(prices[idx] + next[transactions - 1], next[transactions]);
                }
                else
                {
                    // buy state
                    profit = max(-1 * prices[idx] + next[transactions - 1], next[transactions]);
                }
                cur[transactions] = profit;
            }
            next = cur;
        }
        return next[4];
    }

public:
    int maxProfit(vector<int> &prices)
    {
        // int n = prices.size();
        // int max_trades = 2;
        // int transactions = max_trades * 2;
        // vector<vector<int>> dp(n, vector<int>(transactions + 1, -1));
        // return max_profit(0, n, transactions, prices, dp);
        // return max_profit_bottomup(prices);
        return max_profit_sopt(prices);
    }
};
// @lc code=end
