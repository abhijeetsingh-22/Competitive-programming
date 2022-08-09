/*
 * @lc app=leetcode id=823 lang=cpp
 *
 * [823] Binary Trees With Factors
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    int mod = 1e9 + 7;
    long num_bt(int num, vector<int> &arr, unordered_set<int> &set, unordered_map<int, int> &dp)
    {
        if (dp[num] > 0)
            return dp[num];
        // search for foctors in 2-> n/2;
        long ans = 1;
        for (int &x : arr)
        {
            if (num % x == 0 and set.count(num / x) > 0)
            {
                ans += num_bt(x, arr, set, dp) * num_bt(num / x, arr, set, dp);
            }
        }
        return dp[num] = (ans) % mod;
    }
    int num_bt_bottomup(vector<int> &arr)
    {
        unordered_map<int, long> dp;
        int n = arr.size();
        // nlogn for sorting
        sort(arr.begin(), arr.end());
        for (int idx = 0; idx < n; idx++)
        {
            dp[arr[idx]] = 1;
            for (int j = 0; j < idx; j++)
            {
                if (arr[idx] % arr[j] == 0)
                    dp[arr[idx]] = (dp[arr[idx]] + dp[arr[j]] * dp[arr[idx] / arr[j]]) % mod;
            }
        }
        int ans = 0;
        for (auto &p : dp)
        {
            ans = (ans + p.second) % mod;
        }
        return ans;
    }

public:
    int numFactoredBinaryTrees(vector<int> &arr)
    {
        // sort(arr.begin(), arr.end());
        // int ans = 0;
        // int n = arr.size();
        // unordered_set<int> set(arr.begin(), arr.end());
        // unordered_map<int, int> dp;

        // for (int &x : arr)
        // {
        //     ans += num_bt(x, arr, set, dp);
        //     ans = ans % mod;
        // }
        // return ans;
        return num_bt_bottomup(arr);
    }
};
// @lc code=end
