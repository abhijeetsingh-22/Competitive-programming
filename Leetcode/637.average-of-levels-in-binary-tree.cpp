/*
 * @lc app=leetcode id=637 lang=cpp
 *
 * [637] Average of Levels in Binary Tree
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
    vector<double> avg_of_level(TreeNode *root)
    {
        queue<TreeNode *> q;
        vector<double> ans;

        q.push(root);
        q.push(nullptr);
        double n = 0;
        double cur_sum = 0;
        while (!q.empty())
        {
            TreeNode *cur = q.front();
            q.pop();
            if (cur)
            {
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);

                cur_sum += cur->val;
                n++;
            }
            else
            {
                ans.push_back(cur_sum / n);
                n = 0;
                cur_sum = 0;
                if (!q.empty())
                    q.push(nullptr);
            }
        }
        return ans;
    }

public:
    vector<double> averageOfLevels(TreeNode *root)
    {
        return avg_of_level(root);
    }
};
// @lc code=end
