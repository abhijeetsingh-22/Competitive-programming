/*
 * @lc app=leetcode id=2007 lang=cpp
 *
 * [2007] Find Original Array From Doubled Array
 */

// @lc code=start
class Solution {
   public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if (n & 1)
            return {};
        unordered_map<int, int> map;
        vector<int> ans;
        sort(changed.begin(), changed.end());
        // if num/2 is present then this is larger num else
        // consider it as smaller number
        for (int num : changed) {
            if (!(num & 1) and map[num / 2] > 0) {
                map[num / 2]--;
                ans.push_back(num / 2);
            }
            // else if (map[2 * num] > 0) {
            //     map[2 * num]--;
            //     ans.push_back(num);
            // }
            else
                map[num]++;
        }
        // for (pair<int, int> p : map) {
        //     if (p.second != 0)
        //         return {};
        // }
        if (ans.size() * 2 != n)
            return {};
        return ans;
    }
};
// @lc code=end
