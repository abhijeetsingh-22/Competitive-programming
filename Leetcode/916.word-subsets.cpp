/*
 * @lc app=leetcode id=916 lang=cpp
 *
 * [916] Word Subsets
 */

// @lc code=start
class Solution
{
private:
    static bool is_super_set(string &word, int *max_freq)
    {
        int *freq = count_freq(word);
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] < max_freq[i])
                return false;
        }
        return true;
    }
    static int *count_freq(string &word)
    {
        int freq[26] = {0};
        for (char &c : word)
        {
            freq[c - 'a']++;
        }
        return freq;
    }

public:
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
    {

        int max_freq[26] = {0};
        vector<string> ans;

        for (string &s : words2)
        {
            int *cur_freq = count_freq(s);

            for (int i = 0; i < 26; i++)
            {
                max_freq[i] = max(max_freq[i], cur_freq[i]);
            }
        }

        for (string &w : words1)
        {
            if (is_super_set(w, max_freq))
            {
                ans.push_back(w);
            }
        }
        return ans;
    }
};
// @lc code=end
