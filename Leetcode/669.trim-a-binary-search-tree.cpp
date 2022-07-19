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
    static TreeNode *dfs_trim_bst(TreeNode *root, int low, int high)
    {
        if (root == NULL)
            return NULL;
        if (root->val < low)
            return dfs_trim_bst(root->right, low, high);
        if (root->val > high)
            return dfs_trim_bst(root->left, low, high);
        root->left = dfs_trim_bst(root->left, low, high);
        root->right = dfs_trim_bst(root->right, low, high);
        return root;
    }
    static TreeNode *trim_bst_iter(TreeNode *root, int low, int high)
    {
        if (root == NULL)
            return NULL;
        // find the root of the new tree
        // or the first node that lies in the range
        while (root != NULL and !(root->val >= low and root->val <= high))
        {
            if (root->val < low)
                root = root->right;
            else
                root = root->left;
        }
        TreeNode *cur = root;
        // trim the left subtree of the root
        // if element is greater than the low discard the left of that element
        // and move to right
        while (cur != NULL)
        {
            if (cur->left and cur->left->val < low)
            {
                cur->left = cur->left->right;
            }
            else
            {
                cur = cur->left;
            }
        }
        cur = root;
        // Similarly trim the right subtree of the root;
        while (cur != NULL)
        {
            if (cur->right and cur->right->val > high)
            {
                cur->right = cur->right->left;
            }
            else
            {
                cur = cur->right;
            }
        }
        return root;
    }

public:
    TreeNode *trimBST(TreeNode *root, int low, int high)
    {
        // return dfs_trim_bst(root, low, high);
        return trim_bst_iter(root, low, high);
    }
};
// @lc code=end
