/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */
// @lc code=start
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int i = 0, j = 1;
        for (; j < nums.size(); j++)
        {
            if (nums[i] != nums[j])
            {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};
// @lc code=end
