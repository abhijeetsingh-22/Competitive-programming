/*
 * @lc app=leetcode id=2326 lang=cpp
 *
 * [2326] Spiral Matrix IV
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode *head)
    {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        int sr = 0;
        int er = m - 1;
        int sc = 0;
        int ec = n - 1;
        while (sr <= er and sc <= ec and head != NULL)
        {
            for (int i = sc; i <= ec and head != NULL; i++)
            {
                ans[sr][i] = head->val;
                head = head->next;
            }
            sr++;

            for (int i = sr; i <= er and head != NULL; i++)
            {
                ans[i][ec] = head->val;
                head = head->next;
            }
            ec--;
            for (int i = ec; i >= sc and head != NULL; i--)
            {
                ans[er][i] = head->val;
                head = head->next;
            }
            er--;
            for (int i = er; i >= sr and head != NULL; i--)
            {
                ans[i][sc] = head->val;
                head = head->next;
            }
            sc++;
        }
        return ans;
    }
};
// @lc code=end
