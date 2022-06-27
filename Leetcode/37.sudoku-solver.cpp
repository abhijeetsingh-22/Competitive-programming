/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    static bool can_place(vector<vector<char>> &board, int i, int j, int num)
    {
        char val = '0' + num;
        for (int x = 0; x < 9; x++)
        {
            if (board[i][x] == val || board[x][j] == val)
                return false;
        }
        int sx = (i / 3) * 3;
        int sy = (j / 3) * 3;
        for (int x = sx; x < sx + 3; x++)
        {
            for (int y = sy; y < sy + 3; y++)
            {
                if (board[x][y] == val)
                    return false;
            }
        }
        return true;
    }
    static bool solve_sudoku(vector<vector<char>> &board, int i, int j)
    {
        // base case
        if (i == 9)
        {
            return true;
        }
        if (j == 9)
            return solve_sudoku(board, i + 1, 0);

        // recursive case

        // skip cell if already value is present
        if (board[i][j] != '.')
            return solve_sudoku(board, i, j + 1);

        // try each value from 1-9 for each empty cell
        for (int k = 1; k <= 9; k++)
        {
            if (can_place(board, i, j, k))
            {
                board[i][j] = '0' + k;
                bool can_solve = solve_sudoku(board, i, j + 1);
                if (can_solve)
                    return true;
            }
        }
        // backtracking step
        // if unable to solve for any value 1-9
        // means some previous set value is wrong
        board[i][j] = '.';
        return false;
    }

public:
    void solveSudoku(vector<vector<char>> &board)
    {
        solve_sudoku(board, 0, 0);
    }
};
// @lc code=end
