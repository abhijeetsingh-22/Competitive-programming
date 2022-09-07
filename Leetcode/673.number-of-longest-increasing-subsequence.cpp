/*
 * @lc app=leetcode id=673 lang=cpp
 *
 * [673] Number of Longest Increasing Subsequence
 */

// @lc code=start
class Solution
{
    int num_lis(vector<int> &nums)
    {
        int n = nums.size();
        // length of lis ending at i;
        vector<pair<int, int>> dp(n, {1, 1});
        int maxi = 0;
        for (int idx = 0; idx < n; idx++)
        {
            for (int prev_idx = 0; prev_idx < idx; prev_idx++)
            {
                if (nums[prev_idx] < nums[idx])
                {
                    if (dp[idx].first < 1 + dp[prev_idx].first)
                    {

                        dp[idx].first = 1 + dp[prev_idx].first;
                        dp[idx].second = dp[prev_idx].second;
                    }
                    else if (dp[idx].first == 1 + dp[prev_idx].first)
                        dp[idx].second += dp[prev_idx].second;
                }
            }
            maxi = max(dp[idx].first, maxi);
        }
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (dp[i].first == maxi)
                count += dp[i].second;
        }
        return count;
    }

public:
    int findNumberOfLIS(vector<int> &nums)
    {

        return num_lis(nums);
    }
};
// @lc code=end
