/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
class Solution
{
    int min_coin(int idx, int target, vector<int> &coins, vector<vector<int>> &dp)
    {
        if (idx == 0)
        {
            if (target % coins[0] == 0)
                return target / coins[0];
            return INT_MAX;
        }
        if (dp[idx][target] != -1)
            return dp[idx][target];
        int not_take = min_coin(idx - 1, target, coins, dp);
        int take = INT_MAX;
        if (target >= coins[idx])
            take = min_coin(idx, target - coins[idx], coins, dp);
        if (take != INT_MAX)
            take += 1;
        return dp[idx][target] = min(take, not_take);
    }

    int min_coin_bottomup(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        // base case;
        for (int target = 0; target <= amount; target++)
            if (target % coins[0] == 0)
                dp[0][target] = target / coins[0];
            else
                dp[0][target] = INT_MAX;

        for (int idx = 1; idx < n; idx++)
        {

            for (int target = 0; target <= amount; target++)
            {
                int not_take = dp[idx - 1][target];
                int take = INT_MAX;
                if (target >= coins[idx])
                    take = dp[idx][target - coins[idx]];
                if (take != INT_MAX)
                    take += 1;
                dp[idx][target] = min(take, not_take);
            }
        }
        return dp[n - 1][amount];
    }
    int min_coin_sopt(vector<int> &coins, int amount)
    {

        int n = coins.size();

        vector<int> prev(amount + 1, 0), cur(amount + 1, 0);
        for (int target = 0; target <= amount; target++)
        {
            if (target % coins[0] == 0)
                prev[target] = target / coins[0];
            else
                prev[target] = INT_MAX;
        }
        for (int idx = 1; idx < n; idx++)
        {
            for (int target = 0; target <= amount; target++)
            {
                int not_take = prev[target];
                int take = INT_MAX;
                if (target >= coins[idx])
                    take = cur[target - coins[idx]];
                if (take != INT_MAX)
                    take += 1;
                cur[target] = min(take, not_take);
            }
            prev = cur;
        }

        return prev[amount];
    }

public:
    int coinChange(vector<int> &coins, int amount)
    {
        // int n = coins.size();
        // vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        // int ans = min_coin(n - 1, amount, coins, dp);
        // int ans = min_coin_bottomup(coins, amount);
        int ans = min_coin_sopt(coins, amount);
        return ans != INT_MAX ? ans : -1;
    }
};
// @lc code=end
