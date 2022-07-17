/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
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
    static vector<vector<int>> bottom_up_iter(TreeNode *root)
    {
        if (root == NULL)
            return {};
        queue<TreeNode *> q;
        stack<TreeNode *> stk;
        vector<vector<int>> ans;
        q.push(root);
        while (!q.empty())
        {
            int s = q.size();
            for (int i = 0; i < s; i++)
            {
                TreeNode *temp = q.front();
                stk.push(temp);
                if (temp->right)
                    q.push(temp->right);
                if (temp->left)
                    q.push(temp->left);
                q.pop();
            }
            stk.push(NULL);
        }
        // remove extra null value from the top
        stk.pop();
        while (!stk.empty())
        {
            vector<int> row;

            while (!stk.empty() and stk.top() != NULL)
            {

                row.push_back(stk.top()->val);
                stk.pop();
            }
            ans.push_back(row);

            if (!stk.empty())
                stk.pop();
        }
        return ans;
    }

public:
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> ans = bottom_up_iter(root);
        return ans;
    }
};
// @lc code=end
