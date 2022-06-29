/*
 * @lc app=leetcode id=231 lang=cpp
 *
 * [231] Power of Two
 */

// @lc code=start
class Solution

{
private:
    // Recursive solution
    static bool is_power(int n)
    {
        if (n == 1)
            return true;
        if (n == 0)
            return false;
        if (n % 2 != 0)
            return false;
        return is_power(n >> 1);
    }

public:
    bool isPowerOfTwo(int n)
    {
        // return is_power(n);
        return n > 0 ? !(n & (n - 1)) : false;
    }
};
// @lc code=end
