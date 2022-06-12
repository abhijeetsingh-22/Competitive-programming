/*
 * @lc app=leetcode id=561 lang=cpp
 *
 * [561] Array Partition I
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int arrayPairSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        int ans = 0;
        for (int i = nums.size() - 2; i >= 0; i -= 2)
        {
            ans += nums[i];
        }
        return ans;
    }
};
// @lc code=end
