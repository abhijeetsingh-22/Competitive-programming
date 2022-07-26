/*
 * @lc app=leetcode id=1512 lang=cpp
 *
 * [1512] Number of Good Pairs
 */

// @lc code=start
class Solution
{
private:
public:
    int numIdenticalPairs(vector<int> &nums)
    {
        int ans = 0;
        unordered_map<int, int> map;
        for (int &x : nums)
        {
            ans += map[x];
            map[x]++;
        }

        return ans;
    }
};
// @lc code=end
