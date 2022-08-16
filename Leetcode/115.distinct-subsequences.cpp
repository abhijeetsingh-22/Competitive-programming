/*
 * @lc app=leetcode id=115 lang=cpp
 *
 * [115] Distinct Subsequences
 */

// @lc code=start
class Solution
{
    int cout_subsequence(int idx1, int idx2, string &s1, string &s2, vector<vector<int>> &dp)
    {
        // one based indexing
        if (idx2 == 0)
            return 1;
        if (idx1 == 0)
            return 0;
        if (dp[idx1][idx2] != -1)
            return dp[idx1][idx2];
        int take = 0;
        if (s1[idx1 - 1] == s2[idx2 - 1])
            take = cout_subsequence(idx1 - 1, idx2 - 1, s1, s2, dp);
        int not_take = cout_subsequence(idx1 - 1, idx2, s1, s2, dp);

        return dp[idx1][idx2] = take + not_take;
    }

    int count_ss_bottomup(string &s1, string &s2)
    {
        int n1 = s1.size();
        int n2 = s2.size();
        vector<vector<double>> dp(n1 + 1, vector<double>(n2 + 1, 0));
        for (int idx1 = 0; idx1 <= n1; idx1++)
            dp[idx1][0] = 1;
        for (int idx1 = 1; idx1 <= n1; idx1++)
        {
            for (int idx2 = 1; idx2 <= n2; idx2++)
            {
                if (s1[idx1 - 1] == s2[idx2 - 1])
                    dp[idx1][idx2] = dp[idx1 - 1][idx2 - 1] + dp[idx1 - 1][idx2];
                else
                    dp[idx1][idx2] = dp[idx1 - 1][idx2];
            }
        }
        return (int)dp[n1][n2];
    }
    int count_ss_sopt(string &s1, string &s2)
    {
        int n1 = s1.size();
        int n2 = s2.size();
        vector<double> prev(n2 + 1, 0);
        prev[0] = 1;
        for (int idx1 = 1; idx1 <= n1; idx1++)
        {
            for (int idx2 = n2; idx2 >= 1; idx2--)
            {
                if (s1[idx1 - 1] == s2[idx2 - 1])
                    prev[idx2] = prev[idx2 - 1] + prev[idx2];
                // else
                //     prev[idx2] = prev[idx2];
            }
        }
        return (int)prev[n2];
    }

public:
    int numDistinct(string s, string t)
    {
        // int n1 = s.size();
        // int n2 = t.size();
        // vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
        // return cout_subsequence(n1, n2, s, t, dp);
        // return count_ss_bottomup(s, t);
        return count_ss_sopt(s, t);
    }
};
// @lc code=end
