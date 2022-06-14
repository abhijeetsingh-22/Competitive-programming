/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();

        int i = n - 2;

        while (i >= 0 && nums[i] >= nums[i + 1])
            i--;
        if (i < 0)
        {
            sort(nums.begin(), nums.end());
        }
        else
        {
            reverse(nums.begin() + i + 1, nums.end());
            int minRightIdx = upper_bound(nums.begin() + i + 1, nums.end(), nums[i]) - nums.begin();
            swap(nums[i], nums[minRightIdx]);
            sort(nums.begin() + i + 1, nums.end());
        }
    }
};
// @lc code=end
