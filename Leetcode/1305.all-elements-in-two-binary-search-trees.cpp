/*
 * @lc app=leetcode id=1305 lang=cpp
 *
 * [1305] All Elements in Two Binary Search Trees
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
    static void dfs(TreeNode *root, vector<int> &v)
    {
        if (root == NULL)
            return;
        dfs(root->left, v);
        v.push_back(root->val);
        dfs(root->right, v);
    }
    static void merge(vector<int> &v1, vector<int> &v2, vector<int> &ans)
    {
        int idx1 = 0, idx2 = 0;
        int s1 = v1.size();
        int s2 = v2.size();
        while (idx1 < s1 and idx2 < s2)
        {
            if (v1[idx1] < v2[idx2])
            {
                ans.push_back(v1[idx1++]);
            }
            else
                ans.push_back(v2[idx2++]);
        }
        while (idx1 < s1)
            ans.push_back(v1[idx1++]);
        while (idx2 < s2)
            ans.push_back(v2[idx2++]);
    }

public:
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {
        vector<int> v1, v2, ans;
        dfs(root1, v1);
        dfs(root2, v2);
        merge(v1, v2, ans);
        return ans;
    }
};
// @lc code=end
