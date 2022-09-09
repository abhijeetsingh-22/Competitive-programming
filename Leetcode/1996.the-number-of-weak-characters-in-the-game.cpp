/*
 * @lc app=leetcode id=1996 lang=cpp
 *
 * [1996] The Number of Weak Characters in the Game
 */

// @lc code=start
class Solution
{
    static bool comp(vector<int> &a, vector<int> &b)
    {
        if (a[0] == b[0])
        {
            return a[1] < b[1];
        }
        return a[0] > b[0];
    }
    int num_week_chars(vector<vector<int>> &properties)
    {
        sort(properties.begin(), properties.end(), comp);
        int n = properties.size();

        int count = 0;
        int max_y = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            int cur_y = properties[i][1];

            if (cur_y < max_y)
                count++;
            max_y = max(cur_y, max_y);
        }

        return count;
    }

public:
    int numberOfWeakCharacters(vector<vector<int>> &properties)
    {
        return num_week_chars(properties);
    }
};
// @lc code=end
