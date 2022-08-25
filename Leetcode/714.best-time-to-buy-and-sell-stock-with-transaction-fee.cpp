/*
 * @lc app=leetcode id=714 lang=cpp
 *
 * [714] Best Time to Buy and Sell Stock with Transaction Fee
 */

// @lc code=start
class Solution
{
    int max_profit_bottomup(vector<int> &prices, int fee)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        // base base if idx==n dp[idx][]=0;

        for (int idx = n - 1; idx >= 0; idx--)
        {
            // 0 = sell 1==buy;
            dp[idx][0] = max(prices[idx] - fee + dp[idx + 1][1], dp[idx + 1][0]);
            dp[idx][1] = max(-1 * prices[idx] + dp[idx + 1][0], dp[idx + 1][1]);
        }
        return dp[0][1];
    }

public:
    int maxProfit(vector<int> &prices, int fee)
    {
        return max_profit_bottomup(prices, fee);
    }
};
// @lc code=end
