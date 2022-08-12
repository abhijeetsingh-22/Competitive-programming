/*
 * @lc app=leetcode id=518 lang=cpp
 *
 * [518] Coin Change 2
 */

// @lc code=start
class Solution
{
    int count_ways(int idx, int target, vector<int> &coins, vector<vector<int>> &dp)
    {
        if (idx == 0)
        {
            if (target == 0 or target % coins[0] == 0)
                return 1;
            return 0;
        }
        if (dp[idx][target] != -1)
            return dp[idx][target];
        int not_take = count_ways(idx - 1, target, coins, dp);
        int take = 0;
        if (target >= coins[idx])
            take = count_ways(idx, target - coins[idx], coins, dp);

        return dp[idx][target] = take + not_take;
    }
    int count_ways_bottomup(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        for (int target = 0; target <= amount; target++)
        {
            if (target == 0 or target % coins[0] == 0)
                dp[0][target] = 1;
        }
        for (int idx = 1; idx < n; idx++)
        {
            for (int target = 0; target <= amount; target++)
            {
                int not_take = dp[idx - 1][target];
                int take = 0;
                if (target >= coins[idx])
                    take = dp[idx][target - coins[idx]];

                dp[idx][target] = take + not_take;
            }
        }
        return dp[n - 1][amount];
    }
    int count_ways_sopt(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<int> prev(amount + 1, 0), cur(amount + 1, 0);

        for (int target = 0; target <= amount; target++)
        {
            if (target == 0 or target % coins[0] == 0)
                prev[target] = 1;
        }
        for (int idx = 1; idx < n; idx++)
        {
            for (int target = 0; target <= amount; target++)
            {
                int not_take = prev[target];
                int take = 0;
                if (target >= coins[idx])
                    take = cur[target - coins[idx]];
                cur[target] = take + not_take;
            }
            prev = cur;
        }
        return prev[amount];
    }
    int count_ways_sopt1(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<int> row(amount + 1, 0);

        for (int target = 0; target <= amount; target++)
        {
            if (target == 0 or target % coins[0] == 0)
                row[target] = 1;
        }
        for (int idx = 1; idx < n; idx++)
        {
            for (int target = 0; target <= amount; target++)
            {
                int not_take = row[target];
                int take = 0;
                if (target >= coins[idx])
                    take = row[target - coins[idx]];
                row[target] = take + not_take;
            }
            // prev = cur;
        }
        return row[amount];
    }

public:
    int change(int amount, vector<int> &coins)
    {
        // int n = coins.size();
        // vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        // return count_ways(n - 1, amount, coins, dp);
        // return count_ways_bottomup(coins, amount);
        return count_ways_sopt(coins, amount);
    }
};
// @lc code=end
