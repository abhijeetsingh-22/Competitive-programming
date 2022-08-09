/*
 * @lc app=leetcode id=1463 lang=cpp
 *
 * [1463] Cherry Pickup II
 */

// @lc code=start
class Solution
{
    int max_cherry(int row, int col1, int col2, int r, int c, vector<vector<int>> &grid,
                   vector<vector<vector<int>>> &dp)
    {
        if (col1 < 0 or col2 < 0 or col1 >= c or col2 >= c)
            return INT_MIN;
        if (row == r - 1)
        {
            if (col1 == col2)
                return grid[row][col1];
            else
                return grid[row][col1] + grid[row][col2];
        }
        if (dp[row][col1][col2] != -1)
            return dp[row][col1][col2];
        int ans = INT_MIN;
        for (int dc1 = -1; dc1 <= 1; dc1++)
            for (int dc2 = -1; dc2 <= 1; dc2++)
            {
                ans = max(ans, max_cherry(row + 1, col1 + dc1, col2 + dc2, r, c, grid, dp));
            }
        if (col1 == col2)
            ans += grid[row][col1];
        else
            ans += grid[row][col1] + grid[row][col2];
        return dp[row][col1][col2] = ans;
    }

    int max_cherry_bottomup(vector<vector<int>> &grid)
    {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, 0)));

        for (int col1 = 0; col1 < c; col1++)
            for (int col2 = 0; col2 < c; col2++)
            {
                if (col1 == col2)
                    dp[r - 1][col1][col2] = grid[r - 1][col1];
                else
                    dp[r - 1][col1][col2] = grid[r - 1][col1] + grid[r - 1][col2];
            }

        for (int row = r - 2; row >= 0; row--)
        {
            for (int col1 = c - 1; col1 >= 0; col1--)
            {
                for (int col2 = c - 1; col2 >= 0; col2--)
                {
                    int value = 0;

                    for (int dc1 = -1; dc1 <= 1; dc1++)
                        for (int dc2 = -1; dc2 <= 1; dc2++)
                        {
                            if (col1 + dc1 < 0 or col1 + dc1 >= c or col2 + dc2 < 0 or col2 + dc2 >= c)
                                continue;
                            value = max(value, dp[row + 1][col1 + dc1][col2 + dc2]);
                        }

                    if (col1 == col2)
                        value += grid[row][col1];
                    else
                        value += grid[row][col1] + grid[row][col2];

                    dp[row][col1][col2] = value;
                }
            }
        }
        return dp[0][0][c - 1];
    }
    int max_cherry_sopt(vector<vector<int>> &grid)
    {

        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>> front(c, vector<int>(c, 0));

        for (int col1 = 0; col1 < c; col1++)
            for (int col2 = 0; col2 < c; col2++)
            {
                if (col1 == col2)
                    front[col1][col2] = grid[r - 1][col1];
                else
                    front[col1][col2] = grid[r - 1][col1] + grid[r - 1][col2];
            }
        for (int row = r - 2; row >= 0; row--)
        {
            vector<vector<int>> cur(c, vector<int>(c, 0));

            for (int col1 = c - 1; col1 >= 0; col1--)
                for (int col2 = c - 1; col2 >= 0; col2--)
                {
                    int value = 0;
                    for (int dc1 = -1; dc1 <= 1; dc1++)
                        for (int dc2 = -1; dc2 <= 1; dc2++)
                        {
                            if (col1 + dc1 < 0 or col1 + dc1 >= c or col2 + dc2 < 0 or col2 + dc2 >= c)
                                continue;
                            value = max(value, front[col1 + dc1][col2 + dc2]);
                        }
                    if (col1 == col2)
                        value += grid[row][col1];
                    else
                        value += grid[row][col1] + grid[row][col2];
                    cur[col1][col2] = value;
                }

            front = cur;
        }
        return front[0][c - 1];
    }

public:
    int cherryPickup(vector<vector<int>> &grid)
    {

        // int r = grid.size(), c = grid[0].size();
        // vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));

        // return max_cherry(0, 0, c - 1, r, c, grid, dp);
        // return max_cherry_bottomup(grid);
        return max_cherry_sopt(grid);
    }
};
// @lc code=end
