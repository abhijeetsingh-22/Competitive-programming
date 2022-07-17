/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
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
    static pair<int, int> diameter_rec(TreeNode *root)
    {
        if (root == NULL)
        {
            return {0, 0};
        }
        pair<int, int> left = diameter_rec(root->left);
        pair<int, int> right = diameter_rec(root->right);

        int height = max(left.second, right.second) + 1;
        int diameter = max(left.second + right.second, max(left.first, right.first));
        return {diameter, height};
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        return diameter_rec(root).first;
    }
};
// @lc code=end
