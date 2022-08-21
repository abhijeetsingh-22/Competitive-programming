/*
 * @lc app=leetcode id=936 lang=cpp
 *
 * [936] Stamping The Sequence
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    bool can_replace(int pos, string target, string stamp)
    {
        int stamp_len = stamp.size();
        for (int i = 0; i < stamp_len; i++)
        {
            if (target[pos + i] != stamp[i] and target[pos + i] != '?')
                return false;
        }

        return true;
    }

public:
    vector<int> movesToStamp(string stamp, string target)
    {
        vector<int> ans;
        int qm = 0;
        int target_len = target.size();
        int stamp_len = stamp.size();
        vector<bool> vis(target_len, false);

        while (qm != target_len)
        {
            bool did_replace = false;
            for (int idx = 0; idx <= target_len - stamp_len; idx++)
            {
                if (!vis[idx] and can_replace(idx, target, stamp))
                {
                    for (int i = 0; i < stamp_len; i++)
                    {
                        if (target[idx + i] != '?')
                        {
                            qm++;
                            target[idx + i] = '?';
                        }
                    }
                    vis[idx] = true;
                    ans.push_back(idx);
                    did_replace = true;
                    break;
                }
            }
            if (!did_replace)
                return {};
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end
