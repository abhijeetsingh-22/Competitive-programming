/*
 * @lc app=leetcode id=1337 lang=cpp
 *
 * [1337] The K Weakest Rows in a Matrix
 */

// @lc code=start
class Solution
{
public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> ans;
        ans.reserve(k);
        int n = mat.size();
        for (int idx = 0; idx < n; idx++)
        {
            int power = 0;
            for (auto &e : mat[idx])
            {
                if (e == 1)
                    power++;
            }
            pq.push({power, idx});
        }
        for (int i = 0; i < k; i++)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
// @lc code=end
