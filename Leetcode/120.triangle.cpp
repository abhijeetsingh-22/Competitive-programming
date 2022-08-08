/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */

// @lc code=start
class Solution
{
    static int min_path(int row, int col, vector<vector<int>> &triangle, vector<vector<int>> &dp)
    {
        if (row == triangle.size() - 1)
            return triangle[row][col];
        if (dp[row][col] != -1)
            return dp[row][col];
        int down = min_path(row + 1, col, triangle, dp);
        int right = min_path(row + 1, col + 1, triangle, dp);

        return dp[row][col] = min(down, right) + triangle[row][col];
    }
    static int min_path_bottomup(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));
        for (int row = n - 1; row >= 0; row--)
        {
            for (int col = row; col >= 0; col--)
            {

                if (row == n - 1)
                {
                    dp[row][col] = triangle[row][col];
                }
                else
                {

                    int down = dp[row + 1][col];
                    int right = dp[row + 1][col + 1];
                    dp[row][col] = min(down, right) + triangle[row][col];
                }
            }
        }
        return dp[0][0];
    }
    static int min_path_sopt(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<int> prev(n, -1);
        for (int row = n - 1; row >= 0; row--)
        {
            vector<int> cur(n, 0);
            for (int col = 0; col <= row; col++)
            {
                if (row == n - 1)
                    cur[col] = triangle[row][col];
                else
                {
                    int down = prev[col];
                    int right = prev[col + 1];
                    cur[col] = min(down, right) + triangle[row][col];
                }
            }
            prev = cur;
        }
        return prev[0];
    }

public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        // int n = triangle.size();
        // vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        // return min_path(0, 0, triangle, dp);
        // return min_path_bottomup(triangle);
        return min_path_sopt(triangle);
    }
};
// @lc code=end
