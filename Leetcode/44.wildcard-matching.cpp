/*
 * @lc app=leetcode id=44 lang=cpp
 *
 * [44] Wildcard Matching
 */

// @lc code=start
class Solution
{
    bool is_match(int idx1, int idx2, string &s, string &p, vector<vector<int>> &dp)
    {
        if (idx1 < 0)
        {

            while (idx2 >= 0 and p[idx2] == '*')
                idx2--;
            if (idx2 < 0)
                return true;
            return false;
        }
        if (idx2 < 0)
            return false;
        if (dp[idx1][idx2] != -1)
            return dp[idx1][idx2];
        if (s[idx1] == p[idx2] or p[idx2] == '?' or p[idx2] == '*')
        {
            bool ans = false;
            ans = is_match(idx1 - 1, idx2 - 1, s, p, dp);
            if (p[idx2] == '*')
                ans = ans or is_match(idx1 - 1, idx2, s, p, dp) or is_match(idx1, idx2 - 1, s, p, dp);
            return dp[idx1][idx2] = ans;
        }
        return dp[idx1][idx2] = false;
    }
    bool is_match_bottomup(string &s, string &p)
    {
        int n1 = s.size();
        int n2 = p.size();
        vector<vector<bool>> dp(n1 + 1, vector<bool>(n2 + 1, false));

        dp[0][0] = true;
        for (int idx2 = 1; idx2 <= n2; idx2++)
        {
            bool flag = true;
            for (int i = 1; i <= idx2; i++)
                if (p[i - 1] != '*')
                {
                    flag = false;
                    break;
                }
            dp[0][idx2] = flag;
        }
        for (int idx1 = 1; idx1 <= n1; idx1++)
        {
            for (int idx2 = 1; idx2 <= n2; idx2++)
            {
                if (s[idx1 - 1] == p[idx2 - 1] or p[idx2 - 1] == '?')
                {
                    dp[idx1][idx2] = dp[idx1 - 1][idx2 - 1];
                }
                else if (p[idx2 - 1] == '*')
                {
                    dp[idx1][idx2] = dp[idx1 - 1][idx2] or dp[idx1][idx2 - 1];
                }
            }
        }
        return dp[n1][n2];
    }
    bool is_match_sopt(string &s, string &p)
    {
        int n1 = s.size();
        int n2 = p.size();
        vector<bool> prev(n2 + 1, false), cur(n2 + 1, false);
        prev[0] = true;
        for (int idx2 = 1; idx2 <= n2; idx2++)
        {
            bool flag = true;
            for (int i = 1; i <= idx2; i++)
                if (p[i - 1] != '*')
                {
                    flag = false;
                    break;
                }
            prev[idx2] = flag;
        }
        for (int idx1 = 1; idx1 <= n1; idx1++)
        {
            for (int idx2 = 1; idx2 <= n2; idx2++)
            {
                if (s[idx1 - 1] == p[idx2 - 1] or p[idx2 - 1] == '?')
                {
                    cur[idx2] = prev[idx2 - 1];
                }
                else if (p[idx2 - 1] == '*')
                {
                    cur[idx2] = prev[idx2] or cur[idx2 - 1];
                }
                else
                    cur[idx2] = false;
            }
            prev = cur;
        }
        return prev[n2];
    }

public:
    bool isMatch(string s, string p)
    {
        // int n1 = s.size();
        // int n2 = p.size();
        // vector<vector<int>> dp(n1, vector<int>(n2, -1));
        // return is_match(n1 - 1, n2 - 1, s, p, dp);
        // return is_match_bottomup(s, p);
        return is_match_sopt(s, p);
    }
};
// @lc code=end
