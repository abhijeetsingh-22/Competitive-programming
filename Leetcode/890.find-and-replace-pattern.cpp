/*
 * @lc app=leetcode id=890 lang=cpp
 *
 * [890] Find and Replace Pattern
 */

// @lc code=start
class Solution
{
private:
    static string normalize(string &s)
    {
        vector<int> val(26, 0);

        int cur_val, max_val = 0;
        int n = s.size();
        string ans;
        for (int idx = 0; idx < n; idx++)
        {
            cur_val = val[s[idx] - 'a'];
            if (cur_val == 0)
            {
                max_val++;
                cur_val = max_val;
                val[s[idx] - 'a'] = cur_val;
            }
            ans.push_back(cur_val);
        }
        // for (int x : val)
        //     cout << x << " ";
        return ans;
    }

public:
    vector<string> findAndReplacePattern(vector<string> &words, string pattern)
    {
        vector<string> ans;
        string pattern_normal = normalize(pattern);

        for (string s : words)
        {
            if (normalize(s) == pattern_normal)
                ans.push_back(s);
        }
        return ans;
    }
};
// @lc code=end
