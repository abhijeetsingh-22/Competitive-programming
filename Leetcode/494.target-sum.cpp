/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */

// @lc code=start
class Solution
{
    int find_ways(int idx, int tar, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (idx == 0)
        {
            if (tar == 0 and nums[0] == 0)
                return 2;
            if (tar == 0 or tar == nums[0])
                return 1;
            return 0;
        }
        if (dp[idx][tar] != -1)
            return dp[idx][tar];
        int take = 0;
        if (nums[idx] <= tar)
            take = find_ways(idx - 1, tar - nums[idx], nums, dp);

        int not_take = find_ways(idx - 1, tar, nums, dp);

        return dp[idx][tar] = take + not_take;
    }

    int find_ways_bottomup(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(k + 1, 0));

        dp[0][0] = 1;
        if (nums[0] <= k)
            dp[0][nums[0]] = 1;
        if (nums[0] == 0)
            dp[0][0] = 2;

        for (int idx = 1; idx < n; idx++)
            for (int target = 0; target <= k; target++)
            {
                int take = 0;
                if (nums[idx] <= target)
                    take = dp[idx - 1][target - nums[idx]];
                int not_take = dp[idx - 1][target];
                dp[idx][target] = take + not_take;
            }
        return dp[n - 1][k];
    }
    int find_ways_sopt(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> prev(k + 1, 0), cur(k + 1, 0);

        prev[0] = 1;
        if (nums[0] <= k)
            prev[nums[0]] = 1;
        if (nums[0] == 0)
            prev[0] = 2;

        for (int idx = 1; idx < n; idx++)
        {
            for (int target = 0; target <= k; target++)
            {
                int take = 0;
                if (nums[idx] <= target)
                    take = prev[target - nums[idx]];
                int not_take = prev[target];
                cur[target] = take + not_take;
            }
            prev = cur;
        }
        return prev[k];
    }

public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int n = nums.size();
        int sum = 0;
        for (int &x : nums)
            sum += x;
        // vector<unordered_map<int, int>> dp(n);
        if (target > sum or target < -sum or (sum + target) % 2 != 0)
            return 0;

        int new_target = (sum + target) / 2;
        // vector<vector<int>> dp(n, vector<int>(new_target + 1, -1));
        // return find_ways(n - 1, new_target, nums, dp);
        // return find_ways_bottomup(nums, new_target);
        return find_ways_sopt(nums, new_target);
    }
};
// @lc code=end
