/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

// @lc code=start
class Solution
{
    static int ways_to_reach(int row, int col, vector<vector<int>> &grid)
    {
        if (row < 0 or col < 0)
            return 0;
        if (grid[row][col] == 1)
            return 0;
        if (row == 0 and col == 0)
            return 1;

        // recursive case;
        int up = ways_to_reach(row - 1, col, grid);
        int left = ways_to_reach(row, col - 1, grid);
        return up + left;
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        return ways_to_reach(m - 1, n - 1, obstacleGrid);
    }
};
// @lc code=end
