/*
 * @lc app=leetcode id=563 lang=cpp
 *
 * [563] Binary Tree Tilt
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
    // returns the sum,tsum of the tree and updates the values on the go
    static pair<int, int> tilt_rec(TreeNode *root)
    {
        if (root == NULL)
            return {0, 0};
        pair<int, int> l = tilt_rec(root->left);
        pair<int, int> r = tilt_rec(root->right);

        int sum = l.first + r.first + root->val;
        int tsum = abs(l.first - r.first) + l.second + r.second;
        return {sum, tsum};
    }

public:
    int findTilt(TreeNode *root)
    {
        return tilt_rec(root).second;
    }
};
// @lc code=end
