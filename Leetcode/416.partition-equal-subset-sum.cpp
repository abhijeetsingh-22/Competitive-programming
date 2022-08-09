/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
class Solution
{
    bool can_partition(int idx, int target, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (target == 0)
            return true;
        if (idx == 0)
        {
            if (nums[idx] == target)
                return true;
            return false;
        }
        if (dp[idx][target] != -1)
            return dp[idx][target];
        bool not_take = can_partition(idx - 1, target, nums, dp);
        bool take = false;
        if (nums[idx] <= target)
            take = can_partition(idx - 1, target - nums[idx], nums, dp);

        return dp[idx][target] = not_take or take;
    }
    bool can_partition_bottomup(vector<int> &nums)
    {
        int n = nums.size();
        int sum = 0;
        for (int &x : nums)
        {
            sum += x;
        }
        if (sum & 1)
            return false;

        vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));
        sum = sum / 2;

        for (int idx = 0; idx < n; idx++)
            dp[idx][0] = true;

        dp[0][nums[0]] = true;

        for (int idx = 1; idx < n; idx++)
        {
            for (int target = 1; target <= sum; target++)
            {
                bool not_take = dp[idx - 1][target];
                bool take = false;
                if (target >= nums[idx])
                    take = dp[idx - 1][target - nums[idx]];

                dp[idx][target] = take or not_take;
            }
        }
        return dp[n - 1][sum];
    }
    bool can_partition_sopt(vector<int> &nums)
    {
        int n = nums.size();
        int sum = 0;
        for (int &x : nums)
        {
            sum += x;
        }
        if (sum & 1)
            return false;

        vector<bool> prev(sum + 1, false);
        sum = sum / 2;
        prev[0] = true;
        prev[nums[0]] = true;

        for (int idx = 1; idx < n; idx++)
        {
            vector<bool> cur(sum + 1, false);
            cur[0] = true;
            for (int target = 1; target <= sum; target++)
            {
                bool not_take = prev[target];
                bool take = false;
                if (target >= nums[idx])
                    take = prev[target - nums[idx]];
                // cout << idx << "   " << target << "  " << take << "  " << not_take << endl;
                cur[target] = take or not_take;
            }
            prev = cur;
        }
        return prev[sum];
    }

public:
    bool canPartition(vector<int> &nums)
    {

        // int n = nums.size();
        // bool ans = false;
        // int sum = 0;
        // for (int &x : nums)
        // {
        //     sum += x;
        // }
        // vector<vector<int>> dp(n, vector<int>(sum / 2 + 1, -1));
        // return sum & 1 ? false : can_partition(n - 1, sum / 2, nums, dp);
        // return can_partition_bottomup(nums);
        return can_partition_sopt(nums);
    }
};
// @lc code=end
