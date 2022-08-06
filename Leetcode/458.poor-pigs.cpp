/*
 * @lc app=leetcode id=458 lang=cpp
 *
 * [458] Poor Pigs
 */

// @lc code=start
class Solution
{

public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest)
    {
        int rounds = (minutesToTest / minutesToDie);
        int options = rounds + 1;
        return ceil(log(buckets) / log(options));
    }
};
// @lc code=end
