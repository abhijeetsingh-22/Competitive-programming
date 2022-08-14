/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 */

// @lc code=start
class Solution
{
    // retruns LCS from 0-idx1 (s1 ) and 0-idx2(s2)
    int lcs_rec(int idx1, int idx2, string s1, string s2, vector<vector<int>> &dp)
    {

        if (idx1 < 0 or idx2 < 0)
            return 0;
        if (dp[idx1][idx2] != -1)
            return dp[idx1][idx2];
        if (s1[idx1] == s2[idx2])
            return dp[idx1][idx2] = 1 + lcs_rec(idx1 - 1, idx2 - 1, s1, s2, dp);

        return dp[idx1][idx2] = max(lcs_rec(idx1 - 1, idx2, s1, s2, dp), lcs_rec(idx1, idx2 - 1, s1, s2, dp));
    }
    int lcs_bottomup(string s1, string s2)
    {
        int n1 = s1.size();
        int n2 = s2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        for (int idx1 = 0; idx1 <= n1; idx1++)
            dp[idx1][0] = 0;

        for (int idx1 = 1; idx1 <= n1; idx1++)
        {
            for (int idx2 = 1; idx2 <= n2; idx2++)
            {

                if (s1[idx1 - 1] == s2[idx2 - 1])
                    dp[idx1][idx2] = 1 + dp[idx1 - 1][idx2 - 1];
                else
                    dp[idx1][idx2] = max(dp[idx1 - 1][idx2], dp[idx1][idx2 - 1]);
            }
        }
        return dp[n1][n2];
    }
    int lcs_sopt(string s1, string s2)
    {
        int n1 = s1.size();
        int n2 = s2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        vector<int> prev(n2 + 1, 0), cur(n2 + 1, 0);

        // for (int idx1 = 0; idx1 <= n1; idx1++)
        //     dp[idx1][0] = 0;

        for (int idx1 = 1; idx1 <= n1; idx1++)
        {
            for (int idx2 = 1; idx2 <= n2; idx2++)
            {

                if (s1[idx1 - 1] == s2[idx2 - 1])
                    cur[idx2] = 1 + prev[idx2 - 1];
                else
                    cur[idx2] = max(prev[idx2], cur[idx2 - 1]);
            }
            prev = cur;
        }
        return prev[n2];
    }

public:
    int longestCommonSubsequence(string text1, string text2)
    {
        // int n1 = text1.size();
        // int n2 = text2.size();
        // vector<vector<int>> dp(n1, vector<int>(n2, -1));
        // return lcs_rec(n1 - 1, n2 - 1, text1, text2, dp);
        // return lcs_bottomup(text1, text2);
        return lcs_sopt(text1, text2);
    }
};
// @lc code=end
