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
    static int tilt_iter(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int tsum = 0;
        stack<TreeNode *> stk;
        // sum, tsum
        unordered_map<TreeNode *, int> sum;
        stk.push(root);

        while (!stk.empty())
        {
            TreeNode *top = stk.top();
            if (top->left and sum.find(top->left) == sum.end())
            {
                stk.push(top->left);
            }
            else if (top->right and sum.find(top->right) == sum.end())
            {
                stk.push(top->right);
            }
            else
            {
                stk.pop();
                int l = sum[top->left];
                int r = sum[top->right];
                int t = abs(l - r);
                int s = l + r + top->val;
                sum[top] = s;
                tsum += t;
            }
        }
        return tsum;
    }

public:
    int findTilt(TreeNode *root)
    {
        // return tilt_rec(root).second;
        return tilt_iter(root);
    }
};
// @lc code=end
