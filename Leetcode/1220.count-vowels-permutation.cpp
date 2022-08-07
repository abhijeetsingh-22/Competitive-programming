/*
 * @lc app=leetcode id=1220 lang=cpp
 *
 * [1220] Count Vowels Permutation
 */

// @lc code=start
#define mod 1000000007
class Solution
{
    unordered_map<char, int> map;

private:
    int count_vovel_per(int n, vector<vector<long>> &dp, char prev = ' ')
    {
        if (n == 0)
            return 1;
        // a, e, i, o, u
        long ans = 0;
        string vowel = "aeiou";

        if (dp[n][map[prev]] != -1)
            return dp[n][map[prev]];
        for (char &c : vowel)
        {
            if (c == 'a' and (prev == ' ' or prev == 'e' or prev == 'u' or prev == 'i'))
                ans = (ans + count_vovel_per(n - 1, dp, 'a') % mod) % mod;

            if (c == 'e' and (prev == ' ' or prev == 'a' or prev == 'i'))
                ans = (ans + count_vovel_per(n - 1, dp, 'e') % mod) % mod;

            if (c == 'i' and (prev == ' ' or prev == 'e' or prev == 'o'))
                ans = (ans + count_vovel_per(n - 1, dp, 'i') % mod) % mod;

            if (c == 'o' and (prev == ' ' or prev == 'i'))
                ans = (ans + count_vovel_per(n - 1, dp, 'o') % mod) % mod;

            if (c == 'u' and (prev == ' ' or prev == 'o' or prev == 'i'))
                ans = (ans + count_vovel_per(n - 1, dp, 'u') % mod) % mod;
        }

        return dp[n][map[prev]] = ans;
        // return ans;
    }

public:
    int countVowelPermutation(int n)
    {
        map['a'] = 0;
        map['e'] = 1;
        map['i'] = 2;
        map['o'] = 3;
        map['u'] = 4;

        vector<vector<long>> dp(n + 1, vector<long>(5, -1));

        return count_vovel_per(n, dp);
    }
};
// @lc code=end
