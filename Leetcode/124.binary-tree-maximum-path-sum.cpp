/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
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
class sum_pair
{
public:
    int max_branch;
    int max_path;
};
class Solution
{
private:
    static sum_pair dfs_max_path(TreeNode *root)
    {
        sum_pair p;
        if (root == nullptr)
        {
            p.max_branch = INT_MIN;
            p.max_path = INT_MIN;
            return p;
        }
        sum_pair left = dfs_max_path(root->left);
        sum_pair right = dfs_max_path(root->right);

        p.max_branch = max({left.max_branch, right.max_branch, 0}) + root->val;

        int max_root_path = (left.max_branch > 0 ? left.max_branch : 0) + (right.max_branch > 0 ? right.max_branch : 0) + root->val;
        p.max_path = max({max_root_path, left.max_path, right.max_path});
        return p;
    }

public:
    int maxPathSum(TreeNode *root)
    {
        return dfs_max_path(root).max_path;
    }
};
// @lc code=end
