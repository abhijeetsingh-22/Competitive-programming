/*
 * @lc app=leetcode id=476 lang=cpp
 *
 * [476] Number Complement
 */

// @lc code=start
class Solution
{
public:
    int findComplement(int num)
    {
        long long ans = 0, factor = 1;
        while (num > 0)
        {
            int lastBit = num & 1;
            if (lastBit == 0)
            {
                ans += factor;
            }
            num = num >> 1;
            factor *= 2;
        }
        return ans;
    }
};
// @lc code=end
