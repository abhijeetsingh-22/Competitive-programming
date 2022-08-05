/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution
{
private:
    static int max_money_topdown(vector<int> &nums, int idx, vector<int> &dp)
    {
        if (idx >= nums.size())
            return 0;
        if (dp[idx] != -1)
            return dp[idx];
        int take = nums[idx] + max_money_topdown(nums, idx + 2, dp);
        int not_take = max_money_topdown(nums, idx + 1, dp);
        return dp[idx] = max(take, not_take);
    }
    static int max_money_bottomup(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        dp[n] = 0;
        dp[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            int take = nums[i] + dp[i + 2];
            int not_take = dp[i + 1];
            dp[i] = max(take, not_take);
        }
        return dp[0];
    }

public:
    int rob(vector<int> &nums)
    {
        // vector<int> dp(nums.size(), -1);
        // return max_money_topdown(nums, 0, dp);
        return max_money_bottomup(nums);
    }
};
// @lc code=end
