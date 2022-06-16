/*
 * @lc app=leetcode id=1552 lang=cpp
 *
 * [1552] Magnetic Force Between Two Balls
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    static bool canPlace(vector<int> &p, int force, int m)
    {
        int n = p.size();
        int idx = 0, prevIdx = 0;
        m--;
        while (idx < n)
        {
            if (p[idx] - p[prevIdx] >= force)
            {
                m--;
                prevIdx = idx;
                idx++;
                if (m == 0)
                    return true;
            }
            else
                idx++;
        }
        return false;
    }

public:
    int maxDistance(vector<int> &position, int m)
    {
        sort(position.begin(), position.end());
        int n = position.size();
        int s = 0, e = position[n - 1] - position[0], mid, ans = -1;
        while (s <= e)
        {
            mid = (s + e) / 2;
            if (canPlace(position, mid, m))
            {
                ans = mid;
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
        return ans;
    }
};
// @lc code=end
