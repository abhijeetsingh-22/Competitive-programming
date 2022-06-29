/*
 * @lc app=leetcode id=1823 lang=cpp
 *
 * [1823] Find the Winner of the Circular Game
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    // Recursive solutino TC-> O(n) SC->O(n)
    static int solve_rec(int n, int k)
    {
        if (n == 1)
            return 0;
        return (solve_rec(n - 1, k) + k) % n;
    }
    static int solve_iterative(int n, int k)
    {
        int ans = 0;
        for (int i = 2; i <= n; i++)
        {
            ans = (ans + k) % i;
        }
        return ans;
    }

public:
    int findTheWinner(int n, int k)
    {
        // return solve_rec(n, k) + 1;
        return solve_iterative(n, k) + 1;
    }
};
// @lc code=end
