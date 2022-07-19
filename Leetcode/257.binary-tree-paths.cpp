/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
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
    // build the answer top down
    static void dfs_path(TreeNode *root, string cur_path, vector<string> &path)
    {
        if (root->left == NULL and root->right == NULL)
        {
            path.push_back(cur_path + to_string(root->val));
            return;
        }
        string p = cur_path + to_string(root->val) + "->";
        if (root->left)
            dfs_path(root->left, p, path);
        if (root->right)
            dfs_path(root->right, p, path);
    }
    static vector<string> dfs_rec(TreeNode *root)
    {
        vector<string> ans;

        stack<pair<TreeNode *, string>> stk;
        stk.push(make_pair(root, to_string(root->val)));
        while (!stk.empty())
        {
            auto cur = stk.top();
            stk.pop();
            if (cur.first->left == NULL and cur.first->right == NULL)
                ans.push_back(cur.second);
            if (cur.first->right)
            {
                stk.push(make_pair(cur.first->right, cur.second + "->" + to_string(cur.first->right->val)));
            }
            if (cur.first->left)
            {
                stk.push(make_pair(cur.first->left, cur.second + "->" + to_string(cur.first->left->val)));
            }
        }
        return ans;
    }

public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        // vector<string> ans;
        // dfs_path(root, "", ans);
        // return ans;
        return dfs_rec(root);
    }
};
// @lc code=end
