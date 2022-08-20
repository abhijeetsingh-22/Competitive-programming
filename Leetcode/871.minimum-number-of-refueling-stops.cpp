/*
 * @lc app=leetcode id=871 lang=cpp
 *
 * [871] Minimum Number of Refueling Stops
 */

// @lc code=start
class Solution
{
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations)
    {
        priority_queue<int> pq;
        if (startFuel >= target)
            return 0;
        int fuel = startFuel;
        int prev_position = 0;
        int n = stations.size();
        int pos = 0;
        int ans = 0;
        while (pos < n)
        {
            if (fuel >= stations[pos][0] - prev_position)
            {
                fuel = fuel - (stations[pos][0] - prev_position);
                prev_position = stations[pos][0];
                pq.push(stations[pos][1]);
                pos++;
            }
            else
            {
                if (pq.empty())
                    return -1;
                fuel += pq.top();
                pq.pop();
                ans++;
            }
        }
        while (fuel < target - prev_position)
        {
            if (pq.empty())
                return -1;
            fuel += pq.top();
            ans++;
            pq.pop();
        }
        return ans;
    }
};
// @lc code=end
