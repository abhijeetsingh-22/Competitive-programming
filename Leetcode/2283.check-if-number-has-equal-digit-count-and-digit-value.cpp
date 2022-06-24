/*
 * @lc app=leetcode id=2283 lang=cpp
 *
 * [2283] Check if Number Has Equal Digit Count and Digit Value
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool digitCount(string num)
    {
        int n = num.length();
        int freq[10] = {0};

        for (int i = 0; i < n; i++)
        {
            int n = num[i] - 48;
            freq[n] += 1;
        }
        for (int i = 0; i < n; i++)
        {
            if ((int)num[i] - 48 != freq[i])
                return false;
        }
        return true;
    }
};
// @lc code=end
