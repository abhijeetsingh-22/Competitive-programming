/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
    bool mirror_image(TreeNode *p, TreeNode *q)
    {
        // base case
        if (p == NULL || q == NULL)
            return p == q;

        // recursive case
        return p->val == q->val and mirror_image(p->left, q->right) and mirror_image(p->right, q->left);
    }
    bool mirror_image_iter(TreeNode *root)
    {
        stack<TreeNode *> stk;
        stk.push(root->left);
        stk.push(root->right);
        while (!stk.empty())
        {
            TreeNode *p = stk.top();
            stk.pop();
            TreeNode *q = stk.top();
            stk.pop();
            if (p == NULL or q == NULL)
            {
                if (p != q)
                    return false;
            }
            else
            {
                if (p->val != q->val)
                    return false;

                stk.push(p->left);
                stk.push(q->right);
                stk.push(p->right);
                stk.push(q->left);
            }
        }
        return true;
    }

public:
    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
            return true;
        // return mirror_image(root->left, root->right);
        return mirror_image_iter(root);
    }
};
// @lc code=end
