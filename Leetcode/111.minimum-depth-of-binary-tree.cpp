/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
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
    int minDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        if (root->left == NULL and root->right == NULL)
            return 1;

        int ld = minDepth(root->left);
        int rd = minDepth(root->right);

        return 1 + (min(ld, rd) ? min(ld, rd) : max(ld, rd));
        // if (ld == 0 and rd == 0)
        //     return 0;
        // if (rd == 0)
        //     return ld + 1;
        // if (ld == 0)
        //     return rd + 1;
        // return min(ld, rd) + 1;
    }
};
// @lc code=end
