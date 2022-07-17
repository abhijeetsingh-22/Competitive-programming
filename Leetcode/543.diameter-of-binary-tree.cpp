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
    // DFS using stack
    static int diameter_iter_DFS(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        unordered_map<TreeNode *, int> height;
        stack<TreeNode *> stk;
        stk.push(root);
        int diameter = 0;
        while (!stk.empty())
        {
            auto top = stk.top();
            // go to extreme left leaf node
            if (top->left and height.find(top->left) == height.end())
            {
                stk.push(top->left);
            }
            else if (top->right and height.find(top->right) == height.end())
            {
                stk.push(top->right);
            }
            else
            {
                stk.pop();
                int l = height[top->left];
                int r = height[top->right];
                height[top] = max(l, r) + 1;
                diameter = max(diameter, l + r);
            }
        }
        return diameter;
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        // return diameter_rec(root).first;
        return diameter_iter_DFS(root);
    }
};
// @lc code=end
