/*
 * @lc app=leetcode id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
    TreeNode *lca(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr)
            return nullptr;
        if (root == p or root == q)
            return root;
        TreeNode *left = lca(root->left, p, q);
        TreeNode *right = lca(root->right, p, q);

        if (left and right)
            return root;

        return left ? left : right;
    }

    TreeNode *lca_opt(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr)
            return nullptr;
        if (root->val >= p->val and root->val <= q->val)
            return root;
        if (root->val > q->val)
            return lca_opt(root->left, p, q);
        return lca_opt(root->right, p, q);
    }

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {

        // return lca(root, p, q);
        if (p->val <= q->val)
            return lca_opt(root, p, q);

        return lca_opt(root, q, p);
    }
};
// @lc code=end
