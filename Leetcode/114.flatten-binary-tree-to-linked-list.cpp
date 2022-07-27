/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
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
    TreeNode *prev;

private:
    void flatten_recursive(TreeNode *root)
    {
        if (root == nullptr)
            return;
        flatten_recursive(root->right);
        flatten_recursive(root->left);
        root->right = prev;
        root->left = nullptr;
        prev = root;
    }
    static void flatten_iter(TreeNode *root)
    {
        if (root == nullptr)
            return;

        stack<TreeNode *> stk;
        stk.push(root);
        while (!stk.empty())
        {
            TreeNode *cur = stk.top();
            stk.pop();
            if (cur->right)
                stk.push(cur->right);
            if (cur->left)
                stk.push(cur->left);
            cur->left = nullptr;
            cur->right = !stk.empty() ? stk.top() : nullptr;
        }
    }
    static void flatten_optimized(TreeNode *root)
    {
        if (root == nullptr)
            return;
        TreeNode *cur = root;
        while (cur != nullptr)
        {
            if (cur->left)
            {
                TreeNode *prev = cur->left;
                while (prev->right != nullptr)
                    prev = prev->right;
                prev->right = cur->right;
                cur->right = cur->left;
                cur->left = nullptr;
                // TreeNode* temp=cur;
                cur = cur->right;
            }
            else
            {
                cur = cur->right;
            }
        }
    }

public:
    void flatten(TreeNode *root)
    {
        // flatten_iter(root);
        prev = nullptr;
        // flatten_optimized(root);
        flatten_recursive(root);
    }
};
// @lc code=end
