/*
 * @lc app=leetcode id=1312 lang=cpp
 *
 * [1312] Minimum Insertion Steps to Make a String Palindrome
 */

// @lc code=start
class Solution
{
    int lcs(int idx1, int idx2, string &s1, string &s2, vector<vector<int>> &dp)
    {
        if (idx1 < 0 or idx2 < 0)
            return 0;
        if (dp[idx1][idx2] != -1)
            return dp[idx1][idx2];

        if (s1[idx1] == s2[idx2])
            return dp[idx1][idx2] = 1 + lcs(idx1 - 1, idx2 - 1, s1, s2, dp);
        int ans = 0;
        ans = max(lcs(idx1 - 1, idx2, s1, s2, dp), lcs(idx1, idx2 - 1, s1, s2, dp));

        return dp[idx1][idx2] = ans;
    }
    int lcs_bottomup(string s1, string s2)
    {
        int n = s1.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int idx1 = 1; idx1 <= n; idx1++)
        {
            for (int idx2 = 1; idx2 <= n; idx2++)
            {
                if (s1[idx1 - 1] == s2[idx2 - 1])
                    dp[idx1][idx2] = 1 + dp[idx1 - 1][idx2 - 1];
                else
                    dp[idx1][idx2] = max(dp[idx1 - 1][idx2], dp[idx1][idx2 - 1]);
            }
        }
        return dp[n][n];
    }
    int lcs_sopt(string s1, string s2)
    {
        int n = s1.size();
        vector<int> prev(n + 1, 0), cur(n + 1, 0);
        for (int idx1 = 1; idx1 <= n; idx1++)
        {
            for (int idx2 = 1; idx2 <= n; idx2++)
            {
                if (s1[idx1 - 1] == s2[idx2 - 1])
                    cur[idx2] = 1 + prev[idx2 - 1];
                else
                    cur[idx2] = max(prev[idx2], cur[idx2 - 1]);
            }
            prev = cur;
        }
        return prev[n];
    }

public:
    int minInsertions(string s)
    {
        string t(s);
        reverse(t.begin(), t.end());
        int n = s.size();
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        //
        // return n - lcs_bottomup(s, t);

        return n - lcs_sopt(s, t);
    }
};
// @lc code=end
