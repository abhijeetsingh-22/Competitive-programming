/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 */

// @lc code=start
class Solution
{
    bool check(int start, string s, vector<string> &words, unordered_map<string, int> &word_count)
    {
        int word_len = words[0].size();
        int no_words = words.size();
        int str_len = s.size();
        int target_len = no_words * word_len;
        unordered_map<string, int> remaining(word_count);
        int count = 0;
        for (int idx = start; idx < idx + target_len; idx += word_len)
        {
            string cur_word = s.substr(idx, word_len);
            if (remaining[cur_word] > 0)
            {
                remaining[cur_word]--;
                count++;
            }
            else
                break;
        }
        return count == no_words;
    }

public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        int word_len = words[0].size();
        int no_words = words.size();
        int str_len = s.size();

        unordered_map<string, int> word_count;
        for (string &s : words)
        {
            word_count[s]++;
        }
        vector<int> ans;
        for (int idx = 0; idx <= str_len - (no_words * word_len); idx++)
        {
            if (check(idx, s, words, word_count))
                ans.push_back(idx);
        }

        return ans;
    }
};
// @lc code=end
