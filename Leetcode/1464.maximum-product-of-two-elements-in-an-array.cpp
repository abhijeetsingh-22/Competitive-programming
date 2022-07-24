/*
 * @lc app=leetcode id=1464 lang=cpp
 *
 * [1464] Maximum Product of Two Elements in an Array
 */

// @lc code=start
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        priority_queue<int> pq(nums.begin(), nums.end());

        int max = pq.top();
        pq.pop();
        int s_max = pq.top();
        return (max - 1) * (s_max - 1);
    }
};
// @lc code=end
