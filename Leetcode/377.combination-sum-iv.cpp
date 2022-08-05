/*
 * @lc app=leetcode id=377 lang=cpp
 *
 * [377] Combination Sum IV
 */

// @lc code=start
class Solution
{
    unsigned int dp[1001];

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
    int combination_sum_BU(vector<int> &nums, int target)
    {

        dp[0] = 1;
        sort(nums.begin(), nums.end());
        for (int cur_target = 1; cur_target <= target; cur_target++)
        {
            dp[cur_target] = 0;
            for (int &x : nums)
            {
                if (x <= cur_target)
                    dp[cur_target] += dp[cur_target - x];
                else
                    break;
            }
        }
        return dp[target];
    }

public:
    int combinationSum4(vector<int> &nums, int target)
    {
        memset(dp, -1, sizeof(dp));
        // return combination_sum(nums, 0, target);
        return combination_sum_BU(nums, target);
    }
};
// @lc code=end
