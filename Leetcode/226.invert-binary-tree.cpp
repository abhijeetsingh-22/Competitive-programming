/*
 * @lc app=leetcode id=226 lang=cpp
 *
 * [226] Invert Binary Tree
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
    static void invert_rec(TreeNode *root)
    {
        if (root == NULL)
            return;

        invert_rec(root->left);
        invert_rec(root->right);

        TreeNode *temp;
        temp = root->left;

        root->left = root->right;
        root->right = temp;
    }

public:
    TreeNode *invertTree(TreeNode *root)
    {
        invert_rec(root);
        return root;
    }
};
// @lc code=end
