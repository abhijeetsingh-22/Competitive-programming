/*
 * @lc app=leetcode id=1092 lang=cpp
 *
 * [1092] Shortest Common Supersequence
 */

// @lc code=start
class Solution
{
    string min_supersequence(string &str1, string &str2)
    {
        int n1 = str1.size();
        int n2 = str2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        for (int idx1 = 1; idx1 <= n1; idx1++)
        {
            for (int idx2 = 1; idx2 <= n2; idx2++)
            {
                if (str1[idx1 - 1] == str2[idx2 - 1])
                    dp[idx1][idx2] = 1 + dp[idx1 - 1][idx2 - 1];
                else
                {
                    dp[idx1][idx2] = max(dp[idx1 - 1][idx2], dp[idx1][idx2 - 1]);
                }
            }
        }
        int lcs_len = dp[n1][n2];
        string ans;
        // ans.reserve(n1 + n2 - lcs_len);
        int idx1 = n1, idx2 = n2, i = n1 + n2 - lcs_len;
        while (idx1 >= 1 and idx2 >= 1)
        {
            if (str1[idx1 - 1] == str2[idx2 - 1])
            {
                // ans[i] = str1[idx1];
                ans.push_back(str1[idx1 - 1]);
                idx1--;
                idx2--;
            }
            else
            {
                if (dp[idx1 - 1][idx2] >= dp[idx1][idx2 - 1])
                {
                    // ans[i] = str1[idx1];
                    ans.push_back(str1[idx1 - 1]);
                    idx1--;
                }
                else
                {
                    // ans[i] = str2[idx2];
                    ans.push_back(str2[idx2 - 1]);
                    idx2--;
                }
            }
        }
        while (idx1 >= 1)
        {
            ans.push_back(str1[idx1 - 1]);
            idx1--;
        }
        while (idx2 >= 1)
        {
            ans.push_back(str2[idx2 - 1]);
            idx2--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

public:
    string shortestCommonSupersequence(string str1, string str2)
    {
        return min_supersequence(str1, str2);
    }
};
// @lc code=end
