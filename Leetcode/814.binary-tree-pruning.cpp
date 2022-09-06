/*
 * @lc app=leetcode id=814 lang=cpp
 *
 * [814] Binary Tree Pruning
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
class Solution {
    TreeNode* get_pruned_tree(TreeNode* root) {
        if (root == nullptr)
            return nullptr;
        root->left = get_pruned_tree(root->left);
        root->right = get_pruned_tree(root->right);

        if (root->val == 1 or (root->left or root->right))
            return root;

        return nullptr;

    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        return get_pruned_tree(root);

    }
};
// @lc code=end

