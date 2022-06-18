/*
 * @lc app=leetcode id=260 lang=cpp
 *
 * [260] Single Number III
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        int x = 0;
        vector<int> ans(2, 0);
        int j = 0;
        for (int n : nums)
        {
            x = x ^ n;
        }
        while (((x >> j) & 1) == 0)
        {
            j++;
        }

        for (int n : nums)
        {
            if (n & (1 << j))
            {
                ans[0] = ans[0] ^ n;
            }
        }
        ans[1] = x ^ ans[0];
        return ans;
    }
};
// @lc code=end
