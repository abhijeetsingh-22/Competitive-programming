/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
    static int height(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int l_height = height(root->left);
        int r_height = height(root->right);
        return max(l_height, r_height) + 1;
    }
    static void print_klevel(TreeNode *root, vector<int> &row, int k)
    {
        if (root == NULL)
            return;
        if (k == 1)
        {
            row.push_back(root->val);
            return;
        }
        print_klevel(root->left, row, k - 1);
        print_klevel(root->right, row, k - 1);
    }
    static void levelorder_rec(TreeNode *root, vector<vector<int>> &ans)
    {
        if (root == NULL)
            return;
        int h = height(root);
        for (int i = 1; i <= h; i++)
        {
            vector<int> row;
            print_klevel(root, row, i);
            ans.push_back(row);
        }
    }
    static void levelorder_iter(TreeNode *root, vector<vector<int>> &ans)
    {
        if (root == NULL)
            return;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        vector<int> row;
        while (!q.empty())
        {
            TreeNode *f = q.front();
            if (f)
            {
                row.push_back(f->val);
                if (f->left)
                    q.push(f->left);
                if (f->right)
                    q.push(f->right);
                q.pop();
            }
            else if (f == NULL)
            {
                ans.push_back(row);
                row.clear();
                q.pop();
                if (!q.empty())
                    q.push(NULL);
            }
        }
    }

public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        // levelorder_rec(root, ans);
        levelorder_iter(root, ans);
        return ans;
    }
};
// @lc code=end
