/*
 * @lc app=leetcode id=1383 lang=cpp
 *
 * [1383] Maximum Performance of a Team
 */

// @lc code=start
int mod = 1e9 + 7;
class Solution {
   public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++) {
            arr.push_back({efficiency[i], speed[i]});
        }
        sort(arr.begin(), arr.end(), greater<pair<int, int>>());
        long maxi = 0;
        long cur_sum = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++) {
            cur_sum = (cur_sum + arr[i].second) % mod;
            pq.push(arr[i].second);
            if (pq.size() > k) {
                cur_sum = (cur_sum - pq.top());
                pq.pop();
            }
            long perf = (arr[i].first * cur_sum);
            maxi = max(maxi, perf);
        }
        return maxi % mod;
    }
};
// @lc code=end
