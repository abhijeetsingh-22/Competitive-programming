/*
 * @lc app=leetcode id=700 lang=cpp
 *
 * [700] Search in a Binary Search Tree
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
    static TreeNode *find_DFS(TreeNode *root, int val)
    {
        if (root == NULL)
            return NULL;
        if (root->val == val)
            return root;
        else if (val < root->val)
            return find_DFS(root->left, val);
        else
            return find_DFS(root->right, val);
    }
    static TreeNode *find_iter(TreeNode *root, int val)
    {
        if (root == NULL)
            return NULL;
        TreeNode *cur = root;
        while (cur != NULL)
        {
            if (val == cur->val)
                return cur;
            if (val < cur->val)
                cur = cur->left;
            else if (val > cur->val)
                cur = cur->right;
        }
        return cur;
    }

public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        // return find_DFS(root, val);
        return find_iter(root, val);
    }
};
// @lc code=end
