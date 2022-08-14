/*
 * @lc app=leetcode id=126 lang=cpp
 *
 * [126] Word Ladder II
 */

// @lc code=start
class Solution
{
    bitset<500> available;
    int n;
    bool is_valid_pair(string &s1, string &s2)
    {
        int n = s1.size();
        bool diff_found = false;

        for (int i = 0; i < n; i++)
        {
            if (s1[i] != s2[i])
            {
                if (!diff_found)
                    diff_found = true;
                else
                    return false;
            }
        }
        return true;
    }
    int min_steps(string &prev, vector<string> &cur_path, vector<vector<string>> &ans, string &end, vector<string> &word_list)
    {
        if (prev == end)
        {
            ans.push_back(cur_path);
            return 0;
        }
        if (available.none())
            return INT_MAX;
        int min_val = INT_MAX;

        for (int idx = 0; idx < n; idx++)
        {
            string s = word_list[idx];

            if (available[idx] and is_valid_pair(prev, s))
            {
                cur_path.push_back(s);
                available[idx] = 0;
                int cur_steps = min_steps(s, cur_path, ans, end, word_list);
                available[idx] = 1;
                cur_path.pop_back();
                if (cur_steps != INT_MAX)
                    min_val = min(min_val, cur_steps + 1);
            }
        }
        return min_val;
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        int word_list_length = wordList.size();
        n = wordList.size();
        for (int i = 0; i < word_list_length; i++)
        {
            available[i] = 1;
        }
        vector<vector<string>> ans;
        vector<vector<string>> ret;
        vector<string> cur_path;
        cur_path.push_back(beginWord);
        int min_s = min_steps(beginWord, cur_path, ans, endWord, wordList);

        for (vector<string> &path : ans)
        {
            if (path.size() == min_s + 1)
                ret.push_back(path);
        }
        return ret;
    }
};
// @lc code=end
