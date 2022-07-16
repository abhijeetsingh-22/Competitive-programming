/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
    /*
    This is TC->O(n) and SC->O(n)
    */
    // private:
    //     static void inorder_traversal(TreeNode *root, vector<int> &ans)
    //     {
    //         if (root == NULL)
    //             return;
    //         inorder_traversal(root->left, ans);
    //         ans.push_back(root->val);
    //         inorder_traversal(root->right, ans);
    //     }

    // public:
    //     vector<int> inorderTraversal(TreeNode *root)
    //     {
    //         vector<int> ans;
    //         inorder_traversal(root, ans);
    //         return ans;
    //     }

    // Using morris traversal which uses O(1) space;

public:
    vector<int> inorderTraversal(TreeNode *root)
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
                    prev->right = cur;
                    cur = cur->left;
                }
                if (prev->right == cur)
                {
                    prev->right = NULL;
                    ans.push_back(cur->val);
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
