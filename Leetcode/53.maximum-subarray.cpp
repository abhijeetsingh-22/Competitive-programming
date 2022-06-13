/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size(), curSum = 0, maxSum = 0, maxVal = -10000;

        for (int i = 0; i < n; i++)
        {
            curSum += nums[i];
            if (curSum <= 0)
            {
                curSum = 0;
            }
            maxSum = max(curSum, maxSum);
            maxVal = max(maxVal, nums[i]);
        }
        if (maxSum == 0)
            return maxVal;
        else
            return maxSum;
    }
};
// @lc code=end
