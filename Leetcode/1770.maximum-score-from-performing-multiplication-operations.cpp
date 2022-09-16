class Solution {
    int max_score(int idx, int start, int end, int m, vector<int>& nums, vector<int>& muls, vector<vector<int>>& dp) {
        if (idx == m) {
            return 0;
        }
        if (dp[idx][start] != INT_MIN)
            return dp[idx][start];
        int take_first = nums[start] * muls[idx] + max_score(idx + 1, start + 1, end, m, nums, muls, dp);
        int take_last = nums[end] * muls[idx] + max_score(idx + 1, start, end - 1, m, nums, muls, dp);
        return dp[idx][start] = max(take_first, take_last);
    }
    int max_score_bottomup(vector<int>& nums, vector<int>& muls) {
        int n = nums.size();
        int m = muls.size();
        vector<vector<int>> dp(m + 1, vector<int>(m + 1, 0));

        for (int idx = m - 1; idx >= 0; idx--) {
            for (int start = idx; start >= 0; start--) {
                // for(int end=0;end<n;end++){
                // if(start>end)
                //     continue;
                int end = n - (idx - start) - 1;
                if (end < 0 or end >= n) break;
                int take_first = nums[start] * muls[idx] + dp[idx + 1][start + 1];
                int take_last = nums[end] * muls[idx] + dp[idx + 1][start];
                dp[idx][start] = max(take_first, take_last);
            }
        }
        // }
        return dp[0][0];
    }

   public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        // int m=multipliers.size();
        // int n=nums.size();
        // vector<vector<int>> dp(m,vector<int>(m,INT_MIN));
        // return max_score(0,0,n-1,m,nums,multipliers,dp);
        return max_score_bottomup(nums, multipliers);
    }
};