/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 */

// @lc code=start
class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int s_idx = 0;
        int l_idx = s.size() - 1;
        while (s_idx < l_idx)
        {
            swap(s[s_idx++], s[l_idx--]);
        }
    }
};
// @lc code=end
