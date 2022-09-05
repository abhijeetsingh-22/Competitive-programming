/*
 * @lc app=leetcode id=1671 lang=cpp
 *
 * [1671] Minimum Number of Removals to Make Mountain Array
 */

 // @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
    int max_bitonic(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp1(n, 1), dp2(n, 1);

        for (int idx = 0;idx < n;idx++) {
            for (int prev_idx = 0;prev_idx < idx;prev_idx++) {
                if (nums[idx] > nums[prev_idx] and dp1[idx] < dp1[prev_idx] + 1) {
                    dp1[idx] = 1 + dp1[prev_idx];
                }
            }
        }
        for (int idx = n - 1;idx >= 0;idx--) {
            for (int prev_idx = n - 1;prev_idx > idx;prev_idx--) {
                if (nums[idx] > nums[prev_idx] and dp2[idx] < dp2[prev_idx] + 1) {
                    dp2[idx] = 1 + dp2[prev_idx];
                }
            }
        }
        int maxi = 0;

        for (int i = 0;i < n;i++) {
            if (dp1[i] >= 2 and dp2[i] >= 2) {
                maxi = max(maxi, dp1[i] + dp2[i] - 1);
            }
        }
        return maxi;
    }

public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        return n - max_bitonic(nums);
    }
};
// @lc code=end

