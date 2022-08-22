/*
 * @lc app=leetcode id=342 lang=cpp
 *
 * [342] Power of Four
 */

// @lc code=start
class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        while (n > 1 and n % 4 == 0)
        {
            n = n / 4;
        }
        return n == 1;
    }
};
// @lc code=end
