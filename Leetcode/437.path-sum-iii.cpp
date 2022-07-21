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
    static int dfs2(TreeNode *root, long long target_sum, long long cur_sum, unordered_map<long long, int> &map)
    {
        if (root == nullptr)
            return 0;
        cur_sum += root->val;
        int count = 0;
        if (cur_sum == target_sum)
        {
            count++;
        }

        if (map[(cur_sum - target_sum)] > 0)
        {
            count += map[cur_sum - target_sum];
        }
        map[cur_sum]++;
        count += dfs2(root->left, target_sum, cur_sum, map) +
                 dfs2(root->right, target_sum, cur_sum, map);
        map[cur_sum]--;

        return count;
    }

public:
    int pathSum(TreeNode *root, int targetSum)
    {
        // int ans = 0;
        // vector<TreeNode *> path;
        // set<pair<TreeNode *, TreeNode *>> set;

        // dfs(root, targetSum, path, ans, set);
        // return ans;
        unordered_map<long long, int> map;
        return dfs2(root, targetSum, 0, map);
    }
};
// @lc code=end
