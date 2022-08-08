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
    // static int lis_bottomup(vector<int> &nums)

public:
    int lengthOfLIS(vector<int> &nums)
    {

        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return lis_length(0, -1, nums, n, dp);
    }
};
// @lc code=end
