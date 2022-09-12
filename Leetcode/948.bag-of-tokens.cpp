/*
 * @lc app=leetcode id=948 lang=cpp
 *
 * [948] Bag of Tokens
 */

// @lc code=start
class Solution {
    int max_score(vector<int>& tokens, int power) {
        int n = tokens.size();
        int i = 0, j = n - 1;
        int maxi = 0;
        int score = 0;
        sort(tokens.begin(), tokens.end());
        while (i <= j) {
            if (power >= tokens[i]) {
                power -= tokens[i];
                score++;
                i++;
            } else if (score >= 1) {
                power += tokens[j];
                score--;
                j--;
            } else
                break;
            maxi = max(maxi, score);
        }
        return maxi;
    }

   public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        // int n = tokens.size();
        return max_score(tokens, power);
    }
};
// @lc code=end
