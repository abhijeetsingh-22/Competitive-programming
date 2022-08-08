/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
class Solution
{
    static int lis_length(int idx, int prev_idx, vector<int> &nums, int n, vector<vector<int>> &dp)
    {
        if (idx == n)
        {
            return 0;
        }

        if (dp[idx][prev_idx + 1] != -1)
            return dp[idx][prev_idx + 1];

        int not_take = lis_length(idx + 1, prev_idx, nums, n, dp);

        int take = INT_MIN;
        if (prev_idx == -1 or nums[idx] > nums[prev_idx])
            take = lis_length(idx + 1, idx, nums, n, dp) + 1;

        return dp[idx][prev_idx + 1] = max(take, not_take);
    }
    static int lis_bottomup(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int idx = n - 1; idx >= 0; idx--)
        {
            for (int prev_idx = idx - 1; prev_idx >= -1; prev_idx--)
            {
                int not_take = dp[idx + 1][prev_idx + 1];
                int take = INT_MIN;
                if (prev_idx == -1 or nums[idx] > nums[prev_idx])
                    take = dp[idx + 1][idx + 1] + 1;
                dp[idx][prev_idx + 1] = max(take, not_take);
            }
        }
        return dp[0][0];
    }

public:
    int lengthOfLIS(vector<int> &nums)
    {

        // int n = nums.size();
        // vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        // return lis_length(0, -1, nums, n, dp);
        return lis_bottomup(nums);
    }
};
// @lc code=end
