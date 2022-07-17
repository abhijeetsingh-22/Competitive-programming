/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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
    static pair<bool, int> check_balance(TreeNode *root)
    {
        // rec case
        if (root == NULL)
        {
            return {true, 0};
        }
        auto left = check_balance(root->left);
        auto right = check_balance(root->right);

        int height = max(left.second, right.second) + 1;
        int is_balanced = abs(left.second - right.second) <= 1 and left.first and right.first;
        return {is_balanced, height};
    }

public:
    bool isBalanced(TreeNode *root)
    {
        return check_balance(root).first;
    }
};
// @lc code=end
