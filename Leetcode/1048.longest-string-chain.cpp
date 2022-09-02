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

public:
    int longestStrChain(vector<string> &words)
    {
        int n = words.size();
        sort(words.begin(), words.end(), compare);

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return longest_string_chain(0, -1, n, words, dp);
    }
};
// @lc code=end
