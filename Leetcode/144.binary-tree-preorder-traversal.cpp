/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
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
    // Preorder traversal using morris method with O(1) spcace complexity
    static void preorder_morris(TreeNode *root, vector<int> &ans)
    {
        TreeNode *cur = root;
        while (cur != NULL)
        {
            if (cur->left)
            {
                TreeNode *prev = cur->left;
                while (prev->right != NULL and prev->right != cur)
                {
                    prev = prev->right;
                }
                // cur is not yet printed
                if (prev->right == NULL)
                {
                    prev->right = cur;
                    ans.push_back(cur->val);
                    cur = cur->left;
                }
                // cur is already printed and came for the 2nd time
                if (prev->right == cur)
                {
                    prev->right = NULL;
                    cur = cur->right;
                }
            }
            else
            {
                ans.push_back(cur->val);
                cur = cur->right;
            }
        }
    }
    static void preorder_rec(TreeNode *root, vector<int> &ans)
    {
        if (root == NULL)
            return;
        ans.push_back(root->val);
        preorder_rec(root->left, ans);
        preorder_rec(root->right, ans);
    }

    static void preorder_iter(TreeNode *root, vector<int> &ans)
    {
        if (root == NULL)
            return;
        stack<TreeNode *> stk;
        stk.push(root);
        while (!stk.empty())
        {
            auto top = stk.top();
            stk.pop();
            ans.push_back(top->val);
            if (top->right)
                stk.push(top->right);
            if (top->left)
                stk.push(top->left);
        }
    }

public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        preorder_morris(root, ans);
        // preorder_rec(root, ans);
        // preorder_iter(root, ans);

        return ans;
    }
};
// @lc code=end
