/*
 * @lc app=leetcode id=377 lang=cpp
 *
 * [377] Combination Sum IV
 */

// @lc code=start
class Solution
{
    int dp[1001];

private:
    int combination_sum(vector<int> &nums, int cur, int target)
    {
        if (cur == target)
            return 1;
        if (cur > target)
            return 0;
        if (dp[cur] != -1)
            return dp[cur];
        int ans = 0;
        for (int &x : nums)
        {
            ans += combination_sum(nums, cur + x, target);
        }
        dp[cur] = ans;
        return ans;
    }

public:
    int combinationSum4(vector<int> &nums, int target)
    {
        memset(dp, -1, sizeof(dp));
        return combination_sum(nums, 0, target);
    }
};
// @lc code=end
