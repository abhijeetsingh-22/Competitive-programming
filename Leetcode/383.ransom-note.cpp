/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 */

// @lc code=start
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        int freq[26] = {0};
        for (char &s : magazine)
        {
            freq[s - 'a']++;
        }
        for (char &s : ransomNote)
        {
            if (freq[s - 'a'] == 0)
                return false;
            freq[s - 'a']--;
        }
        return true;
    }
};
// @lc code=end
