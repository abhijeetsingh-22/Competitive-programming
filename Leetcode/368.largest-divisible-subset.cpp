/*
 * @lc app=leetcode id=368 lang=cpp
 *
 * [368] Largest Divisible Subset
 */

// @lc code=start
class Solution
{
    vector<int> divisible_subset_bottomup(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end(), greater<int>());
        // 1 based indexing for prev_idx
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int idx = n - 1; idx >= 0; idx--)
        {
            for (int prev_idx = -1; prev_idx < idx; prev_idx++)
            {
                int not_take = dp[idx + 1][prev_idx + 1];
                int take = INT_MIN;
                if (prev_idx == -1 or nums[prev_idx] % nums[idx] == 0)
                {
                    take = 1 + dp[idx + 1][idx + 1];
                }
                dp[idx][prev_idx + 1] = max(take, not_take);
            }
        }

        int row = 0, col = 0;
        vector<int> ans;
        while (row < n and col < n)
        {
            if (dp[row][col] == dp[row + 1][col])
                row++;
            else
            {
                ans.push_back(nums[row]);
                col = row + 1;
                row++;
            }
        }

        return ans;
    }
    vector<int> divisible_subset_opt(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        // dp[i] is length of LDS ending at i
        vector<int> dp(n, 1);
        vector<int> hash(n, 0);
        int last_idx = 0, maxi = 0;
        for (int idx = 0; idx < n; idx++)
        {
            hash[idx] = idx;
            for (int prev_idx = 0; prev_idx < idx; prev_idx++)
            {
                if (nums[idx] % nums[prev_idx] == 0 and dp[idx] < 1 + dp[prev_idx])
                {
                    hash[idx] = prev_idx;
                    dp[idx] = 1 + dp[prev_idx];
                }
            }
            if (dp[idx] > maxi)
            {
                maxi = dp[idx];
                last_idx = idx;
            }
        }
        vector<int> ans;
        ans.push_back(nums[last_idx]);
        while (hash[last_idx] != last_idx)
        {
            last_idx = hash[last_idx];
            ans.push_back(nums[last_idx]);
        }
        return ans;
    }

public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        // return divisible_subset_bottomup(nums);
        return divisible_subset_opt(nums);
    }
};
// @lc code=end
