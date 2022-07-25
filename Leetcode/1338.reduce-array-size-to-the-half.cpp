/*
 * @lc app=leetcode id=1338 lang=cpp
 *
 * [1338] Reduce Array Size to The Half
 */

// @lc code=start
class Solution
{
private:
    // TC -> O(nlogn);
    static int min_set_heap(vector<int> &arr)
    {
        vector<int> count(100005, 0);
        for (int &x : arr)
        {
            count[x]++;
        }
        priority_queue<int> pq;
        for (int &c : count)
        {
            pq.push(c);
        }
        int target = arr.size() / 2;
        int cur_elements = arr.size();
        int ans = 0;
        while (cur_elements > target)
        {
            auto top = pq.top();
            pq.pop();
            cur_elements -= top;
            ans++;
        }
        return ans;
    }
    static int min_set_map(vector<int> &arr)
    {
    }

public:
    int minSetSize(vector<int> &arr)
    {
        return min_set_heap(arr);
    }
};
// @lc code=end
