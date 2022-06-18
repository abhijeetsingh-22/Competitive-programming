/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {

        int n = nums.size();
        int subsets = (1 << n);
        vector<int> temp(n);
        vector<vector<int>> ans;
        // ans.reserve(subsets);
        for (int i = 0; i < subsets; i++)
        {

            temp.clear();
            for (int j = 0; j < n; j++)
            {
                if (i & (1 << j))
                {
                    temp.push_back(nums[j]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
// @lc code=end
