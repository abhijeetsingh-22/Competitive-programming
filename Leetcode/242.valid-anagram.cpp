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

        int size_t = t.size(), size_s = s.size();

        if (size_t != size_s)
            return false;
        for (char c : s)
        {
            map[c - 'a']++;
        }
        for (char c : t)
        {
            map[c - 'a']--;
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
