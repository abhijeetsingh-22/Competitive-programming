/*
 * @lc app=leetcode id=659 lang=cpp
 *
 * [659] Split Array into Consecutive Subsequences
 */

// @lc code=start
class Solution
{
public:
    bool isPossible(vector<int> &nums)
    {
        unordered_map<int, int> left, seq;
        for (int &x : nums)
        {
            left[x]++;
        }
        for (auto &x : nums)
        {
            if (left[x] == 0)
                continue;
            left[x]--;
            if (seq[x - 1] > 0)
            {
                seq[x - 1]--;
                seq[x]++;
            }
            else if (left[x + 1] > 0 and left[x + 2] > 0)
            {
                left[x + 1]--;
                left[x + 2]--;
                seq[x + 2]++;
            }
            else
                return false;
        }
        return true;
    }
};
// @lc code=end
