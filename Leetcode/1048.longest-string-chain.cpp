/*
 * @lc app=leetcode id=1048 lang=cpp
 *
 * [1048] Longest String Chain
 */

// @lc code=start
class Solution
{
    bool can_take(string &s1, string &s2)
    {
        if (s1.size() != s2.size() + 1)
            return false;
        int n1 = s1.size(), n2 = s2.size();
        int i = 0, j = 0;

        while (i < n1)
        {

            if (s1[i] == s2[j])
            {
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }
        return i == n1 and j == n2;
    }
    int longest_string_chain(int idx, int prev_idx, int n, vector<string> &words, vector<vector<int>> &dp)
    {
        if (idx == n)
            return 0;
        if (dp[idx][prev_idx + 1] != -1)
            return dp[idx][prev_idx + 1];
        int not_take = longest_string_chain(idx + 1, prev_idx, n, words, dp);
        int take = INT_MIN;
        if (prev_idx == -1 or can_take(words[idx], words[prev_idx]))
        {
            take = 1 + longest_string_chain(idx + 1, idx, n, words, dp);
        }
        return dp[idx][prev_idx + 1] = max(take, not_take);
    }
    static bool compare(string s1, string s2)
    {
        return s1.size() < s2.size();
    }
    int longest_strc_opt(vector<string> &words)
    {
        int n = words.size();
        vector<int> dp(n, 1);
        int maxi = 1;
        for (int idx = 0; idx < n; idx++)
        {
            for (int prev_idx = 0; prev_idx < idx; prev_idx++)
            {
                if (can_take(words[idx], words[prev_idx]) and dp[idx] < 1 + dp[prev_idx])
                {
                    dp[idx] = 1 + dp[prev_idx];
                }
            }
            maxi = max(maxi, dp[idx]);
        }
        return maxi;
    }
    int longetst_strc(vector<string> &words)
    {
        unordered_map<string, int> dp;
        int maxi = 1;
        for (string &word : words)
        {
            int word_len = word.size();
            dp[word] = 1;

            for (int i = 0; i < word_len; i++)
            {
                string prev = word.substr(0, i) + word.substr(i + 1);
                if (dp.find(prev) != dp.end())
                {
                    dp[word] = max(dp[word], 1 + dp[prev]);
                }
            }
            maxi = max(maxi, dp[word]);
        }
        return maxi;
    }

public:
    int longestStrChain(vector<string> &words)
    {
        int n = words.size();
        sort(words.begin(), words.end(), compare);

        // vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        // return longest_string_chain(0, -1, n, words, dp);
        // return longest_strc_opt(words);
        return longetst_strc(words);
    }
};
// @lc code=end
