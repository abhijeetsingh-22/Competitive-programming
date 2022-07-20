/*
 * @lc app=leetcode id=437 lang=cpp
 *
 * [437] Path Sum III
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
    static void dfs(TreeNode *root, int target_sum, vector<TreeNode *> &path, int &ans, set<pair<TreeNode *, TreeNode *>> &set)
    {
        if (root == nullptr)
            return;
        if (root->left == nullptr and root->right == nullptr)
        {
            path.push_back(root);
            int n = path.size();
            for (int i = 0; i < n; i++)
            {
                long long cur_sum = 0;
                for (int j = i; j < n; j++)
                {
                    cur_sum += path[j]->val;
                    if (cur_sum == target_sum)
                    {
                        if (set.count({path[i], path[j]}) == 0)
                        {
                            ans++;
                            set.insert({path[i], path[j]});
                        }
                    }
                }
            }
            path.pop_back();
            return;
        }
        path.push_back(root);
        dfs(root->left, target_sum, path, ans, set);
        dfs(root->right, target_sum, path, ans, set);
        path.pop_back();
    }

public:
    int pathSum(TreeNode *root, int targetSum)
    {
        int ans = 0;
        vector<TreeNode *> path;
        set<pair<TreeNode *, TreeNode *>> set;

        dfs(root, targetSum, path, ans, set);
        return ans;
    }
};
// @lc code=end
