/*
 * @lc app=leetcode id=326 lang=cpp
 *
 * [326] Power of Three
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    // Recursive way is very easy to implement
    static bool is_power_3(int n)
    {
        if (n == 1)
            return true;
        if (n <= 0 or n % 3 != 0)
            return false;
        return is_power_3(n / 3);
    }

public:
    bool isPowerOfThree(int n)
    {
        int maxPowerOfThree = (int)pow(3, (int)(log(0x7fffffff) / log(3)));
        return n > 0 and maxPowerOfThree % n == 0;
        // return is_power_3(n);
    }
};
// @lc code=end
