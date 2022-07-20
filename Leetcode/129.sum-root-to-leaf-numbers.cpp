/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
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
    static void dfs(TreeNode *root, int num, int &ans)
    {
        if (root == NULL)
            return;
        num += (root->val);
        if (!root->left and !root->right)
        {
            ans += num;
            return;
        }

        dfs(root->left, num * 10, ans);
        dfs(root->right, num * 10, ans);
    }

public:
    int sumNumbers(TreeNode *root)
    {
        int ans = 0;
        dfs(root, 0, ans);
        return ans;
    }
};
// @lc code=end
