/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
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
public:
    // Preorder traversal using morris method with O(1) spcace complexity
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        TreeNode *cur = root;

        while (cur != NULL)
        {
            if (cur->left)
            {
                TreeNode *prev = cur->left;
                while (prev->right != NULL and prev->right != cur)
                {
                    prev = prev->right;
                }
                if (prev->right == NULL)
                {
                    ans.push_back(cur->val);
                    prev->right = cur;
                    cur = cur->left;
                }
                if (prev->right == cur)
                {
                    prev->right = NULL;
                    cur = cur->right;
                }
            }
            else
            {
                ans.push_back(cur->val);
                cur = cur->right;
            }
        }
        return ans;
    }
};
// @lc code=end
