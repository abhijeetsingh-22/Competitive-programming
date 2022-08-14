/*
 * @lc app=leetcode id=516 lang=cpp
 *
 * [516] Longest Palindromic Subsequence
 */

// @lc code=start
class Solution
{
    int f(int start, int end, string &s, vector<vector<int>> &dp)
    {
        if (start > end)
            return 0;
        if (start == end)
            return 1;
        if (dp[start][end] != -1)
            return dp[start][end];

        if (s[start] == s[end])
            return dp[start][end] = 2 + f(start + 1, end - 1, s, dp);
        int ans = 0;
        ans = max(ans, f(start, end - 1, s, dp));
        ans = max(ans, f(start + 1, end, s, dp));
        return dp[start][end] = ans;
    }

    int lcs(int idx1, int idx2, string &s1, string &s2, vector<vector<int>> &dp)
    {
        if (idx1 < 0 or idx2 < 0)
            return 0;

        if (dp[idx1][idx2] != -1)
            return dp[idx1][idx2];
        if (s1[idx1] == s2[idx2])
            return dp[idx1][idx2] = 1 + lcs(idx1 - 1, idx2 - 1, s1, s2, dp);
        int ans = 0;
        ans = max(ans, lcs(idx1 - 1, idx2, s1, s2, dp));
        ans = max(ans, lcs(idx1, idx2 - 1, s1, s2, dp));

        return dp[idx1][idx2] = ans;
    }
    int lcs_bottomup(string &s1, string &s2)
    {
        int n = s1.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int idx1 = 1; idx1 <= n; idx1++)
        {
            for (int idx2 = 1; idx2 <= n; idx2++)
            {
                if (s1[idx1 - 1] == s2[idx2 - 1])
                {
                    dp[idx1][idx2] = 1 + dp[idx1 - 1][idx2 - 1];
                }
                else
                {
                    dp[idx1][idx2] = max(dp[idx1 - 1][idx2], dp[idx1][idx2 - 1]);
                }
            }
        }
        return dp[n][n];
    }
    int lcs_sopt(string &s1, string &s2)
    {
        int n = s1.size();
        vector<int> prev(n + 1, 0), cur(n + 1, 0);

        for (int idx1 = 1; idx1 <= n; idx1++)
        {
            for (int idx2 = 1; idx2 <= n; idx2++)
            {
                if (s1[idx1 - 1] == s2[idx2 - 1])
                {
                    cur[idx2] = 1 + prev[idx2 - 1];
                }
                else
                {
                    cur[idx2] = max(prev[idx2], cur[idx2 - 1]);
                }
            }
            prev = cur;
        }
        return prev[n];
    }
    // int longest_palindrome_bottomup(string &s)
    // {
    //     int n = s.size();
    //     vector<vector<int>> dp(n, vector<int>(n, 0));

    //     for (int start = 0; start < n; start++)
    //     {
    //         for (int end =)
    //     }
    // }

public:
    int longestPalindromeSubseq(string s)
    {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        // return f(0, n - 1, s, dp);
        string t = s;
        reverse(t.begin(), t.end());
        // return lcs(n - 1, n - 1, s, t, dp);
        // return lcs_bottomup(s, t);
        return lcs_sopt(s, t);
    }
};
// @lc code=end
