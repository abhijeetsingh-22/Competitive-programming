/*
 * @lc app=leetcode id=1329 lang=cpp
 *
 * [1329] Sort the Matrix Diagonally
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> diagonalSort(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();

        for (int col = 0; col < n; col++)
        {
            vector<int> diagonal;
            int i = 0, j = col;
            while (i < m and j < n)
            {
                diagonal.push_back(mat[i][j]);
                i++;
                j++;
            }
            sort(diagonal.begin(), diagonal.end());
            i = 0;
            j = col;
            while (i < m and j < n)
            {
                mat[i][j] = diagonal[i];
                i++;
                j++;
            }
        }
        for (int row = 1; row < m; row++)
        {
            vector<int> diagonal;
            int i = row, j = 0;
            while (i < m and j < n)
            {
                diagonal.push_back(mat[i][j]);
                j++;
                i++;
            }
            sort(diagonal.begin(), diagonal.end());
            i = row;
            j = 0;
            while (i < m and j < n)
            {
                mat[i][j] = diagonal[j];
                i++;
                j++;
            }
        }
        return mat;
    }
};
// @lc code=end
