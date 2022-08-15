/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

// @lc code=start
class Solution
{
public:
    int romanToInt(string s)
    {
        unordered_map<char, int> map{
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
            {'S', INT_MIN}};

        int n = s.size() - 1;
        int ans = 0;
        char prev = 'S';
        for (; n >= 0; n--)
        {
            char cur = s[n];
            if (map[prev] > map[cur])
            {
                ans -= map[cur];
            }
            else
            {
                ans += map[cur];
            }
            prev = cur;
        }
        return ans;
    }
};
// @lc code=end
