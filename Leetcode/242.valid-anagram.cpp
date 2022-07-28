/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        vector<int> map(26, 0);

        if (s.size() != t.size())
            return false;

        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            map[s[i] - 'a']++;
            map[t[i] - 'a']--;
        }
        for (int x : map)
        {
            if (x != 0)
                return false;
        }
        return true;
    }
};
// @lc code=end
