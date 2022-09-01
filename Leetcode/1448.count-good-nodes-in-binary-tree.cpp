/*
 * @lc app=leetcode id=1448 lang=cpp
 *
 * [1448] Count Good Nodes in Binary Tree
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
    void dfs(TreeNode *root, int maxi, int &ans)
    {
        if (root == nullptr)
            return;
        if (maxi <= root->val)
        {
            ans++;
            maxi = root->val;
        }

        // visit left
        dfs(root->left, maxi, ans);
        // visti right
        dfs(root->right, maxi, ans);
    }

public:
    int goodNodes(TreeNode *root)
    {
        int ans = 0;
        int maxi = INT_MIN;

        dfs(root, maxi, ans);
        return ans;
    }
};
// @lc code=end
