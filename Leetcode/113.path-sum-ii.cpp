/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
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
    static void dfs_path(TreeNode *root, int targetSum, int cur_sum, vector<int> cur_path, vector<vector<int>> &ans)
    {
        if (root == NULL)
            return;
        cur_sum += root->val;
        cur_path.push_back(root->val);
        if (root->left == NULL and root->right == NULL)
        {
            if (cur_sum == targetSum)
                ans.push_back(cur_path);
            return;
        }
        dfs_path(root->left, targetSum, cur_sum, cur_path, ans);
        dfs_path(root->right, targetSum, cur_sum, cur_path, ans);
    }

public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector<int>> ans;
        dfs_path(root, targetSum, 0, {}, ans);
        return ans;
    }
};
// @lc code=end
