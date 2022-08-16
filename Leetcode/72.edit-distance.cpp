/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 */

// @lc code=start
class Solution
{
    int min_operations(int idx1, int idx2, string &s1, string &s2, vector<vector<int>> &dp)
    {
        if (idx2 == 0)
            return idx1;
        if (idx1 == 0)
            return idx2;
        if (dp[idx1][idx2] != -1)
            return dp[idx1][idx2];
        int match = INT_MAX;
        if (s1[idx1 - 1] == s2[idx2 - 1])
        {
            match = min_operations(idx1 - 1, idx2 - 1, s1, s2, dp);
        }
        int rep = 1 + min_operations(idx1 - 1, idx2 - 1, s1, s2, dp);
        int del = 1 + min_operations(idx1 - 1, idx2, s1, s2, dp);
        int insert = 1 + min_operations(idx1, idx2 - 1, s1, s2, dp);

        return dp[idx1][idx2] = min({rep, del, insert, match});
    }
    int min_op_bottomup(string &s1, string &s2)
    {
        int n1 = s1.size();
        int n2 = s2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        for (int idx1 = 0; idx1 <= n1; idx1++)
            dp[idx1][0] = idx1;
        for (int idx2 = 0; idx2 <= n2; idx2++)
            dp[0][idx2] = idx2;
        for (int idx1 = 1; idx1 <= n1; idx1++)
        {
            for (int idx2 = 1; idx2 <= n2; idx2++)
            {
                int match = INT_MAX;
                if (s1[idx1 - 1] == s2[idx2 - 1])
                    match = dp[idx1 - 1][idx2 - 1];
                int replace = 1 + dp[idx1 - 1][idx2 - 1];
                int del = 1 + dp[idx1 - 1][idx2];
                int insert = 1 + dp[idx1][idx2 - 1];
                dp[idx1][idx2] = min({match, replace, del, insert});
            }
        }
        return dp[n1][n2];
    }
    int min_op_sopt(string &s1, string &s2)
    {
        int n1 = s1.size();
        int n2 = s2.size();
        vector<int> prev(n2 + 1, 0), cur(n2 + 1, 0);

        for (int idx2 = 0; idx2 <= n2; idx2++)
            prev[idx2] = idx2;
        for (int idx1 = 1; idx1 <= n1; idx1++)
        {
            cur[0] = idx1;
            for (int idx2 = 1; idx2 <= n2; idx2++)
            {
                int match = INT_MAX;
                if (s1[idx1 - 1] == s2[idx2 - 1])
                    match = prev[idx2 - 1];
                int replace = 1 + prev[idx2 - 1];
                int del = 1 + prev[idx2];
                int insert = 1 + cur[idx2 - 1];
                cur[idx2] = min({match, replace, del, insert});
            }
            prev = cur;
        }
        return prev[n2];
    }

public:
    int minDistance(string word1, string word2)
    {
        // int n1 = word1.size();
        // int n2 = word2.size();
        // vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
        // return min_operations(n1, n2, word1, word2, dp);
        // return min_op_bottomup(word1, word2);
        return min_op_sopt(word1, word2);
    }
};
// @lc code=end
