/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution
{
private:
    // starting position and ending position
    static pair<int, int> binary_search(vector<int> &nums, int s, int e, int target)
    {
        if (s > e)
            return {-1, -1};

        int mid = (s + e) / 2;

        if (nums[mid] < target)
        {
            return binary_search(nums, mid + 1, e, target);
        }
        if (nums[mid] > target)
        {
            return binary_search(nums, s, mid - 1, target);
        }

        pair<int, int> left = binary_search(nums, s, mid - 1, target);
        pair<int, int> right = binary_search(nums, mid + 1, e, target);

        int start_idx = left.first > -1 ? left.first : mid;
        int end_idx = right.second > -1 ? right.second : mid;
        return {start_idx, end_idx};
    }

public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        pair<int, int> ans = binary_search(nums, 0, nums.size() - 1, target);
        return {ans.first, ans.second};
    }
};
// @lc code=end
