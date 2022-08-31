/*
 * @lc app=leetcode id=417 lang=cpp
 *
 * [417] Pacific Atlantic Water Flow
 */

// @lc code=start
class Solution
{
    void visit_dfs(int row, int col, int m, int n, vector<vector<bool>> &visited, vector<vector<int>> &heights)
    {
        if (visited[row][col])
            return;
        visited[row][col] = true;

        // go up
        if (row > 0 and heights[row][col] <= heights[row - 1][col])
            visit_dfs(row - 1, col, m, n, visited, heights);
        // go down
        if (row < m - 1 and heights[row][col] <= heights[row + 1][col])
            visit_dfs(row + 1, col, m, n, visited, heights);
        // go left
        if (col > 0 and heights[row][col] <= heights[row][col - 1])
            visit_dfs(row, col - 1, m, n, visited, heights);
        // go right
        if (col < n - 1 and heights[row][col] <= heights[row][col + 1])
            visit_dfs(row, col + 1, m, n, visited, heights);
    }

    vector<vector<int>> pacific_atlantic(vector<vector<int>> &heights)
    {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> areach(m, vector<bool>(n, false)), preach(m, vector<bool>(n, false));

        for (int row = 0; row < m; row++)
        {
            visit_dfs(row, 0, m, n, preach, heights);
            visit_dfs(row, n - 1, m, n, areach, heights);
        }
        for (int col = 0; col < n; col++)
        {
            visit_dfs(0, col, m, n, preach, heights);
            visit_dfs(m - 1, col, m, n, areach, heights);
        }
        vector<vector<int>> ans;
        for (int row = 0; row < m; row++)
            for (int col = 0; col < n; col++)
                if (areach[row][col] and preach[row][col])
                    ans.push_back({row, col});

        return ans;
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        return pacific_atlantic(heights);
    }
};
// @lc code=end
