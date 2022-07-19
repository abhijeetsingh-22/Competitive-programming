/*
 * @lc app=leetcode id=938 lang=cpp
 *
 * [938] Range Sum of BST
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
    static int range_sum_rec(TreeNode *root, int low, int high)
    {
        if (root == NULL)
            return 0;
        int val = root->val;
        if (val < low)
        {
            return range_sum_rec(root->right, max(low, val), high);
        }
        else if (val > high)
        {
            return range_sum_rec(root->left, low, min(val, high));
        }
        return range_sum_rec(root->left, low, high) + val + range_sum_rec(root->right, low, high);
    }

public:
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        return range_sum_rec(root, low, high);
    }
};
// @lc code=end
