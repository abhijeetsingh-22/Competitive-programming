/*
 * @lc app=leetcode id=1220 lang=cpp
 *
 * [1220] Count Vowels Permutation
 */

// @lc code=start
#define mod 1000000007
class Solution
{
    // unordered_map<char, int> map;
    vector<vector<int>> mappings{{1}, {0, 2}, {0, 1, 3, 4}, {2, 4}, {0}, {0, 1, 2, 3, 4}};

private:
    int count_vovel_per(int n, vector<vector<long>> &dp, int prev = 5)
    {
        if (n == 0)
            return 1;
        // a, e, i, o, u
        long ans = 0;
        string vowel = "aeiou";

        if (dp[n][prev] != -1)
            return dp[n][prev];

        for (int p : mappings[prev])
        {
            ans = (ans + count_vovel_per(n - 1, dp, p) % mod) % mod;
        }
        // for (char &c : vowel)
        // {
        //     if (c == 'a' and (prev == ' ' or prev == 'e' or prev == 'u' or prev == 'i'))
        //         ans = (ans + count_vovel_per(n - 1, dp, 'a') % mod) % mod;

        //     if (c == 'e' and (prev == ' ' or prev == 'a' or prev == 'i'))
        //         ans = (ans + count_vovel_per(n - 1, dp, 'e') % mod) % mod;

        //     if (c == 'i' and (prev == ' ' or prev == 'e' or prev == 'o'))
        //         ans = (ans + count_vovel_per(n - 1, dp, 'i') % mod) % mod;

        //     if (c == 'o' and (prev == ' ' or prev == 'i'))
        //         ans = (ans + count_vovel_per(n - 1, dp, 'o') % mod) % mod;

        //     if (c == 'u' and (prev == ' ' or prev == 'o' or prev == 'i'))
        //         ans = (ans + count_vovel_per(n - 1, dp, 'u') % mod) % mod;
        // }

        return dp[n][prev] = ans;
        // return ans;
    }
    int count_vowel_bottomup(int n)
    {
        // vector<vector<long>> dp(n + 1, vector<long>(6, -1));
        // length, ending char
        long dp[n + 1][5];
        dp[1][0] = dp[1][1] = dp[1][2] = dp[1][3] = dp[1][4] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i][0] = (dp[i - 1][1] + dp[i - 1][4] + dp[i - 1][2]) % mod;
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % mod;
            dp[i][2] = (dp[i - 1][1] + dp[i - 1][3]) % mod;
            dp[i][3] = (dp[i - 1][2]) % mod;
            dp[i][4] = (dp[i - 1][3] + dp[i - 1][2]) % mod;
        }
        long ans = 0;
        for (int i = 0; i < 5; i++)
        {
            ans = (ans + dp[n][i]) % mod;
        }
        return ans;
    }
    int count_vowel_sopt(int n)
    {
        long prev_a, prev_e, prev_i, prev_o, prev_u;
        prev_a = prev_e = prev_i = prev_o = prev_u = 1;
        for (int i = 2; i <= n; i++)
        {
            int cur_a = (prev_e + prev_i + prev_u) % mod;
            int cur_e = (prev_a + prev_i) % mod;
            int cur_i = (prev_e + prev_o) % mod;
            int cur_o = prev_i;
            int cur_u = (prev_o + prev_i) % mod;

            prev_a = cur_a;
            prev_e = cur_e;
            prev_i = cur_i;
            prev_o = cur_o;
            prev_u = cur_u;
        }
        return (prev_a + prev_e + prev_i + prev_o + prev_u) % mod;
    }

public:
    int countVowelPermutation(int n)
    {

        // vector<vector<long>> dp(n + 1, vector<long>(6, -1));

        // return count_vovel_per(n, dp);
        // return count_vowel_bottomup(n);
        return count_vowel_sopt(n);
    }
};
// @lc code=end
