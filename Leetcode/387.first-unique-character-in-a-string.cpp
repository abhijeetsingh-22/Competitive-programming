/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 */

// @lc code=start
class Solution
{
public:
    int firstUniqChar(string s)
    {
        unordered_map<char, int> map;
        for (char &c : s)
            map[c]++;
        int n = s.size();
        for (int idx = 0; idx < n; idx++)
        {
            if (map[s[idx]] == 1)
                return idx;
        }
        return -1;
    }
};
// @lc code=end
