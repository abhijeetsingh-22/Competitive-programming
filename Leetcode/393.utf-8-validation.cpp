/*
 * @lc app=leetcode id=393 lang=cpp
 *
 * [393] UTF-8 Validation
 */

// @lc code=start
class Solution {
   public:
    bool validUtf8(vector<int>& data) {
        int rem_len = 0;
        for (int num : data) {
            if (rem_len == 0) {
                for (int i = 7; i >= 0; i--) {
                    if ((num & (1 << i)))
                        rem_len++;
                    else
                        break;
                }
                if (rem_len == 1 or rem_len > 4) return false;
                if (rem_len > 1) rem_len--;
            } else {
                if ((num & (1 << 7)) and !(num & (1 << 6))) {
                    rem_len--;
                } else
                    return false;
            }
        }
        return rem_len == 0;
    }
};
// @lc code=end
