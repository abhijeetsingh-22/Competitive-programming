/*
 * @lc app=leetcode id=858 lang=cpp
 *
 * [858] Mirror Reflection
 */

// @lc code=start
class Solution
{
public:
    int mirrorReflection(int p, int q)
    {
        // m*p=n*q
        int m = q, n = p;
        while (m % 2 == 0 && n % 2 == 0)
        {
            m /= 2;
            n /= 2;
        }
        if (m % 2 == 0)
            return 0;
        if (m % 2 == 1 && n % 2 == 1)
            return 1;
        if (m % 2 == 1 && n % 2 == 0)
            return 2;
        return -1;
    }
};
// @lc code=end
