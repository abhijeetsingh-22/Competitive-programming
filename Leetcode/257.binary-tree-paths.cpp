/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
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
    // build the answer top down
    static void dfs_path(TreeNode *root, string cur_path, vector<string> &path)
    {
        if (root->left == NULL and root->right == NULL)
        {
            path.push_back(cur_path + to_string(root->val));
            return;
        }
        string p = cur_path + to_string(root->val) + "->";
        if (root->left)
            dfs_path(root->left, p, path);
        if (root->right)
            dfs_path(root->right, p, path);
    }

public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> ans;
        dfs_path(root, "", ans);
        return ans;
    }
};
// @lc code=end
