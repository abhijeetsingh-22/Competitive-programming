/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
    static void dfs(TreeNode *root, TreeNode *p, TreeNode *q, vector<TreeNode *> &cur_path, vector<TreeNode *> &pathP, vector<TreeNode *> &pathQ)
    {
        if (root == nullptr)
            return;
        cur_path.push_back(root);
        if (root == p)
        {
            for (auto x : cur_path)
            {
                pathP.push_back(x);
            }
        }
        if (root == q)
        {
            for (auto x : cur_path)
            {
                pathQ.push_back(x);
            }
        }
        dfs(root->left, p, q, cur_path, pathP, pathQ);
        dfs(root->right, p, q, cur_path, pathP, pathQ);

        cur_path.pop_back();
    }

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        vector<TreeNode *> cur_path, pathQ, pathP;
        dfs(root, p, q, cur_path, pathP, pathQ);
        int i = 0;
        int len = min(pathQ.size(), pathP.size());
        while (i < len and pathP[i] == pathQ[i])
        {
            i++;
        }

        return pathQ[i - 1];
    }
};
// @lc code=end
