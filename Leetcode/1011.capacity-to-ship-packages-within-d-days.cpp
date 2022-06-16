/*
 * @lc app=leetcode id=1011 lang=cpp
 *
 * [1011] Capacity To Ship Packages Within D Days
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    static bool isShippingPossible(vector<int> &weights, int days, int capacity)
    {
        int curWeight = 0, curDays = 1;
        for (auto w : weights)
        {
            if (w > capacity)
                return false;
            if (curWeight + w <= capacity)
            {
                curWeight += w;
            }
            else
            {
                curDays++;
                curWeight = w;
            }
        }
        return curDays <= days;
    }

public:
    int shipWithinDays(vector<int> &weights, int days)
    {
        int n = weights.size();
        int s = 0, e = n * 500, mid, ans = -1;
        while (s <= e)
        {
            mid = (s + e) / 2;
            if (isShippingPossible(weights, days, mid))
            {
                ans = mid;
                e = mid - 1;
            }
            else
                s = mid + 1;
        }
        return ans;
    }
};
// @lc code=end
