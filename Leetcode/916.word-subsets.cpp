/*
 * @lc app=leetcode id=916 lang=cpp
 *
 * [916] Word Subsets
 */

// @lc code=start
class Solution
{
private:
    static bool is_super_set(string &word, vector<int> map)
    {
        for (char c : word)
        {
            map[c - 'a']--;
        }
        for (int x : map)
        {
            if (x > 0)
                return false;
        }
        return true;
    }

public:
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
    {

        vector<int> map(26, 0);
        vector<string> ans;

        for (string s : words2)
        {
            vector<int> cur_map(26, 0);
            for (char c : s)
            {
                cur_map[c - 'a']++;
            }
            for (int i = 0; i < 26; i++)
            {
                map[i] = max(map[i], cur_map[i]);
            }
        }

        for (string w : words1)
        {
            if (is_super_set(w, map))
            {
                ans.push_back(w);
            }
        }
        return ans;
    }
};
// @lc code=end
