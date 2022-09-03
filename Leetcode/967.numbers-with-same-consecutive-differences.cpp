/*
 * @lc app=leetcode id=967 lang=cpp
 *
 * [967] Numbers With Same Consecutive Differences
 */

 // @lc code=start
class Solution {
    void build_number(int num, int n, int k, vector<int>& ans) {
        if (n == 0) {
            ans.push_back(num);
            return;
        }
        int last_digit = num % 10;
        if (last_digit - k >= 0) {
            int new_num = num * 10 + (last_digit - k);
            build_number(new_num, n - 1, k, ans);
        }
        if (k > 0 and last_digit + k < 10) {
            int new_number = num * 10 + (last_digit + k);
            build_number(new_number, n - 1, k, ans);
        }
    }
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        for (int i = 1;i <= 9;i++)
            build_number(i, n - 1, k, ans);
        return ans;
    }
};
// @lc code=end

