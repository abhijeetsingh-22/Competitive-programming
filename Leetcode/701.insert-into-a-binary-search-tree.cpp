/*
 * @lc app=leetcode id=701 lang=cpp
 *
 * [701] Insert into a Binary Search Tree
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
    static TreeNode *bst_insert(TreeNode *root, int val)
    {
        if (root == NULL)
            return new TreeNode(val);
        if (root->val > val)
        {
            root->left = bst_insert(root->left, val);
            return root;
        }
        root->right = bst_insert(root->right, val);
        return root;
    }

public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        return bst_insert(root, val);
    }
};
// @lc code=end
