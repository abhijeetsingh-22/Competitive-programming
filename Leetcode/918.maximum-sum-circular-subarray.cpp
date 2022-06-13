/*
 * @lc app=leetcode id=918 lang=cpp
 *
 * [918] Maximum Sum Circular Subarray
 */

// @lc code=start
class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &nums)
    {
        int n = nums.size();
        int curMax = 0, curMin = 0, maxSum = 0, minSum = 0, sum = 0, maxVal = -30000, idx, ans = 0;
        for (int i = 0; i < n; i++)
        {
            curMax += nums[i];
            curMin += nums[i];
            if (curMax < 0)
                curMax = 0;
            if (curMin > 0)
                curMin = 0;
            maxSum = max(maxSum, curMax);
            minSum = min(minSum, curMin);
            maxVal = max(maxVal, nums[i]);
            sum += nums[i];
        }
        return maxSum == 0 && sum < 0 ? maxVal : max(maxSum, (sum - minSum));
    }
};
// @lc code=end
