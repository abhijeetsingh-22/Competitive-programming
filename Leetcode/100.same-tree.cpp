/*
 * @lc app=leetcode id=100 lang=cpp
 *
 * [100] Same Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
private:
    static bool is_same_rec(TreeNode *p, TreeNode *q)
    {
        if (p == NULL and q == NULL)
            return true;
        if ((p == NULL and q != NULL) or (p != NULL and q == NULL) or (p->val != q->val))
            return false;
        return is_same_rec(p->left, q->left) and is_same_rec(p->right, q->right);
    }

public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        return is_same_rec(p, q);
    }
};
// @lc code=end
