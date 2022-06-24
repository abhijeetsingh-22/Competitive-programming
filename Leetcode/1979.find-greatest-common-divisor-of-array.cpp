/*
 * @lc app=leetcode id=1979 lang=cpp
 *
 * [1979] Find Greatest Common Divisor of Array
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    static int gcd(int a, int b)
    {
        return b == 0 ? a : gcd(b, a % b);
    }

public:
    int findGCD(vector<int> &nums)
    {
        int maxVal = *max_element(nums.begin(), nums.end());
        int minVal = *min_element(nums.begin(), nums.end());
        return gcd(minVal, maxVal);
    }
};
// @lc code=end
