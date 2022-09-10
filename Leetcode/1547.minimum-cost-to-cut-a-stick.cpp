/*
 * @lc app=leetcode id=1547 lang=cpp
 *
 * [1547] Minimum Cost to Cut a Stick
 */

// @lc code=start
class Solution {
    int min_cost(int i, int j, int n, vector<int> &cuts, vector<vector<int>> &dp) {
        if (i > j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int mini = INT_MAX;

        for (int k = i; k <= j; k++) {
            int cost = cuts[j + 1] - cuts[i - 1] + min_cost(i, k - 1, n, cuts, dp) + min_cost(k + 1, j, n, cuts, dp);
            mini = min(mini, cost);
        }
        return dp[i][j] = mini;
    }
    int min_cost_bottomup(vector<int> &cuts, int n) {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.push_back(0);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));

        for (int i = c; i >= 1; i--) {
            for (int j = 1; j <= c; j++) {
                if (i > j) continue;
                int mini = INT_MAX;
                for (int k = i; k <= j; k++) {
                    int cost = cuts[j + 1] - cuts[i - 1] + dp[i][k - 1] + dp[k + 1][j];
                    mini = min(cost, mini);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][c];
    }

   public:
    int minCost(int n, vector<int> &cuts) {
        // int c = cuts.size();
        // cuts.push_back(n);
        // cuts.push_back(0);
        // sort(cuts.begin(), cuts.end());

        // vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));
        // return min_cost(1, c, n, cuts, dp);
        return min_cost_bottomup(cuts, n);
    }
};
// @lc code=end
