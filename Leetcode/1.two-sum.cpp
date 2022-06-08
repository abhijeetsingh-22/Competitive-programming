/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution
{
public:
    static bool compare(pair<int, int> a, pair<int, int> b)
    {
        return a.second < b.second;
    }

    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<pair<int, int>> v;
        int size = nums.size();
        for (int i = 0; i < size; i++)
        {
            v.push_back(make_pair(i, nums[i]));
        }

        sort(v.begin(), v.end(), (compare));
        int i = 0;
        int j = size - 1;
        while (i < j)
        {
            int csum = v[i].second + v[j].second;
            if (csum == target)
            {
                return {v[i].first, v[j].first};
            }
            else if (csum > target)
            {
                j--;
            }
            else
                i++;
        }
        return {};
    }
};
// @lc code=end
