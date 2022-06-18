/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    static int getSetBits(int num)
    {
        int count = 0;
        while (num > 0)
        {
            num = num & (num - 1);
            count++;
        }
        return count;
    }

public:
    vector<int> countBits(int n)
    {

        vector<int> ans(n + 1, 0);
        for (int i = 0; i <= n; i++)
        {
            int setBits = getSetBits(i);
            ans[i] = setBits;
        }

        return ans;
    }
};
// @lc code=end
