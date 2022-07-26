/*
 * @lc app=leetcode id=771 lang=cpp
 *
 * [771] Jewels and Stones
 */

// @lc code=start
class Solution
{
public:
    int numJewelsInStones(string jewels, string stones)
    {
        unordered_map<char, int> map;
        map.reserve(jewels.size());

        for (char &c : jewels)
        {
            map[c]++;
        }
        int no_of_jewels = 0;
        for (auto &s : stones)
        {
            if (map.count(s) > 0)
                no_of_jewels++;
        }
        return no_of_jewels;
    }
};
// @lc code=end
