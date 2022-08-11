/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
    bool is_valid_bst(TreeNode *root, long long lb, long long ub)
    {
        if (root == nullptr)
            return true;

        if (root->val <= lb or root->val >= ub)
            return false;

        return is_valid_bst(root->left, lb, root->val) and is_valid_bst(root->right, root->val, ub);
    }

public:
    bool isValidBST(TreeNode *root)
    {
        long long lb = INT_MIN;
        lb--;
        long long ub = INT_MAX;
        ub++;
        return is_valid_bst(root, lb, ub);
    }
};
// @lc code=end
