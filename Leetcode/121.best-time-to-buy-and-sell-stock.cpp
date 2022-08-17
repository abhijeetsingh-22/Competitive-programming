/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int prev_min = prices[0];
        int ans = 0;
        int n = prices.size();
        for (int idx = 1; idx < n; idx++)
        {
            int profit = prices[idx] - prev_min;
            ans = max(ans, profit);
            prev_min = min(prev_min, prices[idx]);
        }
        return ans;
    }
};
// @lc code=end
