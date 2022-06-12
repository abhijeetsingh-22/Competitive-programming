/*
 * @lc app=leetcode id=905 lang=cpp
 *
 * [905] Sort Array By Parity
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        int i = 0, j = 0;
        while (1)
        {
            // find next even
            while (i < nums.size() && nums[i] % 2 != 0)
            {
                i++;
            }
            if (i >= nums.size())
                return nums;
            // find next odd
            while (j < nums.size() && nums[j] % 2 == 0)
            {
                j++;
            }
            if (j >= nums.size())
                return nums;
            if (j < i)
            {
                swap(nums[i], nums[j]);
            }
            i++;
        }
        return nums;
    }
};
// @lc code=end
