/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
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
    static bool dfs_path_sum(TreeNode *root, int targetSum, int cur_sum)
    {
        if (root == NULL)
            return false;
        cur_sum += root->val;
        if (root->left == NULL and root->right == NULL)
        {
            if (cur_sum == targetSum)
                return true;
            else
                return false;
        }
        return dfs_path_sum(root->left, targetSum, cur_sum) or dfs_path_sum(root->right, targetSum, cur_sum);
    }
    static bool dfs_path_sum_rec(TreeNode *root, int targetSum)
    {
        if (root == NULL)
            return false;

        stack<pair<TreeNode *, int>> stk;
        stk.push({root, root->val});
        while (!stk.empty())
        {
            auto top = stk.top();
            stk.pop();
            if (top.first->left == NULL and top.first->right == NULL)
            {
                if (top.second == targetSum)
                    return true;
            }
            else
            {
                if (top.first->left)
                    stk.push({top.first->left, top.second + top.first->left->val});

                if (top.first->right)
                    stk.push({top.first->right, top.second + top.first->right->val});
            }
        }
        return false;
    }

public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        // return dfs_path_sum(root, targetSum, 0);
        return dfs_path_sum_rec(root, targetSum);
    }
};
// @lc code=end
