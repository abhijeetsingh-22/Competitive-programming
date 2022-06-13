/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

// @lc code=start
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size();
        for (int c = 0; c < m; c++)
            for (int r = 0; r < n / 2; r++)
            {
                swap(matrix[r][c], matrix[n - r - 1][c]);
            }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                if (j > i)
                    swap(matrix[i][j], matrix[j][i]);
            }
    }
};
// @lc code=end
