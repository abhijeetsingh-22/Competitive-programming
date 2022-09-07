/*
 * @lc app=leetcode id=606 lang=cpp
 *
 * [606] Construct String from Binary Tree
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
    void dfs_build(TreeNode *root, string &ans)
    {
        if (root == nullptr)
            return;
        ans += to_string(root->val);
        if (root->left or root->right)
        {
            if (root->left)
            {
                ans += "(";
                dfs_build(root->left, ans);
                ans += ")";
            }
            else
            {
                ans += "()";
            }
            if (root->right)
            {
                ans += "(";
                dfs_build(root->right, ans);
                ans += ")";
            }
        }
    }

public:
    string tree2str(TreeNode *root)
    {
        string ans;
        dfs_build(root, ans);
        return ans;
    }
};
// @lc code=end
