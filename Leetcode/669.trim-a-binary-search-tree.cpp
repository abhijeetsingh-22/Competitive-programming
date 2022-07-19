/*
 * @lc app=leetcode id=669 lang=cpp
 *
 * [669] Trim a Binary Search Tree
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
    static TreeNode *dfs_delete_range(TreeNode *root, int low, int high)
    {
        if (root == NULL)
            return NULL;
        if (root->val < low)
            return dfs_delete_range(root->right, low, high);
        if (root->val > high)
            return dfs_delete_range(root->left, low, high);
        root->left = dfs_delete_range(root->left, low, high);
        root->right = dfs_delete_range(root->right, low, high);
        return root;
    }

public:
    TreeNode *trimBST(TreeNode *root, int low, int high)
    {
        return dfs_delete_range(root, low, high);
    }
};
// @lc code=end
